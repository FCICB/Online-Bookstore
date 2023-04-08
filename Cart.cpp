#include <iostream>
#include<vector>
#include "Book.h"
#include "Inventory.h"
#include "Cart.h"

using namespace std;

Cart::Cart(){

}

void Cart::addBookCart(string title, string author, string genre, const Inventory &inventory){

    try{
        Book book = inventory.searchBook(title, author, genre);
    
       if(book.getTitle().compare("") != 0){
            this->book.push_back(book);
        }
        else{
            throw runtime_error("Out of Stock");
        }
    }
    catch(exception &e){
        cout << e.what();
    }
}

void Cart::removeBookCart(string title, string author, string genre){

    if(this->book.size() == 0){
        throw runtime_error("Cart is Empty");
    }
    else{
        try{
            int position = searchBookCart(title, author, genre);
            if(position != -1){
                this->book.erase(this->book.begin() + position);
            }
        }
        catch(exception &e){
            cout << e.what();
        } 
    } 

}

void Cart::listCartItems(){
    
    if(this->book.size() == 0){
        cout << "Cart is Empty.";
    }

    for(int i = 0;i < this->book.size();i++){
        
        cout << "Book " << i + 1 << ": " << "\n\n";
        this->book[i].display();
        cout << endl;

    }
    cout << endl;
}

int Cart::searchBookCart(string title, string author, string genre) const{

    if(this->book.size() == 0){
        throw runtime_error("Cart is Empty");
    }

    Book book(title, author, genre, 0.0, 0);
    int low = 0 ;
    int high = this->book.size() - 1;

    while(low <= high){

        int mid = (low + high) / 2;
        if(this->book[mid] == book){
            return mid;
        }
        else if(book > this->book[mid]){
            low = mid + 1;
        }
        else if(book < this->book[mid]){
            high = mid - 1;
        }

    }
        
    return -1;
}

bool Cart::checkOut(vector<Book>items, Inventory &inventory){
    
    int totalPrice = 0;
    for(int i = 0;i < items.size();i++){
        
        int position = searchBookCart(items[i].getTitle(), items[i].getAuthor(), items[i].getGenre());
        if(position == -1){
            throw runtime_error("Book Doesn't Exist");
            cout << endl;
        }
        else{
            totalPrice += items[i].getPrice();
        }

    }
    
    string Name;
    string address;
    string creditCardNumber;
    string creditCardSecurityCode;
    double fund;
    
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, Name);
    cout << "Enter Address Information: ";
    getline(cin, address);
    cout << "Enter Credit Card Number: ";
    getline(cin, creditCardNumber);
    cout << "Enter Credit Card Security Code: ";
    getline(cin, creditCardSecurityCode);
    cout << "Enter Fund: ";
    cin >> fund;
    
    if(fund < totalPrice){
        throw runtime_error("Insufficent Fund");
    }
    else{
        
        for(int i = 0;i < items.size();i++){
            removeBookCart(items[i].getTitle(), items[i].getAuthor(), items[i].getGenre());
            inventory.deleteBook(items[i], 0);
        }

        cout << "Items Checked Out Successfully" << "\n\n";
        cout << "Name: " << Name << endl;
        cout << "Address: " << address << endl;
        cout << "Credit Card Number: " << creditCardNumber << endl;
        cout << "Credit Card Security Code" << creditCardSecurityCode << endl;
        cout << "Fund: " << fund << "\n\n";

    }

}