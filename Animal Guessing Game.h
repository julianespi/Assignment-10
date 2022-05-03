#pragma once
#include "Tree of Strings.h"
//Create a bass tree that harded coded animals.
//create a lean function and a ask and move function.
// if games doents guess your animal use the lear function.
//left us yes right is no
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

void learn(binary_tree_node<string>* leafptr)
{
    string guessAnimal;
    string correctAnimal;
    string newQuestion;

    guessAnimal = leafptr->getData();
    correctAnimal = inputString("I can give up. what are you? ", true);
    cout << "Please type a yes/no question that will distinguish a " << correctAnimal << " from a " << guessAnimal << "." << endl;
    newQuestion = inputString("your question: ", true);
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

void GuessingGame()
{
    //decalre the trunk
    binary_tree_node<string>* root = nullptr;
    string fileName = "animal.txt";

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
    print_tree("\t\t", root, false, true, false);
}


