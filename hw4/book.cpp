// book.cpp

// An object of type Book will store information about a single
// book.  The variable "type" stores the category of the book
// (one of the four items in the enumerated type Genre).

#include "book.h"

#include <iostream>
#include <iomanip>
#include <cstring>

Book::Book()
// default constructor, sets up blank book object
{
    strcpy(title, "");
    strcpy(author, "");
    price = 0;
    type = FICTION;
}

void Book::Set(const char* t, const char* a, Genre g, double p)
//  the Set function should allow incoming data to be received through
//  parameters and loaded into the member data of the object.  (i.e.
//  this function "sets" the state of the object to the data passed in).
//  The parameters t, a, g, and p represent the title, author, genre, 
//  and price of the book, respectively.
{
    strcpy(title, t);
    strcpy(author, a);
    type = g;
    price = p;
}

const char* Book::GetTitle() const
// returns the title stored in the object
{
    return title;
}
const char* Book::GetAuthor() const
// returns the author
{
    return author;
}
double Book::GetPrice() const
// returns the price
{
    return price;
}
Genre Book::GetGenre() const
// returns the genre
{
    return type;
}

void Book::Display() const
/* 
The member function Display() should print out a Book object on one line 
as follows, in an organized manner. (Monetary output should be in dollars
and cents notation, to two decimal places):
Title		              Author		  Genre		Price

Examples:
Programming for Dummies       Marvin Dipwart      Computer   $  24.95
Mutant Space Weasels          Bob Myers           Sci-Fi     $   5.95
*/ 
{
    using namespace std;
    
    // converts type to a string
    char genre[9];
    if (type == 0)
    {
        strcpy(genre, "Fiction");
    }
    else if (type == 1)
    {
        strcpy(genre, "Mystery");
    }
    else if (type == 2)
    {
        strcpy(genre, "Sci-Fi");
    }
    else if (type == 3)
    {
        strcpy(genre, "Computer");
    }
    
    
    cout << setprecision(2) << fixed; // so money formats properly

    cout << title << setw(31 - strlen(title) + strlen(author)) 
         << author << setw(21 - strlen(author) + strlen(genre)) 
         << genre << setw(12 - strlen(genre) + strlen("$")) 
         << '$' << setw(9) 
         << price << endl;
}
