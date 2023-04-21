#include "student.h"
#include <iomanip>
#include <cstring>


// constructors
Student::Student(const char l[], const char f[], const char c[])
{
    strncpy(lastName, l, 20);
    strncpy(firstName, f, 20);
    strncpy(course, c, 16);
}

Biology::Biology(const char l[], const char f[], const char c[], 
                 const int g[5]) : Student(l, f, c)
{
    for (int i = 0; i < 5; i++) // copies over array
    {
        grades[i] = g[i];
    }

    final = g[4];
    avg = getAverage();
    gradeLetter = getGradeLetter();
}

Theater::Theater(const char l[], const char f[], const char c[], 
                const int g[3]) : Student(l, f, c)
{
    for (int i = 0; i < 3; i++) // copies over array
    {
        grades[i] = g[i];
    }

    final = g[2];
    avg = getAverage();
    gradeLetter = getGradeLetter();
}
   
ComputerScience::ComputerScience(const char l[], const char f[], 
                                 const char c[], const int g[9]) 
                                 : Student(l, f, c)
{
    for (int i = 0; i < 9; i++) // copies over array
    {
        grades[i] = g[i];
    }

    final = g[8];
    avg = getAverage();
    gradeLetter = getGradeLetter();
}


// getAverage() functions
float Biology::getAverage() const // Average of the following:
                                  // Lab Grade = 30%
                                  // Three term tests = 15 % each
                                  // Final Exam = 25% 
{
    float grade = 0;
    grade += grades[0] * .30; // lab grade
    for (int i = 1; i <= 3; i++) // three term tests
    {
        grade += grades[i] * .15;
    }
    grade += grades[4] * .25; // final

    return grade;
}
float Theater::getAverage() const // Average of the following:
                                  // Participation (scene studies) = 40 %
                                  // Midterm = 25%
                                  // Final Exam = 35% 
{
    float grade = 0;
    grade += grades[0] * .40; // participation
    grade += grades[1] * .25; // midterm
    grade += grades[2] * .35; // final
    
    return grade;
}
float ComputerScience::getAverage() const // Average of the following:
                                          // Program Avg (avg of 6) = 30%
                                          // Test 1 = 20%
                                          // Test 2 = 20%
                                          // Final Exam = 30% 
{
    float grade = 0;
    for (int i = 0; i <= 5; i++) // program average
    {
        grade += grades[i] * .05;
    }
    for (int i = 6; i <= 7; i++) // test 1 and 2
    {
        grade += grades[i] * .2;
    }
    grade += grades[8] * .3; // final

    return grade;
}


// insert/display student functions
void Student::insertStudent(std::ofstream& i) const
// inserts student info into i (for file writing)
{
    using namespace std;

    // saves old precision settings and sets decimal to round to 2 places
    int oldPrecision = i.precision();
    ios_base::fmtflags oldFlags = i.flags();
    i << setprecision(2) << fixed; // rounds grades to 2 places

    char fullName[42] = "\0";
    strcat(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
    i << left << setw(42) 
      << fullName << setw(6)
      << final << setw(8)
      << avg
      << gradeLetter << "\n";

    // returns to old precision and flags
    i.precision(oldPrecision);
    i.flags(oldFlags);
}
void Student::displayStudent() const
{
    using namespace std;

    // saves old precision settings and sets decimal to round to 2 places
    int oldPrecision = cout.precision();
    ios_base::fmtflags oldFlags = cout.flags();

    cout << left << setw(21) << lastName << setw(23) << firstName << course << "\n";

    // returns to old precision and flags
    cout.precision(oldPrecision);
    cout.flags(oldFlags);
}


// helper function
char Student::getGradeLetter() const
{
    if (avg >= 90)
    {
        return 'A';
    }
    else if (avg >= 80)
    {
        return 'B';
    }
    else if (avg >= 70)
    {
        return 'C';
    }
    else if (avg >= 60)
    {
        return 'D';
    }
    else 
    {
        return 'F';
    }
}

const char* Student::getCourse() const
{
    return course;
}

void Student::getName(char* name) const // returns "[lastname] [firstname]"
{
    strcpy(name, lastName);
    strcat(name, " ");
    strcat(name, firstName);
}


const char Student::getGrade() const
{
    return gradeLetter;
}