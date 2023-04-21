#include <iostream>
#include <iomanip>
#include <cmath>

#include "diamond.h"

using std::cout;

// constructor
Diamond::Diamond(int sizeC, char borderC, char fillC)
{
    // if inputted size < 1, sets to 1, if size > 39, sets to 39
    // otherwise sets to inputted size
    if (sizeC < 1)
    {
        size = 1;
    }
    else if (sizeC > 39)
    {
        size = 39;
    }
    else 
    {
        size = sizeC;
    }
        
    border = borderC;
    fill = fillC;
}

// getters
int Diamond::GetSize()
{
    return size;
}

int Diamond::Perimeter()
    {
        int perimeter = size * 4;
        return perimeter;
    }
double Diamond::Area()
{
    // area is s^2 * 3^.5 / 2
    double area = size * size * std::sqrt(3) / 2;
    return area;
}

// grow/shrink
void Diamond::Grow()
{
    // if grow puts diamond out of bounds (size > 39) no change occurs
    if (size < 39)
    {
        size++;
    }
}
void Diamond::Shrink()
{
    // if shrink puts diamond out of bounds (size < 1) no change occurs
    if (size > 1)
    {
        size--;
    }
}

// setters
void Diamond::SetBorder(char borderI)
{
    bool inAsciiRange = (borderI >= '!') && (borderI <= '~');
    if (inAsciiRange)
    {
        border = borderI;
    }
    else
    {
        border = '#';
    }
}
void Diamond::SetFill(char fillI)
{
    bool inAsciiRange = (fillI >= '!') && (fillI <= '~');

    if (inAsciiRange)
    {
        fill = fillI;
    }
    else
    {
        fill = '*';
    }
}

// draw
void Diamond::Draw()
{
    // prints top half
    for (int row = 1; row <= size; row++)
    {
        for (int i = 0; i < (size - row); i++)
        {
            cout << " ";
        }
        cout << border;
        for (int i = 0; i <= (row - 3); i++)
        {
            cout << " " << fill;
        }
        if (row != 1)
        {
            cout << " " << border;
        }
        cout << std::endl;
    }
    // prints bottom half
    for (int row = size - 1; row >= 1; row--)
    {
        for (int i = 0; i < (size - row); i++)
        {
            cout << " ";
        }
        cout << border;
        for (int i = 0; i <= (row - 3); i++)
        {
            cout << " " << fill;
        }
        if (row != 1)
        {
            cout << " " << border;
        }
        cout << std::endl;
    }
}

// summary
void Diamond::Summary()
{
    cout << "Size of diamond's side = " << size << " units.\n";
    cout << "Perimeter of diamond = " << Perimeter() << " units.\n";
    // sets precision so area is rounded to two decimals
    cout << std::setprecision(2) << std::fixed;
    cout << "Area of diamond = " << Area() << " units.\n";
    cout << "Diamond looks like:\n";
    Draw();
}
