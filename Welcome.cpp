//
// Created by Haris Ali on 5/22/2023.
//

#include <cstring>
#include <conio.h>

using namespace std;

void printMessageCenter(const char* message){
    int len = 0;
    int pos = 0;

    len = (78 - strlen(message)) /2;
    printf("\t\t\t");
    for(pos = 0; pos < len; pos++){
        printf(" ");
    }
    printf("%s",message);
}
void headMessage(const char *message){
    system("cls");
    cout << "\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    cout << "\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb                                                   \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    cout << "\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb   	  LIBRARY MANAGEMENT SYSTEM Project in C++     \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    cout << "\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb                                                   \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    cout << "\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb";
    cout << "\n\t\t\t---------------------------------------------------------------------------\n";
    printMessageCenter(message);
    cout << "\n\t\t\t---------------------------------------------------------------------------";
}
void welcomeMessage(){
    system("color 0B");
    headMessage("UOL");
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t        =                 WELCOME                   =";
    cout << "\n\t\t\t\t        =                   TO                      =";
    cout << "\n\t\t\t\t        =                LIBRARY                    =";
    cout << "\n\t\t\t\t        =               MANAGEMENT                  =";
    cout << "\n\t\t\t\t        =                 SYSTEM                    =";
    cout << "\n\t\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=";
    cout << "\n\t\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n";
    cout << "\n\t\t\t\tThis Project has facility of maintaining records of books\n";
    cout << "\n\t\t\t\tOne member can issue one book at a time. If he/she";
    cout << "\n\t\t\t\tdoes not return Book upto  30 days  he/she have to";
    cout << "\n\t\t\t\tpay fine of Rs.15/- per day.";
    cout << "\n\n\n\t\t\t Press any key to continue.....";
    getch();
}