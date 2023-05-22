//
// Created by Haris Ali on 5/22/2023.
//

//
// Created by Haris Ali on 5/22/2023.
//

#include "Library.h"

void Library::addBook() {
    headMessage("Add Book");
    cout << "\n\n";
    Books newBook;
    cout << "\n\t\t\tEnter Book ID: ";
    cin >> newBook.book_id;
    cin.ignore();
    for (int i = 0; i < bookCount; i++) {
        if (books[i].book_id == newBook.book_id) {
            cout << "\n\t\t\tBook with the same ID already exists!";
            getch();
            return; // Exit the function if duplicate ID is found
        }
    }
    cout << "\n\t\t\tEnter Book Name: ";
    getline(cin, newBook.book_name);
    cout << "\n\t\t\tEnter Author Name: ";
    getline(cin, newBook.author_name);
    cout << "\n\t\t\tEnter Quantity: ";
    cin >> newBook.quantity;
    books.push_back(newBook);
    bookCount++;
    cout << "\n\t\t\tBook added successfully!";
}

void Library::modifyBook() {
    headMessage("Modify Book");
    cout << "\n\n";
    int id;
    cout << "\n\t\t\tEnter Book ID to modify: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].book_id == id) {
            cout << "\n\t\t\tEnter new Book Name: ";
            cin.ignore();
            getline(cin, books[i].book_name);
            cout << "\n\t\t\tEnter new Author Name: ";
            getline(cin, books[i].author_name);
            cout << "\n\t\t\tBook modified successfully!";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n\t\t\tBook not found!";
    }
}

void Library::deleteBook() {
    headMessage("Delete Book");
    cout << "\n\n";
    int id;
    cout << "\n\t\t\tEnter Book ID to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].book_id == id) {
            books.erase(books.begin() + i);
            bookCount--;
            cout << "\n\t\t\tBook deleted successfully!";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n\t\t\tBook not found!";
    }
}

void Library::viewBookList(int x) {
    headMessage("View Book List");
    cout << "\n\n";
    for (int i = 0; i < bookCount; i++) {
        cout << "\n\n\t\t\t\t\t\t********** " << i + 1 << ". ********** \n";
        cout << "\n\t\t\tBook Name : " << books[i].book_name << endl;
        cout << "\n\t\t\tBook's Author Name : " << books[i].author_name << endl;
        cout << "\n\t\t\tBook's ID : " << books[i].book_id << endl;
        if (x == 1) {
            cout << "\n\t\t\tBook's Quantity : " << books[i].quantity << endl;
        }
    }
    cout << "\n\t\t\tPress any key to continue.....";
    getch();
}

void Library::searchBook() {
    headMessage("Search Book");
    int choice;
    cout << "\n\n\t\t\t1. Search by Book ID";
    cout << "\n\n\t\t\t2. Search by Book Name";
    cout << "\n\n\t\t\tEnter your choice: ";
    cin >> choice;
    cin.ignore();
    system("cls");
    switch (choice) {
        case 1: {
            int bookID;
            cout << "\n\n\t\t\tEnter Book ID: ";
            cin >> bookID;
            cin.ignore();

            // Search for book by ID
            for (int i = 0; i < bookCount; i++) {
                if (books[i].book_id == bookID) {
                    cout << "\n\n\t\t\tBook Found!";
                    displayBookDetails(books[i]);
                    return;
                }
            }
            cout << "\n\n\t\t\tBook not found!";
            break;
        }
        case 2: {
            string bookName;
            cout << "\n\n\t\t\tEnter Book Name: ";
            getline(cin, bookName);

            // Search for book by name
            for (int i = 0; i < bookCount; i++) {
                if (books[i].book_name == bookName) {
                    cout << "\n\n\t\t\tBook Found!";
                    displayBookDetails(books[i]);
                    return;
                }
            }
            cout << "\n\n\t\t\tBook not found!";
            break;
        }
        default:
            cout << "\n\n\t\t\tInvalid choice! Please try again.";
    }
}

void Library::displayBookDetails(const Books& book) {
    headMessage("Book Details");
    cout << "\n\n\t\t\tBook ID: " << book.book_id;
    cout << "\n\n\t\t\tBook Name: " << book.book_name;
    cout << "\n\n\t\t\tAuthor Name: " << book.author_name;
    cout << "\n\n\t\t\tQuantity: " << book.quantity;
    getch();
}

void Library::saveBookData() {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (int i = 0; i < bookCount; i++) {
            file << books[i].book_id << ","
                 << books[i].book_name << ","
                 << books[i].author_name << ","
                 << books[i].quantity << "\n";
        }
        file.close();
        cout << "\n\t\t\tBook data saved successfully!";
    } else {
        cout << "\n\t\t\tFailed to save book data!";
    }
}

