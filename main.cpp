#include <iostream>

#include "Library.h"
#include "Library.cpp"

int main() {
    Library byteCode;

    // Load books data from file
    byteCode.loadBookData();
    byteCode.MainMenu(byteCode);
    // Save books data to file
    byteCode.saveBookData();

    return 0;
}
