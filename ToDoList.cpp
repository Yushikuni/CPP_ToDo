// ToDoList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

// struktura pro todo ulohu
struct ToDoTask
{
    bool complete;
    string taskName;
    string taskAbout;
};

void GiveMeAllMyTask()
{

}

void AddNewTask(bool isTaskComplete, string setTaskName, string setAboutTask)
{
    ofstream myfile;
    myfile.open("example.txt", ios::app);
    myfile << "Writing this to a file.\n";
    myfile << " Task Compete: " << boolalpha << isTaskComplete << "\n Task Name: " << setTaskName << "\n Task is about: " << setAboutTask << "\n";
    myfile.close();
}

int main()
{
    std::cout << "Hello World!\n";

    std::cout << "Hello There!\n";
    int ui = -1;
    string userInput = "";
    do
    {
        cout << " Option Menu: "
            "\n 0 — For terminate programm"
            "\n 1 - For Add New Task"
            "\n 2 - For Print All Tasks"
            "\n You Choose: ";
        cin >> userInput;       
        ui = atoi(userInput.c_str());

        switch (ui)
        {
        case 1:
            AddNewTask(false, "Test", "About test is text about test :D");
            break;
        case 2:
            GiveMeAllMyTask();
            break;
        case 0:
            cout << "Bay-Bay";
            break;
        default:
            break;
        }

    } while (ui != 0);
    /*
    try
    {
        int ui = atoi(userInput.c_str());
        try
        {
            switch (ui)
            {
            case 1:
                AddNewTask(false, "Test", "About test is text about test :D");
            default:
                break;
            }
        }
        catch (const std::exception&)
        {
            cout << "Convert from string to int was not successfull, programw will be terminated…";
            return 0;
        }
    }
    catch (const std::exception&)
    {
        cout << "User did not set number… program will be terminated…";
        return 0;
    }*/

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
