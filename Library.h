//
// Created by Haris Ali on 5/22/2023.
//

#ifndef LIBRARY_PROJECT_OOP_LIBRARY_H
#define LIBRARY_PROJECT_OOP_LIBRARY_H

#include "Books.h"
#include "Welcome.cpp"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>
#include <conio.h>


class Library : public Books {

private:

    vector<Books> books;
    int bookCount;

public:

    Library() {
        bookCount = 0;
    }

    static void MainMenu(Library&);

    static void LibrarianMenu(Library&);
    static void StudentMenu(Library&);

    void addBook();
    void modifyBook();
    void deleteBook();
    void viewBookList(int);
    void searchBook(int);

    static void displayBookDetails(const Books&, int);

    void saveBookData();
    void loadBookData();

    void issueBookToStudent();
    void returnBookFromStudent();

    static void viewIssuedBooksHistory();

};


#endif //LIBRARY_PROJECT_OOP_LIBRARY_H