void Library::loadBookData() {
    ifstream file("books.txt");
    if (file.is_open()) {
        bookCount = 0;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            int bookId = stoi(token);
            getline(ss, token, ',');
            string bookName = token;
            getline(ss, token, ',');
            string authorName = token;
            getline(ss, token, ',');
            int quantity = stoi(token);

            Books newBook;
            newBook.book_id = bookId;
            newBook.book_name = bookName;
            newBook.author_name = authorName;
            newBook.quantity = quantity;

            books.push_back(newBook);
            bookCount++;
        }
        file.close();
        cout << "\n\t\t\tBook data loaded successfully!";
    } else {
        cout << "\n\t\t\tFailed to load book data!";
    }
}

void Library::issueBookToStudent() {
    headMessage("Issue Book to Student");
    int studentID;
    cout << "\n\t\t\tEnter Student ID: ";
    cin >> studentID;
    cin.ignore();

    Student student;
    student.setStudentID(studentID);

    int bookID;
    cout << "\n\t\t\tEnter Book ID: ";
    cin >> bookID;
    cin.ignore();

    student.issueBook(bookID);
}

void Library::returnBookFromStudent() {
    headMessage("Return Book from Student");
    cout << "\n\t\t\t***** Return Book from Student *****";
    int studentID;
    cout << "\n\t\t\tEnter Student ID: ";
    cin >> studentID;
    cin.ignore();

    Student student;
    student.setStudentID(studentID);

    student.returnBook();
}


