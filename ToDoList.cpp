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
    myfile << endl;
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
    ReadOnlyFromFile();
}

void AddNewTask()
{
    WriteTask();
}

void UpdateTask(int index, bool complete)
{
    int lastIndex = 0;
    fstream file("example.txt", ios::in | ios::out);
    string line = "";

    if (!file) {
        cerr << "Unable to open file." << endl;
        return;
    }
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (lastIndex == index)
            {
                line = (complete ? "TRUE" : "FALSE");
                break;
            }
            lastIndex++;
        }
    }

    file.clear();
    file.seekp(0, ios::beg);

    while (getline(file, line))
    {
        if (lastIndex == index) 
        {
            file << line << endl;
        }
        else
        {
            file << line << endl;
        }
        lastIndex++;
    }

    file.close();    
}

int main()
{
    std::cout << "Hello World!\n";
    int ui = -1;
    string userInput = "";
    int index;
    bool complete = false;

    try
    {
        do
        {

            cout << " Option Menu: "
                "\n ANY OTHER KEYS WILL CASE INMIDIETLY TERMINATE A PROGRAM..."
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
                cout << "...updating in progress..." << endl;
                cout << " Task index is: ";
                cin.ignore();
                cin >> index;

                cout << " Is task already done (1 for true, 0 for false)??: ";
                cin >> complete;
                UpdateTask(index, complete);

                break;

            case 0:
                cout << "Bay-Bay";
                break;

            default:
                break;
            }

        } while (ui != 0);
    }
    catch (const std::exception&)
    {
        cout << "User did not set number… program will be terminated…";
        return 0;
    }
    return 0;
}