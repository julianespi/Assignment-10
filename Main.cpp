// Names of Group:
// Julian Espinoza
// Wesley Goo
// Hamza Patel
// Arturo Islas Mejia
// Eduardo Garcia Ortiz
// Date: 4/18/2022

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "input.h"
#include "Animal Guessing Game.h"
#include "Tree container of integers.h"
#include "Tree of Strings.h"

using namespace std;

int mainMenuOption();
int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case 1: treeofStrings(); break;
        case 2: treeOfInts(); break;
        case 3: GuessingGame(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition:none
//PostCondition:displays the main menu
int mainMenuOption()
{
    cout << endl << "Chapter 9 Assignment by by Julian Espinoza, Wesley Goo, Hamza Patel, Arturo Islas Mejia, and Eduardo Garcia Ortiz";
    cout << endl << "==========================================";
    cout << endl << "1> Tree of strings";
    cout << endl << "2> Tree container of integers";
    cout << endl << "3> Animal Guessing Game";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 3);
    cout << endl << endl << endl;
    return options;
}