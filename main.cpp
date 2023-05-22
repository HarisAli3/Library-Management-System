#include <iostream>

#include "Books.h"
#include "Books.cpp"
#include "Library.h"
#include "Library.cpp"
#include "Student.h"

using namespace std;

int main() {
    Library librarian;
    Student student;
    librarian.loadBookData();

    int choice;
    do {
        headMessage("Library Management System");
        cout << "\n\n\t\t\t1. Library Menu";
        cout << "\n\n\t\t\t2. Student Menu";
        cout << "\n\n\t\t\t0. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> choice;
//        system("cls");

        switch (choice) {
            case 1: {
                int librarianChoice;
                do {
                    headMessage("Library Menu");
                    cout << "\n\n\t\t\t1. Add Book";
                    cout << "\n\n\t\t\t2. Modify Book";
                    cout << "\n\n\t\t\t3. Delete Book";
                    cout << "\n\n\t\t\t4. View Book List";
                    cout << "\n\n\t\t\t5. Search Book";
                    cout << "\n\n\t\t\t6. Issue Book";
                    cout << "\n\n\t\t\t7. Return Book";
                    cout << "\n\n\t\t\t8. Save Book Data";
                    cout << "\n\n\t\t\t0. Exit";
                    cout << "\n\n\t\t\tEnter your choice: ";
                    cin >> librarianChoice;

                    switch (librarianChoice) {
                        case 1:
                            librarian.addBook();
                            break;
                        case 2:
                            librarian.modifyBook();
                            break;
                        case 3:
                            librarian.deleteBook();
                            break;
                        case 4:
                            librarian.viewBookList(1);
                            break;
                        case 5:
                            librarian.searchBook();
                            break;
                        case 6:
                            librarian.issueBookToStudent();
                            break;
                        case 7:
                            librarian.returnBookFromStudent();
                            break;
                        case 0:
                            librarian.saveBookData();
                            cout << "\n\t\t\tThank you for using the Library Management System!";
                            break;
                        default:
                            cout << "\n\t\t\tInvalid choice! Please try again.";
                    }
                } while (librarianChoice != 0);
                break;
            }
            case 2:
            {
                int studentChoice;
                do { headMessage("Student Menu");
                    cout << "\n\n\t\t\t1. View Book List";
                    cout << "\n\n\t\t\t2. Search Book";
                    cout << "\n\n\t\t\t0. Go Back";
                    cout << "\n\n\t\t\tEnter your choice: ";
                    cin >> studentChoice;

                    switch (studentChoice) {
                        case 1:
                            librarian.viewBookList(2);
                            break;
                        case 2:
                            librarian.searchBook();
                            break;
                        case 3:
//                            librarian.calculateFine();
                            break;
                        case 0:
                            cout << "\n\t\t\tThank you for using the Library Management System!";
                            break;
                        default:
                            cout << "\n\t\t\tInvalid choice! Please try again.";
                    }
                } while (studentChoice != 0);
                break;
            }
            case 0:
                cout << "\n\t\t\tThank you for using the Library Management System!";
                break;
            default:
                cout << "\n\t\t\tInvalid choice! Please try again.";
        }
    } while (choice != 0);

    librarian.saveBookData();
    return 0;
}
