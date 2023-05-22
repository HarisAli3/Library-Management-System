//
// Created by Haris Ali on 5/22/2023.
//

#ifndef LIBRARY_PROJECT_OOP_LIBRARY_H
#define LIBRARY_PROJECT_OOP_LIBRARY_H

#include "Books.h"
#include "Student.h"
#include "Welcome.cpp"
#include <cstdlib>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>

class Library {

private:
    string librarianPassword;

protected:
    vector<Books> books;
    int bookCount;
public:
    Library() {
        bookCount = 0;
        librarianPassword = "";
    }

//    void addBook(const Books& book) {
//        books.push_back(book);
//        cout << "\n\t\t\tBook added successfully!";
//    }
//
////    Books* findBookById(int id) {
////        for (auto& book : books) {
////            if (book.book_id == id) {
////                return &book;
////            }
////        }
////        return nullptr;
////    }
//
//    void viewBookList() {
//        cout << "\n\t\t\t***** View Book List *****";
//        cout << "\n\t\t\tBook ID\tBook Name\tAuthor Name\tQuantity";
//        for (const auto& book : books) {
//            cout << "\n\t\t\t" << book.book_id << "\t" << book.book_name << "\t" << book.author_name << "\t" << book.quantity;
//        }
//    }

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

};


#endif //LIBRARY_PROJECT_OOP_LIBRARY_H
