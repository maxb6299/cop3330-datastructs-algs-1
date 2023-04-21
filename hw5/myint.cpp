// MyInt Class
// stores a dynamic array where each index is a decimal place
// index i = 0 would be the ones place, i = 1 would be tenths, 2 is hundredths

#include <cstring>
#include "myint.h"


int C2I(char c)
// converts character into integer (returns -1 for error)
// from Bob Myers at https://www.cs.fsu.edu/~myers/cop3330/hw/hw05.html
{
   if (c < '0' || c > '9')	return -1;	// error
   return (c - '0');				// success
}

char I2C(int x)
// converts single digit integer into character (returns '\0' for error)
// from Bob Myers at https://www.cs.fsu.edu/~myers/cop3330/hw/hw05.html
{
   if (x < 0 || x > 9)		return '\0';	// error
   return (static_cast<char>(x) + '0'); 	// success
}


// arithmetic operator overloads
MyInt operator + (const MyInt& x, const MyInt& y)
{
   MyInt newInt;
   const MyInt* addend;

   // sets newInt to the larger addend and MyInt* addend to the smaller addend
   if (x > y)
   {
      newInt = x;
      addend = &y;
   }
   else
   {
      newInt = y;
      addend = &x;
   }
   
   for (int i = 0; i < newInt.digitCounter; i++)
   {     
      if ((addend->digitCounter - 1) >= i) // adds ints if addend isn't done 
                                           // being added to newInt
      {
         newInt.num[i] += 
         addend->num[i];
      }
   }   

   newInt.carryOver();
   return newInt;
}

MyInt operator * (const MyInt& x, const MyInt& y)
{
   if (x == 0 || y == 0) // in case either equal zero
   {
      return MyInt(0);
   }
   
   MyInt newInt;
   newInt.digitCounter = 0;
   const MyInt* multipleL; // larger multiple
   const MyInt* multipleS; // smaller multiple

   // sets pointers to the larger and smaller multiples (simplifies for loop)
   if (x > y)
   {
      multipleL = &x;
      multipleS = &y;
   }
   else
   {
      multipleL = &y;
      multipleS = &x;
   }

   for (int i = 0; i < multipleS->digitCounter; i++)
   {
      MyInt tempInt;
      tempInt.digitCounter = 0;
      for (int j = 0; j < multipleL->digitCounter; j++)
      {
         tempInt.digitCounter++;
         tempInt.resizeArray();
         tempInt.num[j] = multipleL->num[j] * multipleS->num[i];
      }
      tempInt.carryOver();
      
      // multiplies tempInt by 10^i and sets to tempIntMult
      MyInt tempIntMult = tempInt;
      tempIntMult.digitCounter = tempInt.digitCounter + i;
      tempIntMult.resizeArray();
      for (int j = 0; j < i; j++) // sets first i values to 0
      {
         tempIntMult.num[j] = 0;
      }
      for (int j = 0; j < tempInt.digitCounter; j++) // copies remaining values
                                                     // after the initial 0's
      {
         tempIntMult.num[j + i] = tempInt.num[j];
      }

      newInt = newInt + tempIntMult; // adds value * 10^i to product
   }

   return newInt;
}

// comparison operator overloads
bool operator < (const MyInt& x, const MyInt& y)
{
   // doing by num of digits means more efficiency
   if (x.digitCounter < y.digitCounter)
   {
      return true;
   }
   else if (x.digitCounter > y.digitCounter)
   {
      return false;
   }

   // otherwise for each digit from largest to smallest it must be compared
   for (int i = (x.digitCounter - 1); i >= 0; i--)
   {
      if (x.num[i] < y.num[i])
      {
         return true;
      }
      else if (x.num[i] > y.num[i])
      {
         return false;
      }
   }

   return false;
}
bool operator <= (const MyInt& x, const MyInt& y)
{
   return (x < y) || (x == y);
}
bool operator > (const MyInt& x, const MyInt& y)
{
   return !(x <= y);
}
bool operator >= (const MyInt& x, const MyInt& y)
{
   return !(x < y);
}
bool operator == (const MyInt& x, const MyInt& y)
{
   // doing by num of digits means more efficiency
   if (x.digitCounter != y.digitCounter)
   {
      return false;
   }

   // otherwise must be checked for each digit
   for (int i = 0; i < x.digitCounter; i++)
   {
      if (x.num[i] != y.num[i])
      {
         return false;
      }
   }

   return true;
}
bool operator != (const MyInt& x, const MyInt& y)
{
   return !(x == y);
}

