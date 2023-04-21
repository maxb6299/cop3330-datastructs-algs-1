// store.cpp

#include "store.h"

#include <iostream>
#include <iomanip>
#include <cstring>

Store::Store()
// constructor
{
    bookCounter = 0;
    maxBooks = 5;
    books = new Book[maxBooks];
    money = 0;
}

Store::~Store()
// destructor
{
    delete [] books; // deallocates memory
}

void Store::addBook(const char* t, const char* a, 
                    const Genre g, const double p)
// adds book to inventory list
// increments bookcounter
{    
    growArray(); // grows array if necessary
    books[bookCounter++].Set(t, a, g, p);
}

int Store::findBook(const char* str, const int choice) const
// calls display function for any matching text (based on choice)
// choice = 0 means searches for title for sell func and returns i
// choice = 1 means search for both title and author and displays
// if the title does not exist, returns -1
{
    int isFound = -1; // return value for author search

    if (choice == 0) // searches for just the title and displays it
    {
        for (int i = 0; i < bookCounter; i++)
        {
            if (strcmp(str, books[i].GetTitle()) == 0) 
            // finds equal title/author
            {
                return i;
            }
        }
    }

    else if (choice == 1) // searches for both title and author. used in sell func
    {
        for (int i = 0; i < bookCounter; i++)
        {
            if (strcmp(str, books[i].GetTitle()) == 0)  
            // finds equal title
            {
                std::cout << "Book Found:\n";
                books[i].Display();
                std::cout << "\n";
                return i;
            }
            
            if (strcmp(str, books[i].GetAuthor()) == 0) 
            // finds any matching authors and displays books
            {
                books[i].Display();
                std::cout << "\n";
                isFound = 1;
            }
        }
        
    }

    return isFound;
}

Book Store::getBook(const int n) const
// getter for book array
// assumes valid input
{
    return books[n];
}

bool Store::sellBook(const char* t)
// removes book from inventory list and adds money to cash register
// returns true/false whether inputted book is found and sold
{
    int bookNumber = findBook(t, 0);
    
    if (bookNumber == -1) // if inputted book is not found returns false
    {
        return false;
    }
            
    money += books[bookNumber].GetPrice(); // adds money to cash register


    
    for (int i = bookNumber; i < (bookCounter - 1); i++) 
    // removes book and shifts array left by one slot where the book is
    // being sold
    {
        books[i] = books[i + 1];
    }

    bookCounter--;
    shrinkArray(); // shrinks array if necessary
    
    return true;
}


void Store::display() const
// displays inventory list one line per book containing info as stated in
// book.h
// also displays total num of books and current money in cash register
{
    using namespace std;
    
    // in case inventory is empty
    if (bookCounter == 0)
    {
        cout << "\nNo books currently in inventory\n";
    }
    else
    {
        cout << "\n**Title**                      **Author**           "
             << "**Genre**   **Price**\n\n";
        
        for (int i = 0; i < bookCounter; i++)
        {
            books[i].Display();
        }
    }
    
    

    cout << endl << "Number of books = " << bookCounter << "\n";
    cout << setprecision(2) << fixed; // formats money
    cout << "Money in register = $ " << money << "\n\n";
}

void Store::genreSummary(const Genre choice) const
// displays contents of the inventory list (like the display option) as 
// well as total quantity and total cost based on genre selection:
// FICTION (0), MYSTERY (1), SCIFI (2), or COMPUTER (3)
{
    using namespace std;
    int totalBooks = 0;
    double totalPrice = 0;

    for (int i = 0; i < bookCounter; i++) // finds every book in selected genre
    {
        if (books[i].GetGenre() == choice)
        {
            books[i].Display();
            totalBooks++; // total num of books in that genre
            totalPrice += books[i].GetPrice(); // total cost of that genre
        }
    }

    cout << endl << "Total books in this genre = " << totalBooks << "\n";
    cout << setprecision(2) << fixed; // formats money
    cout << "Total price of books in this genre = $" << totalPrice << "\n\n";
}

void Store::sort(const char choice)
// sorts lexicograpghically based on selection: author ('A') or title ('T') 
{
    // bubble sort
    if (choice == 'A') // by author
    {
        for (int i = 0; i < bookCounter; i++)
        {
            for (int j = 0; j < (bookCounter - i - 1); j++)
            {
                if (strcmp(books[j].GetAuthor(), books[j + 1].GetAuthor()) > 0) 
                // positive means 2nd parameter comes first
                {
                    Book temp;
                    // swaps the two books
                    copyBook(temp, books[j]);
                    copyBook(books[j], books[j + 1]);
                    copyBook(books[j + 1], temp);
                }
            }
        }
    }
    else if (choice == 'T') // by title
    {
        for (int i = 0; i < bookCounter; i++)
        {
            for (int j = 0; j < (bookCounter - i - 1); j++)
            {
                if (strcmp(books[j].GetTitle(), books[j + 1].GetTitle()) > 0) 
                // positive means 2nd parameter comes first
                {
                    Book temp;
                    // swaps the two books
                    copyBook(temp, books[j]);
                    copyBook(books[j], books[j + 1]);
                    copyBook(books[j + 1], temp);
                }
            }
        }
    }
    std::cout << "\nSort complete\n\n";
}

void Store::setMoney(double m)
// sets money in register to inputted value
// is useful when store is constructed. had to be outside of constructor
// for convienence of menu.cpp's design
{
    money = m;
}


void Store::growArray()
// calls resizeArray() if too full
{
    if ((maxBooks - bookCounter) <= 0)
    {
        maxBooks += 5;
        resizeArray();
    }
}

void Store::shrinkArray()
// calls resizeArray() if too over five empty slots
{
    if ((maxBooks - bookCounter) > 5)
    {
        maxBooks -= 5;
        resizeArray();
    }
}

void Store::resizeArray()
// resizes array
{
    Book* newBooks = new Book[maxBooks]; // initializes new array

    for (int i = 0; i < bookCounter; i++) // copies over data
    {
        copyBook(newBooks[i], books[i]);
    }

    delete [] books; // deletes old data

    books = newBooks; // sets old array to point to new array

    std::cout << "** Array being resized to " << maxBooks << " allocated slots\n\n";
}


void Store::copyBook(Book& targetBook, const Book& otherBook) 
// copies from target book to other book
{    
    targetBook.Set(otherBook.GetTitle(), otherBook.GetAuthor(), 
                    otherBook.GetGenre(), otherBook.GetPrice());
}