// menu.cpp

#include "store.h"

#include <iostream>
#include <cstring>

using namespace std;


class Menu
{
    

    public: 
    Menu() 
    // menu function
    {
        
        cout << "*** Welcome to Bookstore Inventory Manager ***\n"
             << "Please input the starting money in the cash register: ";

        double money;
        cin >> money;        
        store.setMoney(money);
        cout << endl;

        char input = 'M';
        do
        {
            switch(input) // selects function based on input
            {
                case 'A': menuA(); break;
                case 'F': menuF(); break;
                case 'S': menuS(); break;
                case 'D': menuD(); break;
                case 'G': menuG(); break;
                case 'O': menuO(); break;
                case 'M': menuM(); break;
                case 'X':          break;

                default: cout << "\nInvalid menu choice.  Try again.\n"; break;
            }           
            
            
            cout << "> ";
            input = charInput();

        } while (input != 'X');

        cout << "\nGoodbye!\n";
    }


    private: 

    Store store; // store that is represented in menu

    void menuA()
    // Add a Book to Inventory
    {
        // accepts title as input
        cout << "Enter title: ";
        char t[31];
        cin.ignore(); // so next getline doesn't accept prev newline            
        cin.getline(t, 30);

        // accepts author as input
        cout << "Enter author: ";
        char a[21];
        cin.getline(a, 20);

        // accepts genre as input
        cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
        Genre g = genreInput();

        // accepts price as input
        double p = priceInput();
        cout << "\n";
        
        store.addBook(t, a, g, p);
    }

    void menuF()
    // Find a book from Inventory based on author or title
    {
        // accepts title as input
        cout << "Enter search string (title or author): ";
        char t[31];
        cin.ignore(); // so next getline doesn't accept prev newline
        cin.getline(t, 30);
        cout << "\n";

        // findbook function will display automatically
        int bookNumber = store.findBook(t, 1);
        
        if (bookNumber < 0) // if book is not found
        {
            cout << "\n" << t << ": Not Found\n\n";
        }
    }

    void menuS()
    // Sell a book
    {
        // accepts title as input
        cout << "Enter title to sell: \n";
        
        char t[31];
        cin.ignore(); // so next getline doesn't accept prev newline
        cin.getline(t, 30);


        if(store.sellBook(t)) // returns false if no book is found
        {
            cout << "Sale complete!\n\n";
        }
        else
        {
            cout <<"\n" << t << " not found in the inventory\n"
                << "* No sale made *\n\n";
        }
    }

    void menuD()
    // Display the inventory list
    {
        store.display();
    }


    void menuG()
    // Genre summary
    {
        cout << "Enter Genre - (F)iction, (M)ystery, "
            << "(S)ci-Fi, or (C)omputer: ";

        Genre g = genreInput();

        cout << '\n';

        store.genreSummary(g);
    }

    void menuO()
    // Sort inventory list
    {
        cout << "Sort by (T)itle or (A)uthor? > ";

        char choice = charInput();

        if (choice != 'A' && choice != 'T') // if invalid input
        {
            cout << "\n** Invalid Sort Option\n\n";
        }
        else
        {
            store.sort(choice);
        }
    }

    void menuM()
    // displays menu choices
    {
        cout << "\n"
             << "                *** BOOKSTORE MENU ***\n"
             << "	A 	Add a Book to Inventory\n"
             << "	F 	Find a book from Inventory\n"
             << "	S 	Sell a book\n"
             << "	D 	Display the inventory list\n"
             << "	G 	Genre summary\n"
             << "	O 	Sort inventory list\n"
             << "	M 	Show this Menu\n"
             << "	X 	eXit Program\n";
    }

    char charInput()
    // accepts char input and ensures it is uppercase (so upper and lower work)
    {
        char input;
        cin >> input;

        input = toupper(input);

        return input;
    }

    double priceInput()
    // accepts price input and ensures it isn't negative
    {
        cout << "Enter price: ";
        double price;
        cin >> price;        

        if (price <= 0) // if negative price
        {
            cout << "Must enter a positive price.  Please re-enter\n";
            price = priceInput(); // calls itself to restart process
        }

        return price;
    }

    Genre genreInput()
    // accepts genre input and ensures it is valid value
    // (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer returns 0, 1, 2, or 3
    {
        char input = charInput();
        
        if (input == 'F')
        {
            return FICTION;
        }
        else if (input == 'M')
        {
            return MYSTERY;
        }
        else if (input == 'S')
        {
            return SCIFI;
        }
        else if (input == 'C')
        {
            return COMPUTER;
        }
        else
        {
            cout << "Invalid Genre entry.  Please re-enter\n"
            << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
            return genreInput(); // calls itself to restart process
        }
    }
};

int main()
{
    Menu menu;
}
