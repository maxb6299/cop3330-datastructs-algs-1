// header file for time class time.cpp

// for i/ostream overloads
#include <iostream>
using namespace std;

class Time
{
    // friend functions
    // input/output operators w/ format days~hh:mm:ss
    friend ostream& operator << (ostream& s, const Time& time);
    friend istream& operator >> (istream& s, Time& );

    
private:
    int days;
    int hours;
    int minutes;
    int seconds;

    // setter
    bool set(int d, int h, int m, int s);

    // converts time to seconds
    int toSeconds(int d, int h, int m, int s) const;
    

public:
    // constructors

    // default constructor
    Time();

    // constuctor w/ seconds parameter
    // also automatic type converter from int (sec) to Time
    Time (int s);

    // 4 parameter constructor (days, hrs, mins, sec)
    Time(int d, int h, int m, int s);


    // arithmetic operators
    
    // returns sum of two times
    Time operator + (const Time& otherTime) const;

    // returns difference of two times. If difference is negative, it will be zero
    Time operator - (const Time& otherTime) const;

    // returns the time multiplied by an integer
    Time operator * (const int n) const;


    // boolean operators
    bool operator < (const Time& otherTime) const;
    bool operator > (const Time& otherTime) const;
    bool operator <= (const Time& otherTime) const;
    bool operator >= (const Time& otherTime) const;
    bool operator == (const Time& otherTime) const;
    bool operator != (const Time& otherTime) const;
    

    // increment/decrement operators (changes by one second)
    // prefixes
    Time& operator ++ ();
    Time& operator -- ();
    // postfixes
    Time operator ++ (int);
    Time operator -- (int);

};
