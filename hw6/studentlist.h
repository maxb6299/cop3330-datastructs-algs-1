// header for StudentList class
#include "student.h"
#include <iostream>
#include <fstream>

class StudentList
{
public:
   StudentList();		// starts out empty
   ~StudentList();	// cleanup (destructor)

   bool ImportFile(const char* filename);
   bool CreateReportFile(const char* filename);
   void ShowList() const;	// print basic list data
   void SortList();

private:
   Student** list;
   int n; // num of students
   int gradeDistribution[5]; // array of num of grades for each letter

   Student* getStudent(std::ifstream& i); // sets students to input i
   void insertCourse(const char* courseName, std::ofstream& o) const; // inserts to each class
   void getGradeDistribution(); // gets grade distribution of files
};