// input/output operator overloads
std::ostream& operator << (std::ostream& o, const MyInt& x)
{
   for (int i = x.digitCounter - 1; i >= 0; i--)
   {
      o << I2C(x.num[i]);
   }
   return o;
}
std::istream& operator >> (std::istream& i, MyInt& x)
{
   while (isspace(i.peek())) // ignores whitespace 
   {
      i.get();
   }
   
   MyInt temp(0);
   temp.digitCounter = 0; // so its properly empty

   int counter = 0;

   while (true) // loops until istream reaches a non-number
   {
      if (C2I(i.peek()) == -1) // if istream is a non-number
      {
         break;
      }

      temp.resizeArray();
      temp.num[counter++] = C2I(i.get());
      temp.digitCounter++; // since num of digits increases
   }

   x = temp;
   for (int i = 0; i < temp.digitCounter; i++)
   {
      x.num[temp.digitCounter - i - 1] = temp.num[i];
   }

   return i;
}

// constructors
MyInt::MyInt(const int n) 
// default constructor (also accepts n as number)
{
   int integer = n;
   digitCounter = 0;
   
   if (n <= 0) // sets MyInt to 0
   {
      digitCounter = 1;
      maxDigits = digitCounter + 5;
      num = new int[maxDigits];
      num[0] = 0;
      return;
   }
   
   int number = 1;
   while (integer / number != 0) // counts number of digits
   {
      number *= 10;
      digitCounter++;
   }

   maxDigits = digitCounter + 5;
   num = new int[maxDigits];
   
   int divisor = 10; // divisor = 10 ^ (i + 1)
   for (int i = 0; i < digitCounter; i++)
   // inserts num into each digit
   // ex. n = 1234 and i = 2 
   // n would be then 1200
   // num[i] = [(1200 % [10 ^ (i + 1)]) / ((10 ^ [i + 1]) / 10)]
   // = (1200 % 1000 / (1000 / 10))
   // = 200 / 100
   {
      num[i] = (integer % divisor) / (divisor / 10);
      divisor *= 10; 
   }
}
MyInt::MyInt(const char n[]) 
// constructor that accepts C-string as input
{
   if (strlen(n) == 0) // if string is empty, set MyInt to 0
   {
      digitCounter = 1;
      maxDigits = digitCounter + 5;
      num = new int[maxDigits];
      num[0] = 0;
      return;
   }
   for (int i = 0; i < strlen(n); i++)
   {
      if (C2I(n[i]) == -1) // if input contains a non number, sets MyInt to 0
      {
         digitCounter = 1;
         maxDigits = digitCounter + 5;
         num = new int[maxDigits];
         num[0] = 0;
         return;
      }
   }
   
   digitCounter = strlen(n);
   maxDigits = digitCounter + 5;
   num = new int[maxDigits];

   for (int i = 0; i < digitCounter; i++)
   {  
      num[digitCounter - i - 1] = C2I(n[i]);
   }
}
MyInt::MyInt(const MyInt& otherInt) 
// copy constructor (makes deep copy of obj)
{
   digitCounter = otherInt.digitCounter;
   maxDigits = otherInt.maxDigits;
   num = new int[maxDigits];

   for (int i = 0; i < digitCounter; i++) // copies array
   {
      num[i] = otherInt.num[i];
   }
}
MyInt::~MyInt() 
// destructor
{
   delete [] num;
}
MyInt MyInt::operator = (const MyInt& otherInt) 
// assignment operator (makes deep copy of obj)
{
   delete [] num; // deallocates memory

   // copies variables and initializes dynamic array
   digitCounter = otherInt.digitCounter;
   maxDigits = otherInt.maxDigits;
   num = new int[maxDigits];

   for (int i = 0; i < digitCounter; i++) // copies array
   {
      num[i] = otherInt.num[i];
   }

   return *this;
}


// increment operators
MyInt& MyInt::operator ++ () 
// pre
{
   *this = *this + 1;
   return *this;
}
MyInt MyInt::operator ++ (int) 
// post
{
   MyInt temp = *this;
   ++(*this);
   return temp;
}


void MyInt::resizeArray() 
// resizes array if unused digits are not within (0 < n <= 5)
{
   int n = maxDigits - digitCounter;
   if (!(0 < n && n <= 5))
   {
      maxDigits = digitCounter + 4;
      int* newNum = new int[maxDigits]; // creates new array

      for (int i = 0; i < digitCounter; i++) // copies data over
      {
         newNum[i] = num[i];
      }

      delete [] num; // deallocates old data
      num = newNum; // num now points to new data
   }
}

void MyInt::carryOver()
// carries over any digits > 10 for adding and multiplying
{
   
   for (int i = 0; i < digitCounter; i++)
   {
      if (num[i] > 9) // carries to next place(s)
      {
         if (digitCounter - 1 == i) // increases digit count if num is 
                                    // carried to a new digit
         {
            resizeArray();
            digitCounter++;

            int numCarry = num[i] / 10;
            num[i + 1] = numCarry; // sets it to next decimal place
            num[i] -= (numCarry * 10); // subtracts from current place
            
            carryOver(); // recursively loops in case new digit needs to
                         // be carried over
         } 
         else
         {
            int numCarry = num[i] / 10;
            num[i + 1] += numCarry; // adds to next decimal place
            num[i] -= (numCarry * 10); // subtracts from current place
         }
      }
   }
}
