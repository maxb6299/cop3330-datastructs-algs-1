// main.cpp -- Bob Myers
//
// Driver program to demonstrate the behavior of the MyInt class
// 
// You can add more tests of your own, or write other drivers to test your
// class

#include <iostream>
#include <cstring>
#include "myint.h"

using namespace std;




void addTest();
void multiplyTest();
void comparisonTest();
void ioTest(int trials);
void constructorTest();
void incrementTest(int trials);
void newPage(string s);

void bobTest(); MyInt Fibonnaci(MyInt num);

int main()
{
   addTest();
   multiplyTest();
   comparisonTest();
   ioTest(5);
   constructorTest();
   incrementTest(12345);
   bobTest();
}


// add test functions
void addOut(MyInt x, MyInt y)
{
   cout << "\n" << x << " + " << y << " = " << (x + y) << "\n";
}
void addTest()
{
   newPage("addition");

   MyInt ints[20] = {"1234567890", "9876543213", "123213213321312321312321", 
                     "31231321312", "1", 2, 321123, 0, 42134, "421323432",
                     "9342d992", 0, 54321, "54321", "3141592653589793234", 
                     "3141592653589793234", 892, "211"};

   for (int i = 0; i < 20; i+=2)
   {
      MyInt intOne = ints[i];
      MyInt intTwo = ints[i + 1];
      addOut(intOne, intTwo);
   }
}


// multiply test functions
void multiplyOut(MyInt x, MyInt y)
{
   cout << "\n" << x << " * " << y << " = " << (x * y) << "\n";
}
void multiplyTest()
{
   newPage("multiplication");

   MyInt ints[20] = {"1234567890", "9876543213", "123213213321312321312321", 
                     "31231321312", "1", 2, 321123, 0, 42134, "421323432",
                     "9342d992", 0, 54321, "54321", "3141592653589793234", 
                     "3141592653589793234", 892, "211"};

   for (int i = 0; i < 20; i+=2)
   {
      MyInt intOne = ints[i];
      MyInt intTwo = ints[i + 1];
      multiplyOut(intOne, intTwo);
   }
}


string toTruth(bool truth)
{
   if (truth)
   {
      return "TRUE";
   }
   return "FALSE";
}
void comparisonOut(MyInt x, MyInt y)
{
   cout << "\n" << x << " < " << y << " is " << toTruth(x < y) << "\n";
   cout << "\n" << x << " <= " << y << " is " << toTruth(x <= y) << "\n";
   cout << "\n" << x << " > " << y << " is " << toTruth(x > y) << "\n";
   cout << "\n" << x << " >= " << y << " is " << toTruth(x >= y) << "\n";
   cout << "\n" << x << " == " << y << " is " << toTruth(x == y) << "\n";
   cout << "\n" << x << " != " << y << " is " << toTruth(x != y) << "\n";
}
void comparisonTest()
{
   newPage("comparison operators");

   MyInt ints[20] = {"1234567890", "9876543213", "123213213321312321312321", 
                     "31231321312", "1", 2, 321123, 0, 42134, "421323432",
                     "9342d992", 0, 54321, "54321", "3141592653589793234", 
                     "3141592653589793234", 892, "211"};

   for (int i = 0; i < 20; i+=2)
   {
      MyInt intOne = ints[i];
      MyInt intTwo = ints[i + 1];
      comparisonOut(intOne, intTwo);
   }
}


void ioTest(int trials)
{
   newPage("ioTest");
   for (int i = 0; i < trials; i++)
   {
      MyInt n;
      cout << "Pick a number: ";
      cin >> n;
      cout << "Number is: " << n << "\n";
   }
}


