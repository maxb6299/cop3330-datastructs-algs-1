// palindrome.cpp

#include "stack.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool checkPalindrome(char str[100]) 
// determine if a string is a palindrome. ignores non-letters
// lowercase and uppercase letters are matching
{
    Stack <char> strStack;
    for (int i = 0; i < strlen(str); i++) // copies data to stack
    {
        if (isalpha(str[i]) == 0) // if char isn't letter don't push on stack
        {
            continue;
        }

        strStack.push(str[i]);
    }

    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]) == 0) // if char isn't a letter skip remaining code
        {
            continue;
        }
        
        char tempChar;
        strStack.pop(tempChar); // sets tempChar to popped value

        // if unequal, not a palindrome. tolower to avoid case sensitivity
        if (tolower(str[i]) != tolower(tempChar)) 
        {
            return false;
        }
    }
    return true;
}

int main() // accepts input, runs checkPalindrome() and outputs results
{
    cout << "Please enter a string: \n> ";

    char palindrome[100] = "\0";
    cin.getline(palindrome, 100);
    
    if (checkPalindrome(palindrome))
    {
        cout << "\n\"" << palindrome << "\" IS a palindrome\n";
    }
    else
    {
        cout << "\n\"" << palindrome << "\" is NOT a palindrome\n";
    }
}
