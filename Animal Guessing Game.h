#pragma once
//Create a bass tree that harded coded animals.
//create a lean function and a ask and move function.
// if games doents guess your animal use the lear function.

void GuessingGame()
{
    //decalre the trunk
    binary_tree_node<string>* root = nullptr;
  

    //read the file
    string fileName = inputString("Enter the name of the file: ", false);
    int newEmployeeIDIncrment = 0;
    string correctFile = "EmployeeRecords.dat";

    cout << "loading file..." << endl;

    ifstream file1;
    file1.open(fileName, ios::in);
    if (file1.fail())
    {
        cout << "ERROR: file cannot be read, try " << correctFile << endl;
        return;
    }

    //transfer data from tile to tree
    root = new binary_tree_node<string>;
    

    string temp;
    while (!file1.eof())
    {
        getline(file1, temp, '\n');
        if (temp[0] == '[')
        {
            // have this be in the question
        }
        else if (temp[0] == '(')
        {
            // have this be an answer
        }
    }

    
    cout << "file loaded and data downloaded" << endl;
    file1.close();
}