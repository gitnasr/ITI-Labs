#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    int id;
    char name[50];

public:
    Student() {
        strcpy(this->name, "Unknown");
        this->id = 0;
    }

    Student(int studentId) {
        this->id = studentId;
        strcpy(this->name, "Unknown");
    }

    Student(char* studentName) {
        this->id = 0;
        strcpy(this->name, studentName);
    }

    Student(int studentId, char* studentName) {
        this->id = studentId;
        strcpy(this->name, studentName);
    }

    Student(Student& other) {
        this->id = other.id;
        strcpy(this->name, other.name);
    }

    ~Student() {
        cout << "Destructor called for Student with ID: " << this->id << " and Name: " << this->name << endl;
    }

    int getId() {
        return this->id;
    }

    void setId(int studentId) {
        this->id = studentId;
    }

    const char* getName()  {
        return this->name;
    }

    void setName(const char* studentName) {
        strcpy(this->name, studentName);
    }

    void display() const {
        cout << "ID: " << this->id << ", Name: " << this->name << endl;
    }
     void fillStudent(int studentId, const char* studentName) {
        this->id = studentId;
        strcpy(this->name, studentName);
    }
};

int main() {
    // Default
    Student student1;
    student1.display();

    // Constructor with ID only
    Student student2(123);
    student2.display();

    // Constructor with Name only
    Student student3("Nasr");
    student3.display();

    // Name and ID
    Student student4(0123, "Mahmoud Nasr");
    student4.display();

    // Fill without constructor 
    student1.fillStudent(336, "Salma");
    student1.display();

    // Modifying existing student using fillStudent
    student3.fillStudent(112, "Ager");
    student3.display();

    // Creating a student and filling it later
    Student student5;
    student5.fillStudent(000, "Aronld");
    student5.display();

    // Invalid name handling in fillStudent
    student5.fillStudent(303, ""); // Name will still be set to an empty string
    student5.display();

    return 0;
}
