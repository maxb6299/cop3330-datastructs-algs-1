#include <iostream>
#include "time.h"
using namespace std;


void compareString(string i, string f, string e)
{
    cout << "\n\n-------------------------\n\n\n"
         << "Info:     " << i << "\n"
         << f << "\n"
         << "Expected: " << e << "\n"
         << "Actual:   ";
}


int main()
{
    string i, f, e;

    // testing constructors
    cout << "TESTING CONSTRUCTORS\n\n\n";

    i = "default constructor";
    f = "Time t0;";
    e = "0~00:00:00";
    compareString(i, f, e);
    Time t0;
    cout << t0;

    i = "1 parameter construction";
    f = "Time t1(1234);";
    e = "0~00:20:34";
    compareString(i, f, e);
    Time t1(1234);
    cout << t1;

    i = "1 parameter construction";
    f = "Time t1(-12);";
    e = "0~00:00:00";
    compareString(i, f, e);
    Time t2(-12);
    cout << t2;

    i = "constructor int conversion";
    f = "t1 = 4321;";
    e = "0~01:12:01";
    compareString(i, f, e);
    t1 = 4321;
    cout << t1;

    i = "constructor int conversion";
    f = "t1 = 1234;";
    e = "0~00:20:34";
    compareString(i, f, e);
    t1 = 1234;
    cout << t1;

    i = "4 parameter construction";
    f = "compareString(i, f, e);";
    e = "1~03:05:07";
    compareString(i, f, e);
    Time t3(1, 3, 5, 7);
    cout << t3;

    i = "4 parameter construction";
    f = "Time t4(2, -4, 5, 7);";
    e = "0~00:00:00";
    compareString(i, f, e);
    Time t4(2, -4, 5, 7);
    cout << t4;
    
    i = "4 parameter construction";
    f = "Time t5(2, 25, 4, 62);";
    e = "3~01:05:02";
    compareString(i, f, e);
    Time t5(2, 25, 4, 62);
    cout << t5;
    

    // testing extraction operators
    cout << "\nTESTING EXTRACTION OPERATOR (>>)\n\n\n";
    
    i = "please input expected";
    f = "cin >> t0;";
    e = "2~04:07:28";
    compareString(i, f, e);
    cin >> t0;
    cout << t0;

    i = "please input expected";
    f = "cin >> t1";
    e = "5~08:19:02";
    compareString(i, f, e);
    cin >> t1;
    cout << t1;

    i = "please input expected";
    f = "cin >> t2";
    e = "5~12:15:57";
    compareString(i, f, e);
    cin >> t2;
    cout << t2;


    i = "please input expected";
    f = "cin >> t3";
    e = "2~16:51:05";
    compareString(i, f, e);
    cin >> t3;
    cout << t3;



    // testing arithmetic operators
    cout << "\nTESTING ARITHMETIC OPERATORS\n\n\n";


    i = "2~04:07:28 + 5~08:19:02";
    f = "Time t10 = t0 + t1;";
    e = "7~12:26:30";
    compareString(i, f, e);
    Time t10 = t0 + t1;
    cout << t10;

    i = "2~04:07:28 - 5~08:19:02";
    f = "Time t11 = t0 - t1;";
    e = "0~00:00:00";
    compareString(i, f, e);
    Time t11 = t0 - t1;
    cout << t0 - t1;

    i = "5~12:15:57 + 2~16:51:05";
    f = "Time t12 = t2 + t3;";
    e = "8~05:07:02";
    compareString(i, f, e);
    Time t12 = t2 + t3;
    cout << t2 + t3;

    i = "5~12:15:57 - 2~16:51:05";
    f = "Time t12 = t2 - t3;";
    e = "2~19:24:52";
    compareString(i, f, e);
    Time t13 = t2 - t3;
    cout << t2 - t3;

    i = "2~07:10:32 * 2";
    f = "cout << t15 * 2;";
    e = "4~14:21:04";
    compareString(i, f, e);
    Time t15(2,7,10,32);
    cout << t15 * 2;

    i = "2~07:10:32 * 5";
    f = "cout << t16 * 5;";
    e = "11~11:52:40";
    compareString(i, f, e);
    Time t16(2,7,10,32);
    cout << t16 * 5;
    

    // testing boolean operators
    cout << "\nTESTING BOOLEAN OPERATORS\n";
    
    i = "1220 < 4990";
    f = "";
    e = "1";
    compareString(i, f, e);
    Time b1(1220);
    Time b2(4990);
    cout << (b1 < b2) << endl;

    i = "1220 <= 4990";
    f = "";
    e = "1";
    compareString(i, f, e);
    cout << (b1 <= b2) << endl;

    i = "1220 > 4990";
    f = "";
    e = "0";
    compareString(i, f, e);
    cout << (b1 > b2) << endl;

    i = "1220 >= 4990";
    f = "";
    e = "0";
    compareString(i, f, e);
    cout << (b1 >= b2) << endl;

    i = "1220 == 4990";
    f = "";
    e = "0";
    compareString(i, f, e);
    cout << (b1 == b2) << endl;

    i = "1220 != 4990";
    f = "";
    e = "1";
    compareString(i, f, e);
    cout << (b1 != b2) << endl;

    i = "(12, 4, 1, 343) < (12, 10, 0, 1)";
    f = "";
    e = "1";
    compareString(i, f, e);
    Time b3(12, 4, 1, 343);
    Time b4(12, 10, 0, 1);
    cout << (b3 < b4);

    i = "(12, 4, 1, 343) > (12, 10, 0, 1)";
    f = "";
    e = "0";
    compareString(i, f, e);
    cout << (b3 > b4);

    i = "(12, 4, 1, 343) <= (12, 10, 0, 1)";
    f = "";
    e = "1";
    compareString(i, f, e);
    cout << (b3 <= b4);

    i = "(12, 4, 1, 343) >= (12, 10, 0, 1)";
    f = "";
    e = "0";
    compareString(i, f, e);
    cout << (b3 >= b4);

    i = "(12, 4, 1, 343) == (12, 10, 0, 1)";
    f = "";
    e = "0";
    compareString(i, f, e);
    cout << (b3 == b4);

    i = "(12, 4, 1, 343) != (12, 10, 0, 1)";
    f = "";
    e = "1";
    compareString(i, f, e);
    cout << (b3 != b4);

    i = "(32, 5, 1 75) == (32, 5, 2, 15)";
    f = "";
    e = "1";
    compareString(i, f, e);
    Time c1(32, 5, 1, 75);
    Time c2(32, 5, 2, 15);
    cout << (c1 == c2) << endl;

    i = "(32, 5, 1 75) != (32, 5, 2, 15)";
    f = "";
    e = "0";
    compareString(i, f, e);
    cout << (c1 != c2) << endl;

    i = "(32, 5, 1 75) >= (32, 5, 2, 15)";
    f = "";
    e = "1";
    compareString(i, f, e);
    cout << (c1 >= c2) << endl;

    i = "(32, 5, 1 75) <= (32, 5, 2, 15)";
    f = "";
    e = "1";
    compareString(i, f, e);
    cout << (c1 <= c2) << endl;


    // testing increment and decrement
    cout << "\nTESTING INCREMENT AND DECREMENT" << endl;


    i = "i1(2, 04, 07, 58)";
    f = "i1++";
    e = "2~04:07:58";
    compareString(i, f, e);
    Time i1(2, 04, 07, 58);
    cout << i1++ << endl;

    i = "i1(2, 04, 07, 59)";
    f = "++i1";
    e = "2~04:08:00";
    compareString(i, f, e);
    cout << ++i1 << endl;

    i = "i2(5, 8, 19, 1)";
    f = "i2--";
    e = "5~08:19:01";
    compareString(i, f, e);
    Time i2(5, 8, 19, 1);
    cout << i2-- << endl;

    i = "i2(5, 8, 19, 0)";
    f = "--i2";
    e = "5~08:18:59";
    compareString(i, f, e);
    cout << --i2 << endl;

    return 0;
}
