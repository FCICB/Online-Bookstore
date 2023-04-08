#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>
#include <string.h>

using namespace std;

class Book{
public:
    Book();
    Book(string title, string author, string genre, double price, int stockQuantity);
    Book(const Book &book);
    void display();
    void setTitle(string title);
    void setAuthor(string author);
    void setGenre(string genre);
    void setPrice(double price);
    void setStockQuantity(int stockQuantity);
    string getTitle();
    string getAuthor();
    string getGenre();
    double getPrice();
    int getStockQuantity();
    bool operator==(const Book &book) const;
    bool operator>(const Book &book) const;
    bool operator<(const Book &book) const;
private:
    string title;
    string author;
    string genre;
    double price;
    int stockQuantity;
};

#endif 
