//
// Created by Haris Ali on 5/22/2023.
//

#include "Librarian.h"

void Librarian::addBook(){
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
    books[bookCount++] = newBook;
    cout << "\n\t\t\tBook added successfully!";
}

void Librarian::modifyBook(){
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

void Librarian::deleteBook(){
    headMessage("Delete Book");
    cout << "\n\n";
    int id;
    cout << "\n\t\t\tEnter Book ID to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].book_id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
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

void  Librarian::viewBookList(int x) {
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

void Librarian::searchBook() {
    headMessage("Search Book");
    cout << "\n\n";
    string name;
    cout << "\n\t\t\tEnter Book Name to search: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;
    cout << "\n\t\t\tBook ID\tBook Name\tAuthor Name\tQuantity";
    for (int i = 0; i < bookCount; i++) {
        if (books[i].book_name == name) {
            cout << "\n\t\t\t" << books[i].book_id << "\t" << books[i].book_name << "\t" << books[i].author_name << "\t" << books[i].quantity;
            found = true;
        }
    }
    if (!found) {
        cout << "\n\t\t\tBook not found!";
    }
}

void Librarian::saveBookData() {
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

void Librarian::loadBookData() {
    ifstream file("books.txt");
    if (file.is_open()) {
        bookCount = 0;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            books[bookCount].book_id = stoi(token);
            getline(ss, books[bookCount].book_name, ',');
            getline(ss, books[bookCount].author_name, ',');
            getline(ss, token, ',');
            books[bookCount].quantity = stoi(token);
            bookCount++;
        }
        file.close();
//            cout << "\n\t\t\tBook data loaded successfully!";
//        } else {
//            cout << "\n\t\t\tFailed to load book data!";
    }
}