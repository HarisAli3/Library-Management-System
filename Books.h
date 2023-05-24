//
// Created by Haris Ali on 5/22/2023.
//

#ifndef LIBRARY_PROJECT_OOP_BOOKS_H
#define LIBRARY_PROJECT_OOP_BOOKS_H

using namespace std;

class Books {
public:
    int bookID;
    string bookName;
    string authorName;
    int quantity;
    Books() {
        bookID = 0;
        bookName = "";
        authorName = "";
        quantity = 0;
    }

};


#endif //LIBRARY_PROJECT_OOP_BOOKS_H
