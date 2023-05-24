//
// Created by Haris Ali on 5/22/2023.
//

#include "Library.h"
#include "Books.h"


void Library::MainMenu(Library& librarian) {
    int choice;
    do {
        MainMenu:
        headMessage("Library Management System");
        cout << "\n\n\t\t\t1. Librarian Menu";
        cout << "\n\n\t\t\t2. Student Menu";
        cout << "\n\n\t\t\t0. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> choice;
//        system("cls");

        switch(choice) {
            case 1: {
                Library::LibrarianMenu(librarian);
                goto MainMenu;
                break;
            }
            case 2:
                StudentMenu(librarian);
                break;
        }
    } while (choice != 0);
}

void Library::LibrarianMenu(Library& librarian) {
    int librarianChoice;
    do {
        headMessage("Librarian Menu");
        cout << "\n\n\t\t\t1. View Book List";
        cout << "\n\n\t\t\t2. Search Book";
        cout << "\n\n\t\t\t3. Add Book";
        cout << "\n\n\t\t\t4. Modify Book";
        cout << "\n\n\t\t\t5. Delete Book";
        cout << "\n\n\t\t\t6. Issue Book";
        cout << "\n\n\t\t\t7. Return Book";
        cout << "\n\n\t\t\t8. View Issued Books History:";
        cout << "\n\n\t\t\t9. Save Book Data";
        cout << "\n\n\t\t\t0. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> librarianChoice;

        switch (librarianChoice) {
            case 1:
                librarian.viewBookList(1);
                break;
            case 2:
                librarian.searchBook();
                break;
            case 3:
                librarian.addBook();
                break;
            case 4:
                librarian.modifyBook();
                break;
            case 5:
                librarian.deleteBook();
                break;
            case 6:
                librarian.issueBookToStudent();
                break;
            case 7:
                librarian.returnBookFromStudent();
                break;
            case 8:
                Library::viewIssuedBooksHistory();
                break;
            case 9:
                librarian.saveBookData();
                break;
            case 0:
                librarian.saveBookData();
                cout << "\n\t\t\tThank you for using the Library Management System!";
                break;
            default:
                cout << "\n\t\t\tInvalid choice! Please try again.";
        }
    } while (librarianChoice != 0);

}

void Library::StudentMenu(Library& student) {
    int studentChoice;
    do { headMessage("Student Menu");
        cout << "\n\n\t\t\t1. View Book List";
        cout << "\n\n\t\t\t2. Search Book";
        cout << "\n\n\t\t\t0. Go Back";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> studentChoice;

        switch (studentChoice) {
            case 1:
                student.viewBookList(2);
                break;
            case 2:
                student.searchBook();
                break;
            case 3:
//                            student.calculateFine();
                break;
            case 0:
                cout << "\n\t\t\tThank you for using the Library Management System!";
                break;
            default:
                cout << "\n\t\t\tInvalid choice! Please try again.";
        }
    } while (studentChoice != 0);
}


