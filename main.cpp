#include <iostream>

#include "Books.cpp"
#include "Library.h"
#include "Library.cpp"

int main() {
    Library library;
    library.loadBookData();
    library.MainMenu(library);
    library.saveBookData();

    return 0;
}
