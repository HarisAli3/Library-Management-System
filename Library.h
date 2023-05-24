//
// Created by Haris Ali on 5/22/2023.
//

#ifndef LIBRARY_PROJECT_OOP_LIBRARY_H
#define LIBRARY_PROJECT_OOP_LIBRARY_H

#include "Books.h"
#include "Student.h"
#include "Welcome.cpp"
#include "conio.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>


class Library : public Books{

private:
    string librarianPassword;

protected:
    vector<Books> books;
//    vector<Student> students;
    int bookCount;
public:
    Library() {
        bookCount = 0;
        librarianPassword = "";
    }

    static void MainMenu(Library&);
    static void LibrarianMenu(Library&);
    static void StudentMenu(Library&);
    void addBook();
    void modifyBook();
    void deleteBook();

    static void displayBookDetails(const Books&);

    void viewBookList(int);
    void searchBook();
    void saveBookData();
    void loadBookData();

    void issueBookToStudent();
    void returnBookFromStudent();

    static void viewIssuedBooksHistory();

};


#endif //LIBRARY_PROJECT_OOP_LIBRARY_H
