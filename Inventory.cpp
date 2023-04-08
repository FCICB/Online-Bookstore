#include <iostream>
#include<vector>
#include<fstream>
#include <algorithm>
#include "Book.h"
#include "Inventory.h"

using namespace std;

Inventory::Inventory(){

}

void Inventory::loadInventory(){
    
    ifstream file;
    file.open("Inventory.txt", ios::in);
    if(!file.is_open()){
        throw runtime_error("Could not Open File");
        cout << endl;
    }
    else{
        string title;
        string author;
        string genre;
        double price;
        int stockQuantity;
        file.seekg(0);

        while(getline(file, title,',')){
           
           getline(file, author,',');
           getline(file, genre, ',');
           file >> price;
           file.ignore();
           file >> stockQuantity;
           file.ignore();
           Book book(title, author, genre, price, stockQuantity);
           this->book.push_back(book);

        }

        file.close();
        sort(this->book.begin(), this->book.end());
    }

}

void Inventory::addBook(Book book){
   
    ofstream file;
    file.open("Inventory.txt", ios::app);
    
    if(!file.is_open()){
        throw runtime_error("Could not Open File");
        cout << endl;
    }
    else{
        file << book.getTitle();
        file << ',';
        file << book.getAuthor();
        file << ',';
        file << book.getGenre();
        file << ',';
        file << book.getPrice();
        file << ',';
        file << book.getStockQuantity();
        file << '\n';
        this->book.push_back(book);
        file.close();
        cout << "Book Added Successfully" << "\n\n";
    }

}

void Inventory::editBook(Book book, Book updateBook){
    
    try{
        int state = deleteBook(book, 1);
        if(state){
          addBook(updateBook);
        }
    }
    catch(exception &e){
        cout << e.what() << endl;
    }

}

int Inventory::deleteBook(Book delBook, int dummy){
    
    ifstream file;
    ofstream newFile;
    int removed = 0;
    
    file.open("Inventory.txt");
    newFile.open("NewInventory.txt");

    if(file.is_open() && newFile.is_open()){
        
        string title;
        string author;
        string genre;
        double price;
        int stockQuantity;

        while(getline(file, title,',')){
            getline(file, author,',');
            getline(file, genre, ',');
            file >> price;
            file.ignore();
            file >> stockQuantity;
            file.ignore();

           if((title.compare(delBook.getTitle()) != 0)   || (delBook.getAuthor().compare(author) != 0) || (delBook.getGenre().compare(genre) !=0 )){
                newFile << title;
                newFile << ',';
                newFile << author;
                newFile << ',';
                newFile << genre;
                newFile << ',';
                newFile << price;
                newFile << ',';
                newFile << stockQuantity;
                newFile << '\n';
           }
           else{
               removed = 1;
               if(dummy == 1){
                continue;
               }

               if(stockQuantity > 1){
                   newFile << title;
                   newFile << ',';
                   newFile << author;
                   newFile << ',';
                   newFile << genre;
                   newFile << ',';
                   newFile << price;
                   newFile << ',';
                   newFile << (stockQuantity - 1);
                   newFile << '\n';
               }
           } 
        }
     
        file.close();
        newFile.close();

        remove("Inventory.txt");
        rename("NewInventory.txt", "Inventory.txt");
        
        this->book.clear();
        loadInventory();

        if(removed){
            cout << "Book Removed Successfully" << "\n\n";
        }
        else{
            cout << "Book Doesn't Exist" << "\n\n";
        }

        return removed;

    }
    else{
        throw runtime_error("Could not Open File");
        cout << endl;
    }
}

void Inventory::displayAllInventory(){
    
    if(this->book.size() == 0){
        cout << "Inventory is Empty." << endl;
    }

    for(int i = 0;i < this->book.size();i++){
        cout << "Book " << i + 1 << ": " << "\n\n";
        this->book[i].display();
        cout << endl;
    }
    cout << endl;
}

void Inventory::displayInventoryByTitle(string title){

    int counter = 0;
    for(int i = 0;i < this->book.size();i++){

        if(this->book[i].getTitle().compare(title) == 0){
            cout << "Book: " << ++counter << ": " << "\n\n";
            this->book[i].display();
            cout << endl;
        }

    }
    cout << endl;
}

void Inventory::displayInventoryByAuthor(string author){

    int counter = 0;
    
    for(int i = 0;i < this->book.size();i++){

        if(this->book[i].getAuthor().compare(author) == 0){
            cout << "Book " << ++counter << ": " << "\n\n";
            this->book[i].display();
            cout << endl;
        }

    }
    cout << endl;
}

void Inventory::displayInventoryByGenre(string genre){

    int counter = 0;
    
    for(int i = 0;i < this->book.size();i++){

        if(this->book[i].getGenre().compare(genre) == 0){
            cout << "Book " << ++counter << ": " << "\n\n";
            this->book[i].display();
            cout << endl;
        }

    }
    cout << endl;
}

Book Inventory::searchBook(string title, string author, string genre)const{
    
    if(this->book.size() == 0){
        throw runtime_error("Inventory is Empty");
        cout << endl;
    }
    else{
       
        Book book(title, author, genre, 0.0, 0);
        int low = 0 ;
        int high = this->book.size() - 1;

        while(low <= high){

            int mid = (low + high) / 2;
            if(this->book[mid] == book){
                return this->book[mid];
            }
            else if(book > this->book[mid]){
                low = mid + 1;
            }
            else if(book < this->book[mid]){
                high = mid - 1;
            }

        }
        
        cout << "Book Doesn't Exist" << endl;
        Book emptyBook("", "", "", 0.0, 0);
        return emptyBook;

    }
}















