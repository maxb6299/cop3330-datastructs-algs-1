// time class

#include <iostream>
#include "time.h"
using namespace std;

// constructors

// default constructor
Time::Time()
{
    set (0, 0, 0, 0);
}

// automatic type converter from int (sec) to Time
Time::Time(int s)
{
    set (0, 0, 0, s);
}

// 4 parameter constructor (days, hrs, mins, sec)
Time::Time(int d, int h, int m, int s)
{
    set(d, h, m, s);
}


// arithmetic operators
    
// adds one time to another
Time Time::operator + (const Time& otherTime) const
{
    int newDays = days + otherTime.days;
    int newHours = hours + otherTime.hours;
    int newMinutes = minutes + otherTime.minutes;
    int newSeconds = seconds + otherTime.seconds;

    Time newTime(newDays, newHours, newMinutes, newSeconds);

    return newTime;
}

// subtracts one time from another. If a time is negative, sets to 0
Time Time::operator - (const Time& otherTime) const
{
    int newDays = days - otherTime.days;
    int newHours = hours - otherTime.hours;
    int newMinutes = minutes - otherTime.minutes;
    int newSeconds = seconds - otherTime.seconds;

    // so that say 1~00:00:00 - 0~10:00:00 (which is 1~-14:00:00) 
    // won't result to 0 when constructed, as the actual value is not negative
    int newTotalSeconds = toSeconds(newDays, newHours, newMinutes, newSeconds); 

    Time newTime(newTotalSeconds);

    return newTime;
}

// multiplies the time by an integer
Time Time::operator * (const int n) const
{
    int newDays = days * n;
    int newHours = hours * n;
    int newMinutes = minutes * n;
    int newSeconds = seconds * n;
    
    
    Time newTime(newDays, newHours, newMinutes, newSeconds);

    return newTime;
}


// boolean operators
bool Time::operator < (const Time& otherTime) const
{
    int thisSeconds = toSeconds(days, hours, minutes, seconds);
    int otherSeconds = toSeconds(otherTime.days, otherTime.hours, 
                                 otherTime.minutes, otherTime.seconds);

    return (thisSeconds < otherSeconds);
}
bool Time::operator > (const Time& otherTime) const
{
    int thisSeconds = toSeconds(days, hours, minutes, seconds);
    int otherSeconds = toSeconds(otherTime.days, otherTime.hours, 
                                 otherTime.minutes, otherTime.seconds);

    return (thisSeconds > otherSeconds);
}
bool Time::operator <= (const Time& otherTime) const
{
    int thisSeconds = toSeconds(days, hours, minutes, seconds);
    int otherSeconds = toSeconds(otherTime.days, otherTime.hours, 
                                 otherTime.minutes, otherTime.seconds);
                                 
    return (thisSeconds <= otherSeconds);
}
bool Time::operator >= (const Time& otherTime) const
{
    int thisSeconds = toSeconds(days, hours, minutes, seconds);
    int otherSeconds = toSeconds(otherTime.days, otherTime.hours, 
                                 otherTime.minutes, otherTime.seconds);

    return (thisSeconds >= otherSeconds);
}
bool Time::operator == (const Time& otherTime) const
{
    int thisSeconds = toSeconds(days, hours, minutes, seconds);
    int otherSeconds = toSeconds(otherTime.days, otherTime.hours, 
                                 otherTime.minutes, otherTime.seconds);

    return (thisSeconds == otherSeconds);
}
bool Time::operator != (const Time& otherTime) const
{
    int thisSeconds = toSeconds(days, hours, minutes, seconds);
    int otherSeconds = toSeconds(otherTime.days, otherTime.hours, 
                                 otherTime.minutes, otherTime.seconds);

    return (thisSeconds != otherSeconds);
}
    

// increment/decrement operators (changes by one second)
// prefixes
Time& Time::operator ++ ()
{
    set(days, hours, minutes, seconds + 1);
    return *this;
}
Time& Time::operator -- ()
{
    // converts to pure seconds because 0~00:01:00 being decremented otherwise would be 
    // set(0, 00, 01, -1) which would default to setting time to all 0
    int newSeconds = toSeconds(days, hours, minutes, seconds) - 1;
    set(0, 0, 0, newSeconds);
   
    return *this;
}
// postfixes
Time Time::operator ++ (int)
{
    Time temp = *this; // saves to return this value as it is postfix

    set(days, hours, minutes, seconds + 1);
    
    return temp;
}
Time Time::operator -- (int)
{
    Time temp = *this; // saves to return this value as it is postfix

    // converts to pure seconds because 0~00:01:00 being decremented otherwise would be 
    // set(0, 00, 01, -1) which would default to setting time to all 0
    int newSeconds = toSeconds(days, hours, minutes, seconds) - 1;
    set(0, 0, 0, newSeconds);
    
    return temp;
}



// input/output operators w/ format days~hh:mm:ss
ostream& operator << (ostream& s, const Time& time)
{
    s << time.days << "~";

    // if statments add a 0 in front if the numbers are under double digits
    // ex. 1:00:00 --> 01:00:00
    if (time.hours < 10)
    {
        s << "0";
    }
    s << time.hours << ":";

    if (time.minutes < 10)
    {
        s << "0";
    }
    s << time.minutes << ":";

    if (time.seconds < 10)
    {
        s << "0";
    }
    s << time.seconds;

    
    return s;
}

// accepts format days~hh:mm:ss
istream& operator >> (istream& s, Time& time)
{
    char symbol;
    int days, hours, minutes, seconds;

    s >> days >> symbol >> hours >> symbol >> minutes >> symbol >> seconds;

    // will automatically error check if invalid input
    time.set(days, hours, minutes, seconds);
    
    return s;
}



// private setter function
// returns false if negative input
bool Time::set(int d, int h, int m, int s)
{
    // if any of the inputted values are negative, sets time to 0
    if (d < 0 || h < 0 || m < 0 || s < 0)
    {
        days = 0;
        hours = 0;
        minutes = 0;
        seconds = 0;

        return false;
    }

    // if any of the values for hrs, mins, sec is out of range (23 or 59)
    // the program will carry over. ex. 62sec --> 1min 2sec
    minutes = m + s / 60; // floored division due to two ints
    seconds = s % 60;

    hours = h + minutes / 60; // floored division due to two ints
    minutes = minutes % 60;
    
    days = d + hours / 24; // floored division due to two ints
    hours = hours % 24;

    return true;    
}

// private function converts time to seconds (for easy booleans)
int Time::toSeconds(int d, int h, int m, int s) const
{
    h = h + d * 24;
    m = m + h * 60;
    s = s + m * 60;

    return s;
}
