//
// Created by Haris Ali on 5/22/2023.
//

#ifndef LIBRARY_PROJECT_OOP_STUDENT_H
#define LIBRARY_PROJECT_OOP_STUDENT_H

#include "Student.cpp"
#include <vector>

class Student {
private:
    string studentName;
    int studentID;
    int issuedBookID;
    time_t issueDate;
//    vector<int> issuedBooks;
public:
    Student() {
        studentName = "";
        studentID = 0;
        issuedBookID = 0;
        issueDate = 0;
    }

    void setStudentName(const string &name) {
        studentName = name;
    }

    void setStudentID(int id) {
        studentID = id;
    }


    void issueBook(int bookID) {
        issuedBookID = bookID;
        time(&issueDate);
        cout << "\n\t\t\tBook issued to student!";
    }

    void returnBook() {
        if (issuedBookID != 0) {
            issuedBookID = 0;
            time_t returnDate;
            time(&returnDate);
            double days = difftime(returnDate, issueDate) / (24 * 60 * 60);
            cout << "\n\t\t\tBook returned by student!";
            cout << "\n\t\t\tNumber of days book was issued: " << days;
        } else {
            cout << "\n\t\t\tNo book issued to return!";
        }
    }

};



#endif //LIBRARY_PROJECT_OOP_STUDENT_H
