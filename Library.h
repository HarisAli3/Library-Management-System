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

class Library {

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

    void viewIssuedBooksHistory() {
        headMessage("View Issued History");
        ifstream file("issued_books.txt");
        if (file.is_open()) {


            int id, book;
            time_t issueTime;
            int i = 0;
            while (file >> id >> book >> issueTime) {
                cout << "\n\n\t\t\t\t\t\t********** " << i + 1 << ". ********** \n";
                cout << "\n\n\t\t\tStudent ID: " << id;
                cout << "\n\n\t\t\tBook ID: " << book;
                cout << "\n\n\t\t\tIssue Time: " << ctime(&issueTime);
                cout << "\n\t\t\t";
//                cout << "\t\t\t" << id << "\t\t" << book << "\t\t" << ctime(&issueTime);
            }

            file.close();
            getch();
        } else {
            cout << "\n\t\t\tNo issued history found!" << endl;
            getch();
        }
    }



};


#endif //LIBRARY_PROJECT_OOP_LIBRARY_H