//#include "Library.h"
//
//void Library::addBook(){
//    headMessage("Add Book");
//    cout << "\n\n";
//    Books newBook;
//    cout << "\n\t\t\tEnter Book ID: ";
//    cin >> newBook.book_id;
//    cin.ignore();
//    for (int i = 0; i < bookCount; i++) {
//        if (books[i].book_id == newBook.book_id) {
//            cout << "\n\t\t\tBook with the same ID already exists!";
//            getch();
//            return; // Exit the function if duplicate ID is found
//        }
//    }
//    cout << "\n\t\t\tEnter Book Name: ";
//    getline(cin, newBook.book_name);
//    cout << "\n\t\t\tEnter Author Name: ";
//    getline(cin, newBook.author_name);
//    cout << "\n\t\t\tEnter Quantity: ";
//    cin >> newBook.quantity;
//    books[bookCount++] = newBook;
//    cout << "\n\t\t\tBook added successfully!";
//}
//
//void Library::modifyBook(){
//    headMessage("Modify Book");
//    cout << "\n\n";
//    int id;
//    cout << "\n\t\t\tEnter Book ID to modify: ";
//    cin >> id;
//    bool found = false;
//    for (int i = 0; i < bookCount; i++) {
//        if (books[i].book_id == id) {
//            cout << "\n\t\t\tEnter new Book Name: ";
//            cin.ignore();
//            getline(cin, books[i].book_name);
//            cout << "\n\t\t\tEnter new Author Name: ";
//            getline(cin, books[i].author_name);
//            cout << "\n\t\t\tBook modified successfully!";
//            found = true;
//            break;
//        }
//    }
//    if (!found) {
//        cout << "\n\t\t\tBook not found!";
//    }
//}
//
//void Library::deleteBook(){
//    headMessage("Delete Book");
//    cout << "\n\n";
//    int id;
//    cout << "\n\t\t\tEnter Book ID to delete: ";
//    cin >> id;
//    bool found = false;
//    for (int i = 0; i < bookCount; i++) {
//        if (books[i].book_id == id) {
//            for (int j = i; j < bookCount - 1; j++) {
//                books[j] = books[j + 1];
//            }
//            bookCount--;
//            cout << "\n\t\t\tBook deleted successfully!";
//            found = true;
//            break;
//        }
//    }
//    if (!found) {
//        cout << "\n\t\t\tBook not found!";
//    }
//}
//
//void  Library::viewBookList(int x) {
//    headMessage("View Book List");
//    cout << "\n\n";
//    for (int i = 0; i < bookCount; i++) {
//        cout << "\n\n\t\t\t\t\t\t********** " << i + 1 << ". ********** \n";
//        cout << "\n\t\t\tBook Name : " << books[i].book_name << endl;
//        cout << "\n\t\t\tBook's Author Name : " << books[i].author_name << endl;
//        cout << "\n\t\t\tBook's ID : " << books[i].book_id << endl;
//        if (x == 1) {
//            cout << "\n\t\t\tBook's Quantity : " << books[i].quantity << endl;
//        }
//    }
//    cout << "\n\t\t\tPress any key to continue.....";
//    getch();
//}
//
//void Library::searchBook() {
//    headMessage("Search Book");
//    int choice;
//    cout << "\n\n\t\t\t1. Search by Book ID";
//    cout << "\n\n\t\t\t2. Search by Book Name";
//    cout << "\n\n\t\t\tEnter your choice: ";
//    cin >> choice;
//    cin.ignore();
//    system("cls");
//    switch (choice) {
//        case 1: {
//            int bookID;
//            cout << "\n\n\t\t\tEnter Book ID: ";
//            cin >> bookID;
//            cin.ignore();
//
//            // Search for book by ID
//            for (int i = 0; i < bookCount; i++) {
//                if (books[i].book_id == bookID) {
//                    cout << "\n\n\t\t\tBook Found!";
//                    displayBookDetails(books[i]);
//                    return;
//                }
//            }
//            cout << "\n\n\t\t\tBook not found!";
//            break;
//        }
//        case 2: {
//            string bookName;
//            cout << "\n\n\t\t\tEnter Book Name: ";
//            getline(cin, bookName);
//
//            // Search for book by name
//            for (int i = 0; i < bookCount; i++) {
//                if (books[i].book_name == bookName) {
//                    cout << "\n\n\t\t\tBook Found!";
//                    displayBookDetails(books[i]);
//                    return;
//                }
//            }
//            cout << "\n\n\t\t\tBook not found!";
//            break;
//        }
//        default:
//            cout << "\n\n\t\t\tInvalid choice! Please try again.";
//    }
//}
//
//void Library::displayBookDetails(const Books& book) {
//    headMessage("Book Details");
//    cout << "\n\n\t\t\tBook ID: " << book.book_id;
//    cout << "\n\n\t\t\tBook Name: " << book.book_name;
//    cout << "\n\n\t\t\tAuthor Name: " << book.author_name;
//    cout << "\n\n\t\t\tQuantity: " << book.quantity;
//    getch();
//}
//
//void Library::saveBookData() {
//    ofstream file("books.txt");
//    if (file.is_open()) {
//        for (int i = 0; i < bookCount; i++) {
//            file << books[i].book_id << ","
//                 << books[i].book_name << ","
//                 << books[i].author_name << ","
//                 << books[i].quantity << "\n";
//        }
//        file.close();
//        cout << "\n\t\t\tBook data saved successfully!";
//    } else {
//        cout << "\n\t\t\tFailed to save book data!";
//    }
//}
//
//void Library::loadBookData() {
//    ifstream file("books.txt");
//    if (file.is_open()) {
//        bookCount = 0;
//        string line;
//        while (getline(file, line)) {
//            stringstream ss(line);
//            string token;
//            getline(ss, token, ',');
//            int bookId = stoi(token);
//            getline(ss, token, ',');
//            string bookName = token;
//            getline(ss, token, ',');
//            string authorName = token;
//            getline(ss, token, ',');
//            int quantity = stoi(token);
//
//            Books newBook;
//            newBook.book_id = bookId;
//            newBook.book_name = bookName;
//            newBook.author_name = authorName;
//            newBook.quantity = quantity;
//
//            books.push_back(newBook);
//            bookCount++;
//        }
//        file.close();
//        cout << "\n\t\t\tBook data loaded successfully!";
//    } else {
//        cout << "\n\t\t\tFailed to load book data!";
//    }
//}
//
////void Library::loadBookData() {
////    ifstream file("books.txt");
////    if (file.is_open()) {
////        bookCount = 0;
////        string line;
////        while (getline(file, line)) {
////            stringstream ss(line);
////            string token;
////            getline(ss, token, ',');
////            books[bookCount].book_id = stoi(token);
////            getline(ss, books[bookCount].book_name, ',');
////            getline(ss, books[bookCount].author_name, ',');
////            getline(ss, token, ',');
////            books[bookCount].quantity = stoi(token);
////            bookCount++;
////        }
////        file.close();
////            cout << "\n\t\t\tBook data loaded successfully!";
////        } else {
////            cout << "\n\t\t\tFailed to load book data!";
////    }
////}
//
//void Library::issueBookToStudent() {
//    headMessage("Issue Book to Student");
//    int studentID;
//    cout << "\n\t\t\tEnter Student ID: ";
//    cin >> studentID;
//    cin.ignore();
//
//    Student student;
//    student.setStudentID(studentID);
//
//    int bookID;
//    cout << "\n\t\t\tEnter Book ID: ";
//    cin >> bookID;
//    cin.ignore();
//
//    student.issueBook(bookID);
//}
//
//void Library::returnBookFromStudent() {
//    headMessage("Return Book from Student");
//    cout << "\n\t\t\t***** Return Book from Student *****";
//    int studentID;
//    cout << "\n\t\t\tEnter Student ID: ";
//    cin >> studentID;
//    cin.ignore();
//
//    Student student;
//    student.setStudentID(studentID);
//
//    student.returnBook();
//}
