//
// Created by Haris Ali on 5/22/2023.
//

#ifndef LIBRARY_PROJECT_OOP_LIBRARIAN_H
#define LIBRARY_PROJECT_OOP_LIBRARIAN_H

#include "Books.h"
#include "Welcome.cpp"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>

class Librarian {

private:
    string librarianPassword;

protected:
    int bookCount;
    Books books[100];
public:
    Librarian() {
        bookCount = 0;
        librarianPassword = "";
    }

    void addBook();
    void modifyBook();
    void deleteBook();

    void viewBookList(int);
    void searchBook();
    void saveBookData();
    void loadBookData();

};


#endif //LIBRARY_PROJECT_OOP_LIBRARIAN_H
