#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include<vector>
#include "Book.h"

class Cart{
public:
    Cart();
    void addBookCart(string title, string author, string genre, const Inventory &inventory);
    void removeBookCart(string title, string author, string genre);
    void listCartItems();
    int searchBookCart(string title, string author, string genre)const;
    bool checkOut(vector<Book>items, Inventory &inventory);
private:
    vector<Book>book;
};


#endif