// constructor test functions
void constructorOut(int i)
{
   MyInt MyInti(i);
   std::cout << "MyInt(" << i << ")=" << MyInti << "\n";
}
void constructorOut(char i[])
{
   MyInt MyInti(i);
   std::cout << "MyInt(" << i << ")=" << MyInti << "\n";
}
void constructorOut(MyInt i)
{
   MyInt MyInti(i);
   std::cout << "MyInt(" << i << ")=" << MyInti << "\n";
}
void constructorTest()
{
   newPage("constructors");

   std::cout << " *** Testing ints *** \n";
   constructorOut(67);
   constructorOut(17);
   constructorOut(47);
   constructorOut(1234567);
   constructorOut(531303);
   constructorOut(111587812);
   constructorOut(-21312412);
   constructorOut(-1);
   constructorOut(0);

   std::cout << " *** Testing cstrings *** \n";
   constructorOut("67");
   constructorOut("17");
   constructorOut("47");
   constructorOut("1234567");
   constructorOut("531303");
   constructorOut("111587812");
   constructorOut("1");
   constructorOut("21adsas312412");
   constructorOut("11111a");
   constructorOut("0");
   constructorOut("1234A67");
   constructorOut("2312Hasdas1123123");
   constructorOut("1w234567");
   constructorOut("");


   std::cout << " *** Testing MyInts *** \n";
   
   MyInt a(67), b(17), c(47), d(1234567), e(43412321), 
   f("213123321312312312321321312312"), g(-1), h("43213123h21312jh312"), i(0);
   constructorOut(a);
   constructorOut(b);
   constructorOut(c);
   constructorOut(d);
   constructorOut(e);
   constructorOut(f);
   constructorOut(g);
   constructorOut(h);
   constructorOut(i);

   newPage("Assignment Operator");
   MyInt ints[10] = {321312, "1231223123123123", a, 3213123, "372188ss13", 
                     "23178276", 831281, 213, 0, -12};
   for (int i = 0; i < 10; i++)
   {
      MyInt newInt = ints[i];
      constructorOut(newInt);
   }
   std::cout <<  " *** Assignment Operator (extended) *** \n";
   MyInt a1 = "12";
   MyInt a2 = "21";
   MyInt a3 = "432423423432";
   MyInt a4 = 321321;
   MyInt a5 = a1 + 32;
   MyInt a6 = a2 + 111;
   std::cout << "MyInt(" << "12" << ")=" << a1 << "\n";
   std::cout << "MyInt(" << "21" << ")=" << a2 << "\n";
   std::cout << "MyInt(" << "432423423432" << ")=" << a3 << "\n";
   std::cout << "MyInt(" << "321321" << ")=" << a4 << "\n";
   std::cout << "MyInt(" << "44" << ")=" << a5 << "\n";
   std::cout << "MyInt(" << "122" << ")=" << a6 << "\n";
   a1 = a3;
   std::cout << "MyInt(" << "432423423432" << ")=" << a1 << "\n";
   a1 = a4;
   std::cout << "MyInt(" << "321321" << ")=" << a1 << "\n";

}


// increment test function
void incrementTest(int trials)
{
   newPage("incrementing");
   
   MyInt i1, i2;
   for (int i = 0; i < trials; i++)
   {
      cout << "i++: " << i1++
           << "; ++i: "<< ++i2 << "\n";
   }
}

void newPage(string s)
{
   char i;
   cout << "Press any key to continue to the next test\n";
   cin >> i;
   cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
        << " *** Now testing " << s << " *** \n\n";
}












void bobTest()
{
   // demonstrate behavior of the two constructors and the << overload

  MyInt x(12345), y("98765432101234567809"), r1(-1000), r2 = "14H67", r3;
  char answer;
  cout << "Initial values: \nx = " << x << "\ny = " << y
       << "\nr1 = " << r1 << "\nr2 = " << r2 << "\nr3 = " << r3 << "\n\n";

  // demonstrate >> overload

  cout << "Enter first number: ";
  cin >> x;
  cout << "Enter second number: ";
  cin >> y;

  cout << "You entered:\n";
  cout << "  x = " << x << '\n';
  cout << "  y = " << y << '\n';

  // demonstrate assignment =
  cout << "Assigning r1 = y ...\n";
  r1 = y;
  cout << "  r1 = " << r1 << '\n';

  // demonstrate comparison overloads
  if (x < y)	cout << "(x < y) is TRUE\n";
  if (x > y)	cout << "(x > y) is TRUE\n";
  if (x <= y)	cout << "(x <= y) is TRUE\n";
  if (x >= y)	cout << "(x >= y) is TRUE\n";
  if (x == y)	cout << "(x == y) is TRUE\n";
  if (x != y)	cout << "(x != y) is TRUE\n";

  // demonstrating + and * overloads
  r1 = x + y;
  cout << "The sum (x + y) = " << r1 << '\n';
  r2 = x * y;
  cout << "The product (x * y) = " << r2 << "\n\n";
  cout << "The sum (x + 12345) = " << x + 12345 << '\n';
  cout << "The product (y * 98765) = " << y * 98765 << '\n';

  // create Fibonacci numbers (stored as MyInts) using +
  cout << "\nAssuming that the Fibonnaci sequence begins 1,1,2,3,5,8,13..."
       << "\n\nThe 10th Fibonnaci number   = " << Fibonnaci(10)
       << "\n\nThe 100th Fibonnaci number  = " << Fibonnaci(100)
       << "\n\nThe 1000th Fibonnaci number = " << Fibonnaci(1000)
       << "\n\nThe 2000th Fibonnaci number = " << Fibonnaci(2000)
       << "\n\n";
}

MyInt Fibonnaci(MyInt num)
{
   MyInt n1 = 1, n2 = 1, n3;
   MyInt i = 2;
   while (i < num)
   {
	n3 = n1 + n2;
	n1 = n2;
	n2 = n3;
	i++;
   }
   return n2;
}
