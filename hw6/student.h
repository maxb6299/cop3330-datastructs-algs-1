// header for Student class
#include <iostream>
#include <fstream>

class Student
{
public:
    Student(const char l[] = "\0", const char f[] = "\0", 
            const char c[] = "\0");
    void insertStudent(std::ofstream& i) const; // inserts student into file i
    void displayStudent() const;
    const char* getCourse() const;
    void getName(char* name) const; // returns "[lastname] [firstname]"
    const char getGrade() const;
    
protected:
    char lastName[21];
    char firstName[21];
    char course[17];
    char gradeLetter;
    float avg;
    float final;
    virtual float getAverage() const = 0;
    char getGradeLetter() const;
};

class Biology : public Student
{
public:
    Biology(const char l[], const char f[], const char c[], const int g[5]);

private:
    int grades[5];
    float getAverage() const;
};

class Theater : public Student
{
public:
    Theater(const char l[], const char f[], const char c[], const int g[3]);
   
private:
    int grades[3];
    float getAverage() const;
};

class ComputerScience : public Student
{
public:
    ComputerScience(const char l[], const char f[], const char c[], 
                    const int g[9]);
   
private:
    int grades[9];
    float getAverage() const;
};
