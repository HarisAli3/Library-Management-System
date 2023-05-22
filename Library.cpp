//
// Created by Haris Ali on 5/22/2023.
//

//
// Created by Haris Ali on 5/22/2023.
//

#include "Library.h"
#include "Books.h"

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

bool isBookAlreadyIssued(int bookID) {
    ifstream file("issued_books.txt");
    if (file.is_open()) {
        int id, book;
        while (file >> id >> book) {
            if (book == bookID) {
                file.close();
                cout << "Already Issued" << endl;
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
    if (isBookAlreadyIssued(bookID) || books[0].quantity <= 0) {
        cout << "\n\t\t\tBook already issued to another student or no stock available!" << endl;
        return;
    }

    // Find the book in the library
    Books* book = nullptr;
    for (auto& b : books) {
        if (b.book_id == bookID) {
            book = &b;
            break;
        }
    }

    if (book != nullptr) {
        // Reduce the quantity of the book
        book->quantity -= 1;

        // Open the file to append the issued book information
        ofstream outFile("issued_books.txt", ios::app);
        if (outFile.is_open()) {
            outFile << studentID << " " << bookID << " " << time(nullptr) << endl;
            outFile.close();
            cout << "\n\t\t\tBook '" << book->book_name << "' issued to student!" << endl;
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
                if (b.book_id == bookID) {
                    b.quantity += 1;
                    saveBookData();
                    cout << "\n\t\t\tBook returned successfully!" << endl;
                    return;
                }
            }
        }
    } else {
        cout << "\n\t\t\tBook not issued to the specified student!" << endl;
    }
}

//void Library::issueBookToStudent() {
//    cout << "Issue Book to Student" << endl;
//
//    int studentID;
//    cout << "Enter Student ID: ";
//    cin >> studentID;
//    cin.ignore();
//
//    int bookID;
//    cout << "Enter Book ID: ";
//    cin >> bookID;
//    cin.ignore();
//
//    if (isBookAlreadyIssued(bookID) || books[0].quantity < 0) {
//        cout << "Book already issued to another student!" << endl;
//        return;
//    }
//
//    for (int i = 0; i < bookCount; i++) {
//        if (books[i].book_id == bookID) {
//            cout << "Book Found!" << endl;
//            books[0].quantity -= 1;
//            break;
//        }
//    }
//
//    // Check if the book is already issued to another student
//
//    getch();
//
////     Find the book in the library
//    Books* book = nullptr;
//    for (auto& b : books) {
//        if (b.book_id == bookID) {
//            book = &b;
//            break;
//        }
//    }
//
//    if (book != nullptr) {
//        // Open the file to append the issued book information
//        ofstream outFile("issued_books.txt", ios::app);
//        if (outFile.is_open()) {
//            outFile << studentID << " " << bookID << endl;
//            outFile.close();
//            cout << "Book '" << book->getBookName() << "' issued to student!" << endl;
//        } else {
//            cout << "Failed to issue book!" << endl;
//        }
//    } else {
//        cout << "Book not found in the library!" << endl;
//    }
//}
//
//void Library::returnBookFromStudent() {
//    cout << "Return Book from Student" << endl;
//
//    int studentID;
//    cout << "Enter Student ID: ";
//    cin >> studentID;
//    cin.ignore();
//
//    int bookID;
//    cout << "Enter Book ID: ";
//    cin >> bookID;
//    cin.ignore();
//
//    // Check if the book is issued to the specified student
//    bool bookIssued = false;
//    ifstream file("issued_books.txt");
//    if (file.is_open()) {
//        int id, book;
//        while (file >> id >> book) {
//            if (id == studentID && book == bookID) {
//                bookIssued = true;
//                break;
//            }
//        }
//        file.close();
//    }
//
//    if (bookIssued) {
//        // Calculate the number of days the book was issued
//        time_t currentTime = time(nullptr);
//        ifstream file("issued_books.txt");
//        if (file.is_open()) {
//            int id, book;
//            while (file >> id >> book) {
//                if (id == studentID && book == bookID) {
//                    time_t issueTime;
//                    file >> issueTime;
//
//                    double days = difftime(currentTime, issueTime) / (24 * 60 * 60);
//                    if (days > 30) {
//                        double fine = 15 * (days - 30);
//                        cout << "Fine to be paid: $" << fine << endl;
//                    }
//                    break;
//                }
//            }
//            file.close();
//        }
//
//        // Remove the returned book information from the file
//        ifstream inputFile("issued_books.txt");
//        ofstream outputFile("temp.txt");
//        if (inputFile.is_open() && outputFile.is_open()) {
//            int id, book;
//            time_t issueTime;
//            while (inputFile >> id >> book >> issueTime) {
//                if (!(id == studentID && book == bookID)) {
//                    outputFile << id << " " << book << " " << issueTime << endl;
//                }
//            }
//            inputFile.close();
//            outputFile.close();
//
//            // Rename the temporary file to the original file
//            remove("issued_books.txt");
//            rename("temp.txt", "issued_books.txt");
//
//            cout << "Book returned by student!" << endl;
//        } else {
//            cout << "Failed to return book!" << endl;
//        }
//    } else {
//        cout << "Book not issued to this student!" << endl;
//    }
//}


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
//    Library::saveBookData();
//    getch();
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

//void Library::issuedBooksLogs() {
//    headMessage("Issued Books Logs");
//
//    // Iterate over all students
//    for (const auto& student : students) {
//        cout << "\n\n\t\t\tStudent ID: " << student.getStudentID();
//        cout << "\n\n\t\t\tIssued Books: ";
//        const vector<Books>& issuedBooks = student.getIssuedBooks();
//        if (issuedBooks.empty()) {
//            cout << "No books issued";
//        } else {
//            for (const auto& book : issuedBooks) {
//                cout << "\n\t\t\t- " << book->getBookName() << " (Book ID: " << book->getBookID() << ")";
//            }
//        }
//    }
//
//    getch();
//}





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
