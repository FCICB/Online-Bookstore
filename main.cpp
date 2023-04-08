#include <iostream>
#include <fstream>
#include <string.h>
#include "Book.h"
#include "Inventory.h"
#include "Cart.h"
using namespace std;

Inventory inventory;

void loadInventory(){
    
    string title[10] = {"I Feel Bad About My Neck", "Broken Glass", "The Girl With the Dragon Tatto", "Harry Potter and the Goblet of Fire"
    ,"A Little Life", "Chronicles: Volume One", "Chronicles: Volume One", "The Tripping Point", "Darkmans", "The Seige"};
    
    string author[10] = {"Nora Ephron", "Alain Mabanckou", "Steig Larsson", "JK Rowling", "Hanya Yanagihara", "Bob Dylan", "Bob Dylan",
    "Malcolm Gladwell", "Nicola Barker", "Helen Dunmore"};

    string genre[10] = {"Humor", "Fiction", "Thriller", "Fiction", "Novel", "Biography", "Non-Fiction", "Fiction", "History", "Fiction"};

    double price[10] = {9.74, 9.97, 9.71, 6.92, 9.97, 11.69, 15.69, 14.10, 14.99, 16.90};

    int stockQuantity[10] = {200, 120, 30, 80, 44, 250, 400, 300, 170, 90};
    
    fstream file;
    file.open("Inventory.txt");

    if(!file.is_open()){
        throw runtime_error("Could not Open File");
        cout << endl;
    }
    else{
        
        for(int i = 0;i < 10;i++){
            file << title[i];
            file << ',';
            file << author[i];
            file << ',';
            file << genre[i];
            file << ',';
            file << price[i];
            file << ',';
            file << stockQuantity[i];
            file << '\n';
        }

        file.close();
    }
}

