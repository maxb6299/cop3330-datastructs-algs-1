// store.h
// header for store.cpp

#include "book.h"

class Store
{
    public:
    
    Store();
    // constructor

    ~Store();
    // destructor

    void addBook(const char* t, const char* a, const Genre g, const double p);
    // adds book to inventory list
    // increments bookcounter

    int findBook(const char* str, const int choice) const;
    // returns array item n (where first item = 0) that corresponds to title
    // if the title does not exist, returns -1

    Book getBook(const int n) const;
    // getter for book array
    // assumes valid input

    bool sellBook(const char* t);
    // removes book from inventory list and adds money to cash register
    // returns true/false whether inputted book is found and sold


    void display() const;
    // displays inventory list one line per book containing info as stated in
    // book.h 
    // also displays total num of books and current money in cash register
    
    void genreSummary(const Genre choice) const;
    // displays contents of the inventory list (like the display option) as 
    // well as total quantity and total costbased on genre selection:
    // FICTION (0), MYSTERY (1), SCIFI (2), or COMPUTER (3)

    void sort(const char choice);
    // sorts lexicograpghically based on selection: author ('A') or title ('T') 

    void setMoney(double m);
    // sets money in register to inputted value
    // is useful when store is constructed. had to be outside of constructor
    // for convienence of menu.cpp's design

    
    private:
    int bookCounter; // counts # of books in array
    int maxBooks; // maximum num of books in array
    Book* books; // unused slots in array should be 0 <= n <= 5
    double money; // money in the store

    void growArray();
    // calls resizeArray() if too full
    void shrinkArray();
    // calls resizeArray() if too empty

    void resizeArray(); 
    // resizes array

    void copyBook(Book& thisBook, const Book& otherBook);
    // copies from target book to other book
};