void Library::addBook() {
    headMessage("Add Book");
    cout << "\n\n";
    Books newBook;
    cout << "\n\t\t\tEnter Book ID: ";
    cin >> newBook.bookID;
    cin.ignore();
    for (int i = 0; i < bookCount; i++) {
        if (books[i].bookID == newBook.bookID) {
            cout << "\n\t\t\tBook with the same ID already exists!";
            getch();
            return; // Exit the function if duplicate ID is found
        }
    }
    cout << "\n\t\t\tEnter Book Name: ";
    getline(cin, newBook.bookName);
    cout << "\n\t\t\tEnter Author Name: ";
    getline(cin, newBook.authorName);
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
        if (books[i].bookID == id) {
            cout << "\n\t\t\tEnter new Book Name: ";
            cin.ignore();
            getline(cin, books[i].bookName);
            cout << "\n\t\t\tEnter new Author Name: ";
            getline(cin, books[i].authorName);
            cout << "\n\t\t\tEnter new Quantity: ";
            cin >> books[i].quantity;
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
        if (books[i].bookID == id) {
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
        cout << "\n\t\t\tBook Name : " << books[i].bookName << endl;
        cout << "\n\t\t\tBook's Author Name : " << books[i].authorName << endl;
        cout << "\n\t\t\tBook's ID : " << books[i].bookID << endl;
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
                if (books[i].bookID == bookID) {
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
                if (books[i].bookName == bookName) {
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
    cout << "\n\n\t\t\tBook ID: " << book.bookID;
    cout << "\n\n\t\t\tBook Name: " << book.bookName;
    cout << "\n\n\t\t\tAuthor Name: " << book.authorName;
    cout << "\n\n\t\t\tQuantity: " << book.quantity;
    getch();
}


bool isBookAlreadyIssued(int bookID, int studentID) {
    ifstream file("issued_books.txt");
    if (file.is_open()) {
        int id, book;
        while (file >> id >> book) {
            if (id == studentID) {
                file.close();
                cout << "\n\n\t\t\tAlready Issued" << endl;
                getch();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void Library::issueBookToStudent() {
    headMessage("Issue Book to Student");
    int studentID;
    cout << "\n\t\t\tEnter Student ID: ";
    cin >> studentID;
    cin.ignore();

    int bookID;
    cout << "\n\t\t\tEnter Book ID: ";
    cin >> bookID;
    cin.ignore();

    // Check if the book is already issued to another student
    if (isBookAlreadyIssued(bookID, studentID) || books[0].quantity <= 0) {
        cout << "\n\t\t\tBook already issued to another student or no stock available!" << endl;
        return;
    }

    // Find the book in the library
    Books* book = nullptr;
    for (auto& b : books) {
        if (b.bookID == bookID) {
            book = &b;
            break;
        }
    }
    if (book != nullptr) {
        // Reduce the quantity of the book+
        book->quantity -= 1;

        // Open the file to append the issued book information
        ofstream outFile("issued_books.txt", ios::app);
        if (outFile.is_open()) {
            outFile << studentID << " " << bookID << " " << time(nullptr) << endl;
            outFile.close();
            cout << "\n\t\t\tBook '" << book->bookName << "' issued to student!" << endl;
            saveBookData();
        } else {
            cout << "\n\t\t\tFailed to issue book!" << endl;
        }
    } else {
        cout << "\n\t\t\tBook not found in the library!" << endl;
    }
}

void Library::returnBookFromStudent() {
    headMessage("Return Book from Student");
    int studentID;
    cout << "\n\t\t\tEnter Student ID: ";
    cin >> studentID;
    cin.ignore();

    int bookID;
    cout << "\n\t\t\tEnter Book ID: ";
    cin >> bookID;
    cin.ignore();

    // Check if the book is issued to the specified student
    bool bookIssued = false;
    ifstream file("issued_books.txt");
    if (file.is_open()) {
        int id, book;
        while (file >> id >> book) {
            if (id == studentID && book == bookID) {
                bookIssued = true;
                break;
            }
        }
        file.close();
    }

    if (bookIssued) {
        // Calculate the number of days the book was issued
        time_t currentTime = time(nullptr);
        ifstream file("issued_books.txt");
        if (file.is_open()) {
            int id, book;
            while (file >> id >> book) {
                if (id == studentID && book == bookID) {
                    time_t issueTime;
                    file >> issueTime;

                    double days = difftime(currentTime, issueTime) / (24 * 60 * 60);
                    if (days > 30) {
                        double fine = 15 * (days - 30);
                        cout << "\n\t\t\tFine to be paid: $" << fine << endl;
                    }
                    break;
                }
            }
            file.close();
        }

        // Remove the returned book information from the file
        ifstream inputFile("issued_books.txt");
        ofstream outputFile("temp.txt");
        if (inputFile.is_open() && outputFile.is_open()) {
            int id, book;
            time_t issueTime;
            while (inputFile >> id >> book >> issueTime) {
                if (!(id == studentID && book == bookID)) {
                    outputFile << id << " " << book << " " << issueTime << endl;
                }
            }
            inputFile.close();
            outputFile.close();

            // Replace the original file with the updated file
            if (remove("issued_books.txt") != 0) {
                cout << "\n\t\t\tFailed to return book!" << endl;
                return;
            }
            if (rename("temp.txt", "issued_books.txt") != 0) {
                cout << "\n\t\t\tFailed to return book!" << endl;
                return;
            }

            // Increase the quantity of the book
            for (auto& b : books) {
                if (b.bookID == bookID) {
                    b.quantity += 1;
                    saveBookData();
                    cout << "\n\t\t\tBook returned successfully!" << endl;
                    return;
                }
            }
        }
    } else {
        cout << "\n\t\t\tBook not issued to the specified student!";
        getch();
    }
}



void Library::viewIssuedBooksHistory() {
    headMessage("View Issued History");
    ifstream file("issued_books.txt");
    if (file.is_open()) {
        // Check if the file is empty
        file.seekg(0,ios::end);
        if(file.tellg()<1){
            cout << "\n\t\t\tNo issued history found!" << endl;
            getch();
            //empty
        }else {
            file.clear(); // clear all flags(eof)
            file.seekg(0, ios::beg);//reset to front
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
            //not empty
        }
        file.close();
        getch();
    } else {
        cout << "\n\n\t\t\tFile Not Found! ";
        cout << "\n\n\t\t\tPress and key to continue!!! ";
        getch();
    }
}

void Library::saveBookData() {
    ofstream file("books.txt");
    if (file.is_open()) {
        for (int i = 0; i < bookCount; i++) {
            file << books[i].bookID << ","
                 << books[i].bookName << ","
                 << books[i].authorName << ","
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
            newBook.bookID = bookId;
            newBook.bookName = bookName;
            newBook.authorName = authorName;
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