void CartMenu(Cart &cart){
    
    string title;
    string author;
    string genre;
    double price;
    int stockQuantity;
    int choice;
    int exit = 0;

    while(exit == 0){
        
        cout << "*****************************" << endl;
        cout << "1. Add to Cart" << endl;
        cout << "2. Delete from Cart" << endl;
        cout << "3. List Cart Items" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "******************************\n\n";
    
        cout << "Enter Choice: ";
        cin >> choice;
        cout << endl;

        while(cin.fail()){
            cout << "You Should Enter Number between 1 and 4" << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
    
        switch (choice)
        {
        case 1:
            try{
                cout << "Enter Book Information" << "\n\n";
                cout << "Book Title: ";
                cin.ignore();
                getline(cin,title);
                cout << "Book Author: ";
                getline(cin,author);
                cout << "Book Genre: ";
                getline(cin,genre);
                cart.addBookCart(title, author, genre, inventory);
            }
            catch(exception &e){
                cout << e.what() << endl;
            }
            break;
        case 2:
            try{
                cout << "Enter Book Information" << "\n\n";
                cout << "Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Book Author: ";
                getline(cin, author);
                cout << "Book Genre: ";
                getline(cin, genre);
                cart.removeBookCart(title, author, genre);
            }
            catch(exception &e){
                cout << e.what() << endl;
            }
            break;
        case 3:
            cout << "Cart Items" << "\n\n";
            cart.listCartItems();
            break;
        case 4:
            exit = 1;
            break;
        default:
            cout << "You should Input Number between 1 and 4." << endl;
            cout << "Try Again" << "\n\n";           
            break;
        }
    }


}

void displayInventoryMenu(){
    
    string title;
    string author;
    string genre;
    int choice;
    int exit = 0;
    
    while(exit == 0){

        cout << "**************************************" << endl;
        cout << "1. Display All Inventory" << endl;
        cout << "2. Display Inventory by Title" << endl;
        cout << "3. Display Inventory by Author" << endl;
        cout << "4. Display Inventory by Genre" << endl;
        cout << "5. Return to Main Menu" << endl;
        cout << "***************************************\n\n";

        cout << "Enter Choice: ";
        cin >> choice;
        cout << endl;

        while(cin.fail()){
            cout << "You Should Enter Number between 1 and 5" << endl;
            cin.clear();
            cin.ignore();
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "Displaying All Inventory" << "\n\n";
            inventory.displayAllInventory();
            break;
        case 2:
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            inventory.displayInventoryByTitle(title);
            break;
        case 3:
            cout << "Enter Book Author: ";
            cin.ignore();
            getline(cin, author);
            inventory.displayInventoryByAuthor(author);
            break;
        case 4:
            cout << "Enter Book Genre: ";
            cin.ignore();
            getline(cin, genre);
            inventory.displayInventoryByGenre(genre);
            break;
        case 5:
            exit = 1;
            break;
        default:
            cout << "You should Input Number between 1 and 5." << endl;
            cout << "Try Again" << "\n\n";
            break;
        }
    }
}

void InventoryMenu(){

    int inventoryMenuChoice;
    int exit = 0;
    string title;
    string author;
    string genre;
    double price;
    int stockQuantity;

    while(exit == 0){

        cout << "******************************" << endl;
        cout << "1. Add Book to Inventory" << endl;
        cout << "2. Display All Inventory" << endl;
        cout << "3. Edit Book in Inventory" << endl;
        cout << "4. Delete Book in Inventory" << endl;
        cout << "5. Exit Program" << endl;
        cout << "******************************\n\n";

        cout << "Enter Choice: ";               
        cin >> inventoryMenuChoice;
        cout << endl;

        while(cin.fail()){
            cout << "You Should Enter Number between 1 and 5" << endl;
            cin.clear();
            cin.ignore();
            cin >> inventoryMenuChoice;
        }
    
        switch(inventoryMenuChoice){
            case 1: 
                try{
                    cout << "Enter New Book Information: " << endl;
                    cout << "Book Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Book Author: ";
                    getline(cin, author);
                    cout << "Book Genre: ";
                    getline(cin, genre);
                    cout << "Book Price: ";
                    cin >> price;
                    cout << "Book Stock Quantity: ";
                    cin >> stockQuantity;
                    Book book(title, author, genre, price, stockQuantity);
                    inventory.addBook(book);
                }
                catch(exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 2:
                displayInventoryMenu();
                break;
           case 3:{
                cout << "Enter Old Book Information" << "\n\n";
                cout << "Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Book Author: ";
                getline(cin, author);
                cout << "Book Genre: ";
                getline(cin, genre);
                cout << "Book Price: ";
                cin >> price;
                cout << "Book Stock Quantity: ";
                cin >> stockQuantity;
                cout << "\n\n";
                Book oldBook(title, author, genre, price, stockQuantity);

                cout << "Enter New Book Information" << "\n\n";
                cout << "Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Book Author: ";
                getline(cin, author);
                cout << "Book Genre: ";
                getline(cin, genre);
                cout << "Book Price: ";
                cin >> price;
                cout << "Book Stock Quantity: ";
                cin >> stockQuantity;
                cout << "\n\n";
                Book newBook(title, author, genre, price, stockQuantity);

                inventory.editBook(oldBook, newBook);
                break;}
            case 4:
                try{
                    cout << "Enter Deleted Book Information" << endl;
                    cout << "Book Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Book Author: ";
                    getline(cin, author);
                    cout << "Book Genre: ";
                    getline(cin, genre);
                    cout << "Book Price: ";
                    cin >> price;
                    cout << "Book Stock Quantity: ";
                    cin >> stockQuantity;
                    cout << "\n\n";
                    Book deletedBook(title, author, genre, price, stockQuantity);
                    inventory.deleteBook(deletedBook, 0);
                }
                catch(exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 5:
                exit = 1;
                break;
            default:
                cout << "You should Input Number between 1 and 5." << endl;
                cout << "Try Again" << "\n\n";
                break; 
            }
    }
}

int main(){
    
    int mainMenuChoice;
    int modeChoice;
    string title;
    string author;
    string genre;
    double price;
    int stockQuantity;
    int itemsNumber;
    int exit = 0;
    Cart cart;

    try{
        loadInventory();
        inventory.loadInventory();
    }
    catch(exception &e){
        cout << e.what() << endl;
        return 0;
    }

    cout << "********************ONLINE BOOKSTORE**********************" << endl;
    cout << "Please choose a mode" << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << "\n\n";

    cout << "Choice: ";
    cin >> modeChoice;
    cout << endl;

    while(cin.fail()){
        cout << "You Should Enter Number 1 or 2" << endl;
        cin.clear();
        cin.ignore(); 
        cin >> modeChoice;
    }
    
    if(modeChoice == 1){
        InventoryMenu();
    }
    else if(modeChoice == 2){
        while(exit == 0){
        
        cout << "*********************************************" << endl;
        cout << "1. Search For a Book" << endl;
        cout << "2. Add or Delete or List Books from Cart" << endl;
        cout << "3. Checkout Books from Cart" << endl;
        cout << "4. Exit Program" << endl;
        cout << "*********************************************\n\n";

        cout << "Enter Choice: ";
        cin >> mainMenuChoice;
        cout << endl;

        while(cin.fail()){
            cout << "You Should Enter Number between 1 and 4" << endl;
            cin.clear();
            cin.ignore();
            cin >> mainMenuChoice;
        }

        switch(mainMenuChoice){
            case 1:
                try{
                    cout << "Enter Book Information" << "\n\n";
                    cout << "Book Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Book Author: ";
                    getline(cin, author);
                    cout << "Book Genre: ";
                    getline(cin, genre);

                    Book book = inventory.searchBook(title, author, genre);

                    if(book.getTitle().compare("") != 0){
                        cout << endl << "Book Information" << endl;
                        book.display();
                        cout << endl;
                    }
                }
                catch(exception &e){
                    cout << e.what() << endl;
                }
                break;
            case 2:
                CartMenu(cart);
                break;;
            case 3:{
                vector<Book>books;
                cout << "Enter Number of Items to Checkout from Cart: ";
                cin >> itemsNumber;

                for(int i = 0;i < itemsNumber;i++){
                    cout << "Item " << i + 1 << " info :" << "\n\n";
                    cout << "Book Title: ";
                    cin.ignore();
                    getline(cin, title);
                    cout << "Book Author: ";
                    getline(cin, author);
                    cout << "Book Genre: ";
                    getline(cin, genre);
                    cout << "Book Price: ";
                    cin >> price;
                    cout << "Book Stock Quantity: ";
                    cin >> stockQuantity;
                    Book book(title, author, genre, price, stockQuantity);
                    books.push_back(book);
                    cout << "\n\n";
                }

                try{
                    cart.checkOut(books,inventory);
                }
                catch(exception &e){
                    cout << e.what() << endl;
                }
                break;
                }
            case 4:
                cout << "HAVE A NICE DAY, GOODBYE!!!" << "\n\n";
                exit = 1;
                break;
            default:
                cout << "You should Input Number between 1 and 4." << endl;
                cout << "Try Again" << "\n\n";           
                break; 
            }

         }
     }
     else{
        cout << "You Should Enter 1 or 2" << endl;
     }
    return 0;
}