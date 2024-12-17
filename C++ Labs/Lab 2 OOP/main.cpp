//
// Created by nasr on 12/17/2024.
//

using namespace std;
#include <cstdio>
#include <cstring>
#include <iostream>

class Student
{
private:
    int id;
    char name[50];
    int grades[3];

public:
    void set_id(int id)
    {
        Student::id = id;
    };
    void set_name(char name[50])
    {
        strncpy(Student::name, name, sizeof(Student::name) - 1);
    }
    int get_id()
    {
        return id;
    }
    char *get_name()
    {
        return name;
    }
    void set_grades(int grades[3])
    {
        for (int i = 0; i < 3; i++)
        {
            Student::grades[i] = grades[i];
        }
    }
    int *get_grades()
    {
        return grades;
    }
};
Student fillStudent()
{
    int id;
    char name[50];
    int grades[3];
    Student student;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    cin >> name;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter Student Grade " << "(" << i + 1 << ")" << ": ";
        cin >> grades[i];
    }
    student.set_id(id);
    student.set_grades(grades);
    student.set_name(name);
    return student;
}

void PrintStudent(Student student)
{
    cout << "Student ID: " << student.get_id() << endl;
    cout << "Student Name: " << student.get_name() << endl;
    cout << "Student Grades: ";
    for (int i = 0; i < 3; i++)
    {
        cout << student.get_grades()[i] << " ";
    }
}

int main()
{

    Student student = fillStudent();

    PrintStudent(student);

    return 0;
}
