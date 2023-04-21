// MyInt class header

#include <iostream>

class MyInt
{
   // arithmetic operator overloads
   friend MyInt operator + (const MyInt& x, const MyInt& y);
   friend MyInt operator * (const MyInt& x, const MyInt& y);   
   
   // comparison operator overloads
   friend bool operator < (const MyInt& x, const MyInt& y);
   friend bool operator <= (const MyInt& x, const MyInt& y);
   friend bool operator > (const MyInt& x, const MyInt& y);
   friend bool operator >= (const MyInt& x, const MyInt& y);
   friend bool operator == (const MyInt& x, const MyInt& y);
   friend bool operator != (const MyInt& x, const MyInt& y);

   // input/output operator overloads
   friend std::ostream& operator << (std::ostream& o, const MyInt& x);
   friend std::istream& operator >> (std::istream& i, MyInt& x);

public:
   MyInt(const int n = 0); // default constructor (also accepts n as number)
   MyInt(const char n[]); // constructor that accepts C-string as input
   MyInt(const MyInt& otherInt); // copy constructor (makes deep copy of obj)
   ~MyInt(); // destructor
   MyInt operator = (const MyInt& otherInt); // assignment operator

   // increment
   MyInt& operator ++ (); // pre
   MyInt operator ++ (int); // post

private:
   int digitCounter; // num of digits in array 
                     // (unused digits must be 0 <= n <= 5)
   int maxDigits; // maximum number of digits possible in the array
   int* num; // dynamic array to store the actual number (each int is a digit)

   void resizeArray(); // resizes array if unused digits are not (0 < n < 5)
   void carryOver(); // carries over any digits > 10 for adding and multiplying
};
