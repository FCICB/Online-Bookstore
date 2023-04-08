#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include<vector>
#include "Book.h"

class Inventory{
public:
    Inventory();
    void loadInventory();
    void addBook(Book book);
    void editBook(Book book, Book updateBook);
    int deleteBook(Book book, int dummy);
    void displayAllInventory();
    void displayInventoryByTitle(string title);
    void displayInventoryByAuthor(string author);
    void displayInventoryByGenre(string genre);
    Book searchBook(string title, string author, string genre) const;
private:
    vector<Book>book;
};

#endif 