#pragma once
#include "Tree of Strings.h"

//Precondition: takes in a binary tree and a file
//postcondition: filles the binary tree
void insert(binary_tree_node<string>*& tree, ifstream& file1)
{
    string temp;

    getline(file1, temp);

    if (temp != "")
    {
        tree = new binary_tree_node<string>;
        tree->setData(temp);
        
        if (temp[0] == '[')
        {
            insert(tree->getLeft(), file1);
            insert(tree->getRight(), file1);
        }
        else if (temp[0] = '(')
        {
            tree->setLeft(NULL);
            tree->setRight(NULL);
        }
    }
    else
    {
        tree = NULL;
    }
}

//precondtion: takes a leaft pointer
//postcondtion: replaces the current pointer with a question and adds the correct animal to the tree
void learn(binary_tree_node<string>* leafptr)
{
    string guessAnimal;
    string correctAnimal = "(";
    string newQuestion = "[";

    guessAnimal = leafptr->getData();
    correctAnimal += inputString("I can give up. what are you? ", true);
    correctAnimal += ")";
    cout << "Please type a yes/no question that will distinguish a " << correctAnimal << " from a " << guessAnimal << "." << endl;
    newQuestion += inputString("your question and make sure to add a ?: ", true);
    newQuestion += "]";
    leafptr->setData(newQuestion);
    cout << "As, a " << correctAnimal << ", " << newQuestion << endl;
    char yesOrNO = inputStatus("Please answer: ", 'Y', 'N');
    if (yesOrNO == 'Y')
    {
        leafptr->setLeft(new binary_tree_node<string>(correctAnimal));
        leafptr->setRight(new binary_tree_node<string>(guessAnimal));
    }
    else
    {
        leafptr->setLeft(new binary_tree_node<string>(guessAnimal));
        leafptr->setRight(new binary_tree_node<string>(correctAnimal));
    }
}

//precondtion: takes in the current node
//postcondtion: moves left or right on the binary tree
void askAndMove(binary_tree_node<string>*& currentPtr)
{
    cout << currentPtr->getData() << endl;
    char yesOrNO = inputStatus("Please answer: ", 'Y', 'N');
    if (yesOrNO == 'Y')
    {
        currentPtr = currentPtr->getLeft();
    }
    else
    {
        currentPtr = currentPtr->getRight();
    }
}

//precondtion: takes in a pointers
//postcondtion guees the type of animal you are thinking of
void play(binary_tree_node<string>* currentPtr)
{
    cout << "Think of an animal, then press the return key.";
    cin.ignore();

    while (!currentPtr->isLeaf())
        askAndMove(currentPtr);
    cout << "My Guess is " << currentPtr->getData() << endl;
    char yesOrNO = inputStatus("Please answer: ", 'Y', 'N');
    if (yesOrNO == 'N')
    {
        learn(currentPtr);
    }
    else
    {
        cout << "I knew it all along!" << endl;
    }
}

//Precondition:none
//PostCondition:displays the main menu
int GuessingGameMenuOption()
{
    cout << endl << "Welcome to Animal Guessing Game";
    cout << endl << "==========================================";
    cout << endl << "1> Play the game";
    cout << endl << "2> Save the game file";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 2);
    cout << endl << endl << endl;
    return options;
}

void startGuessingGame(binary_tree_node<string>*&root, string fileName)
{
    //decalre the trunk
    root = nullptr;
    fileName = "animal.txt";

    cout << "loading file..." << endl;

    ifstream file1;
    file1.open(fileName, ios::in);
    if (file1.fail())
    {
        return;
    }

    string temp;
    insert(root, file1);

    file1.close();
    char yesOrNO;
    do
    {
        play(root);
        yesOrNO = inputStatus("do you want to go again: ", 'Y', 'N');
    } while (yesOrNO == 'Y');
    cout << "Thank you for teaching me a thing or two." << endl;
    //print_tree("\t\t", root, false, true, false);
}

void saveGameFile(binary_tree_node<string>*& root, string fileName)
{
    print_tree("\t\t", root, false, true, false);
}

//driver for the guess animal game
void GuessingGame()
{
    binary_tree_node<string>* root;
    string fileName;
    cout << " A game tree for a simple game of 'animal' twenty questions would look like: " << endl << endl
        << "                                 [ Is it a mammal? ]" << endl
        << "                                      /         \ " << endl
        << "                                     /           \ " << endl
        << "                 [ Does it have stripes? ]     [ Is it a bird? ] " << endl
        << "                       /       \                  /       \ " << endl
        << "                      /         \                /         \ " << endl
        << "                 ( Zebra )    ( Lion )   [ Does it fly? ]  ( Gila monster )" << endl
        << "                                            /       \ " << endl
        << "                                           /         \ " << endl
        << "                                    ( Eagle )     ( Penguin )" << endl << endl
        << " A learning version of twenty questions: one that not only plays the game, but learns new" << endl
        << " objects when it loses." << endl;

    do
    {
        switch (GuessingGameMenuOption())
        {
        case 0: return; break;
        case 1: startGuessingGame(root, fileName); break;
        case 2: saveGameFile(root, fileName); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    

}


