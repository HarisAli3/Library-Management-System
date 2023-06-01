//
// Created by Haris Ali on 5/18/2023.
//

#include "Library.h"
#include "Library.cpp"

int main() {

        Library byteCode;

        // Load books data from file
        byteCode.loadBookData();

        // Display main menu
        Library::MainMenu(byteCode);

        // Save books data to file
        byteCode.saveBookData();

    return 0;
}
