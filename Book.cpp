#include <iostream>
#include <string.h>
#include "Book.h"

using namespace std;

Book::Book(){
    this->title = "";
    this->author = "";
    this->genre = "";
    this->price = 0.0;
    this->stockQuantity = 0;
}

Book::Book(string title, string author, string genre, double price, int stockQuantity){
    this->title = title;
    this->author = author;
    this->genre = genre;
    this->price = price;
    this->stockQuantity = stockQuantity;
}

Book::Book(const Book &book){
    this->title = book.title;
    this->author = book.author;
    this->genre = book.genre;
    this->price = book.price;
    this->stockQuantity = book.stockQuantity;
}

void Book::display(){
    cout << "Title: " << this->title << endl;
    cout << "Author: " <<this->author << endl;
    cout << "Genre: " << this->genre << endl;
    cout << "Price: " << this->price << endl;
    cout << "Stock Quantity: " << this->stockQuantity << endl;
}

void Book::setTitle(string title){
    this->title = title;
}

void Book::setAuthor(string author){
    this->author = author;
}

void Book::setGenre(string genre){
    this->genre = genre;
}

void Book::setPrice(double price){
    this->price = price;
}

void Book::setStockQuantity(int stockQuantity){
    this->stockQuantity = stockQuantity;
}

string Book::getTitle(){
    return this->title;
}

string Book::getAuthor(){
    return this->author;
}

string Book::getGenre(){
    return this->genre;
}

double Book::getPrice(){
    return this->price;
}

int Book::getStockQuantity(){
    return this->stockQuantity;
}

bool Book::operator==(const Book &book) const{
    
    if((this->title.compare(book.title) == 0) && (this->author.compare(book.author) == 0) && (this->genre.compare(book.genre) == 0)){
        return true;
    }

    return false;
}

bool Book::operator>(const Book &book)const{
    
    if((this->title.compare(book.title) > 0)){
        return true;
    }

    if((this->title.compare(book.title) == 0) && (this->author.compare(book.author) > 0)){
        return true;
    }

    if((this->title.compare(book.title) == 0) && (this->author.compare(book.author) == 0) && (this->genre.compare(book.genre) > 0)){
        return true;
    }

    return false;
}

bool Book::operator<(const Book &book)const{
    
    if((this->title.compare(book.title) < 0)){
        return true;
    }

    if((this->title.compare(book.title) == 0) && (this->author.compare(book.author) < 0)){
        return true;
    }

    if((this->title.compare(book.title) == 0) && (this->title.compare(book.title) == 0) && (this->genre.compare(book.genre) < 0)){
        return true;
    }

    return false;
}










































































