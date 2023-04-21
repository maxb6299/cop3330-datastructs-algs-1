#include <iostream>
#include "studentlist.h"
using namespace std;

void menuPick(char i, StudentList& list);
char getInput();

int main()
{
    StudentList list;
    
    char input = 'M';
    menuPick(input, list); // so it displays menu at start
    while (input != 'Q')
    {
        input = getInput();
        menuPick(input, list);

        cout << "\n";
    }
    cout << "Goodbye!\n";
}

void menuPick(char i, StudentList& list)
{
    if (i == 'I')
    {
        char fileName[30];
        cout << "Enter filename: ";
        cin.ignore(); // so no prev input is accepted
        cin.getline(fileName, 30);

        if(!list.ImportFile(fileName))
        {
            cout << "Invalid file. No data imported\n";
        }
    }
    else if (i == 'S')
    {
        list.ShowList();
    }
    else if (i == 'E')
    {
        char fileName[30];
        cout << "Enter filename: ";
        cin.ignore(); // so no prev input is accepted
        cin.getline(fileName, 30);

        if(!list.CreateReportFile(fileName))
        {
            cout << "Invalid file. No data imported\n";
        }
    }
    else if (i == 'M')
    {
        cout 
        << "        *** Student List menu ***\n\n"

        << "I       Import students from a file\n"
        << "S       Show student list (brief)\n"
        << "E       Export a grade report (to file)\n"
        << "M       Show this Menu\n"
        << "O       sOrt student list\n"
        << "Q       Quit Program\n";
    }
    else if (i == 'O')
    {
        list.SortList();
    }
}

char getInput()
{
    char input;

    cout << ">";
    cin >> input;

    input = toupper(input);
    return input;
}