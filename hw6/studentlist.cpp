#include "studentlist.h"
#include <iomanip>
#include <cstring>

StudentList::StudentList() // starts out empty
{
    list = NULL; // initializes list to nothing
    n = 0;
}
StudentList::~StudentList()
{
    for (int i = 0; i < n; i++) // deletes what each pointer
                                           // points to
    {
        delete list[i];
    }
    
    delete [] list; // deletes list of pointers
}

bool StudentList::ImportFile(const char* filename)
{
    std::ifstream in;
    in.open(filename);
    if (!in) // in case attached file is not valid
    {
        return false;
    }

    int fileCount;
    in >> fileCount; // sets number of students based off file
    Student** newList = new Student*[n + fileCount];

    for (int i = 0; i < n; i++) // copies old array over if n > 0
    {   
        newList[i] = list[i];
    }

    delete [] list; // deallocates list
    list = newList; // sets to new list

    for (int i = n; i < (n + fileCount); i++) // adds new students to array
    {
        list[i] = getStudent(in); 
    }

    n += fileCount; // sets new n

    in.close();
    return true;
}
bool StudentList::CreateReportFile(const char* filename)
{
    using namespace std;
    ofstream out;
    out.open(filename);
    if (!out) // in case attached file is not valid
    {
        return false;
    }

    out << "Student Grade Summary\n"
        << "---------------------\n";

    insertCourse("Biology", out);
    insertCourse("Theater", out);
    insertCourse("Computer Science", out);

    out << "\nOVERALL GRADE DISTRIBUTION\n";
    getGradeDistribution();
    
    ios_base::fmtflags oldFlags = out.flags(); // saves flags
    
    out 
    << "\nA:" << setw(4) << gradeDistribution[0]
    << "\nB:" << setw(4) << gradeDistribution[1]
    << "\nC:" << setw(4) << gradeDistribution[2]
    << "\nD:" << setw(4) << gradeDistribution[3]
    << "\nF:" << setw(4) << gradeDistribution[4] << "\n";
    
    out.flags(oldFlags); // returns to old flags

    out.close();
    return true;
}
void StudentList::ShowList() const // print basic list data
{
    using namespace std;
    cout << "Last                 First                    Course\n";
    for (int i = 0; i < n; i++)
    {
        list[i]->displayStudent();
    }
}
void StudentList::SortList()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1); j++)
        {
            // copies and sets name to lower (that way sort is truly alphabetical)
            char name1[42];
            char name2[42];
            list[j]->getName(name1);
            list[j+1]->getName(name2);
            for (int k = 0; k < 41; k++) 
            {
                name1[k] = tolower(name1[k]);
                name2[k] = tolower(name2[k]);
            }

            if (strcmp(name1, name2) > 0) // if names are out of order, swap
            {
                Student* temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    
}

Student* StudentList::getStudent(std::ifstream& i)
// sets student to input i
{
    char l[21];
    char f[21];
    char c[17];


    i.ignore(); // ignores any previous whitespace
    i.getline(l, 20, ',');
    i.get(); // gets the space between last, first
    i.getline(f, 20, '\n');

    i.getline(c, 16, ' ');
    if (strcmp(c, "Computer") == 0) // computer science being two words 
                                    // requires more than a delimiter
    {
        i.getline(c, 16, ' '); // clears rest of coursename
        strcpy(c, "Computer Science"); // sets coursename to computer science
    }

    if (strcmp(c, "Biology") == 0)
    {
        int g[5];
        for (int j = 0; j < 5; j++) // sets data in array to input
        {
            i >> g[j];
        }
        return new Biology(l, f, c, g);
    }
    else if (strcmp(c, "Theater") == 0)
    {
        int g[3];
        for (int j = 0; j < 3; j++) // sets data in array to input
        {
            i >> g[j];
        }

        return new Theater(l, f, c, g);
    }
    else
    {
        int g[9];
        for (int j = 0; j < 9; j++) // sets data in array to input
        {
            i >> g[j];
        }

        return new ComputerScience(l, f, c, g);
    }
}

void StudentList::insertCourse(const char* courseName, std::ofstream& o) const
{
    char capsName[17];
    if (strcmp(courseName, "Biology")  == 0)
    {
        strcpy(capsName, "BIOLOGY CLASS");
    }
    else if (strcmp(courseName, "Theater")  == 0)
    {
        strcpy(capsName, "THEATER CLASS");
    }
    else
    {
        strcpy(capsName, "COMPSCI CLASS");
    }

    o << "\n" << capsName << "\n\n"
        << "Student                                   Final Final   Letter\n"
        << "Name                                      Exam  Avg     Grade\n"
    << "----------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        if (strcmp(list[i]->getCourse(), courseName) == 0)
        {
            list[i]->insertStudent(o);
        }
    }
}

void StudentList::getGradeDistribution()
// gets grade distribution of files
{
    for (int i = 0; i < 5; i++) // sets count to 0
    {
        gradeDistribution[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(list[i]->getGrade() == 'A')
        {
            gradeDistribution[0]++;
        }
        else if(list[i]->getGrade() == 'B')
        {
            gradeDistribution[1]++;
        }
        else if(list[i]->getGrade() == 'C')
        {
            gradeDistribution[2]++;
        }
        else if(list[i]->getGrade() == 'D')
        {
            gradeDistribution[3]++;
        }
        else
        {
            gradeDistribution[4]++;
        }
    }
}
