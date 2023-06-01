//
// Created by Haris Ali on 5/18/2023.
//

#include "Books.h"
#include "Welcome.cpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <conio.h>

class Library : protected Books {

private:
    vector<Books> books; // Composition
    int bookCount;

    string librarianPassword = "1234";
public:

    Library() {
        bookCount = 0;
    }

    // Getters
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
