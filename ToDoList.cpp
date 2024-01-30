// ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// struct fo todo task
struct ToDoTask
{
    int taskIndex;
    bool taskComplete;
    string taskName;
    string taskAbout;
};

int ReadOnlyFromFile()
{
    int lastTaskIndex = 0;
    ifstream myfile ("example.txt");
    string line = "";

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            cout << line << '\n';
            lastTaskIndex++;
        }
        myfile.close();
    }

    else cout << "Unable to open file";
    
    return lastTaskIndex;
}

void WriteToTXTFile(int index, bool complete, string taskName, string aboutTask)
{
    ofstream myfile;
    myfile.open("example.txt", ios::app);
    myfile << index << " " << (boolalpha) << complete << " " << taskName << " " <<  aboutTask << endl;
    myfile.close();
}



void WriteTask()
{
    int index= ReadOnlyFromFile();
    string complete = "FALSE";
    bool isComplete = false;
    string taskName = "TASK NAME";
    string aboutTask = "ABOUT TASK";

    cout << "\n Task Name: ";
    cin.ignore();
    getline(cin,taskName);
    cout << "\n Task is about: ";
    getline(cin, aboutTask);
    
    WriteToTXTFile(index, isComplete, taskName, aboutTask);
}

void GiveMeAllMyTask()
{
    cout << "Here it is:\n";
    ReadOnlyFromFile();
}

void AddNewTask()
{
    WriteTask();
}

void UpdateTask()
{
    cout << "Updating" << endl;
    // Get task index
    // Update status of struct
    //his should be awsome in Update task : )
    cout << " Is task already done?: ";
    //getline(cin, complete);
    //updating only last index
    int lastIndex = ReadOnlyFromFile();
}

int main()
{
    std::cout << "Hello World!\n";
    int ui = -1;
    string userInput = "";
    do
    {
        cout << " Option Menu: "
            "\n 0 - For terminate programm"
            "\n 1 - For Add New Task"
            "\n 2 - For Print All Tasks"
            "\n 3 - For Update Tasks"
            "\n You Choose: ";
        cin >> userInput;       
        ui = atoi(userInput.c_str());

        switch (ui)
        {
        case 1:
            AddNewTask();
            break;
        case 2:
            GiveMeAllMyTask();
            break;
        case 3:
            cout << "updating in progress…" << endl;
            UpdateTask();
            break;

        case 0:
            cout << "Bay-Bay";
            break;

        default:
            break;
        }

    } while (ui != 0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
