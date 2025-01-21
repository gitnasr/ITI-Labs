#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
using namespace std;



class Employee
{
private:
    int id, salary;
    string name;


    friend ostream &operator<<(ostream &out, Employee objectOfEmployee);
    friend istream &operator>>(istream &in, Employee &objectOfEmployee);
public:
 void printFromBinaryFile() {
    ifstream F("data.nasr",std::ios::in | std::ios::binary);
    F.read(reinterpret_cast< char *>(&id),sizeof(int));
    F.read(reinterpret_cast< char *>(&name),sizeof(string));
    F.read(reinterpret_cast< char *>(&salary),sizeof(int));

    cout <<id << endl;
    cout << name << endl;
    cout << salary << endl;
 
 };
};
ostream &operator<<(ostream &out,  Employee objectOfEmployee)
{
    ofstream F1;
    F1.open("data.nasr",ios::binary | ios::out);
    F1.write(reinterpret_cast<const char *>(&objectOfEmployee.id), sizeof(int));
    F1.write(reinterpret_cast<const char *>(&objectOfEmployee.name), sizeof(string));
    F1.write(reinterpret_cast<const char *>(&objectOfEmployee.salary) , sizeof(int));
    
    return out;
}

istream &operator>>(istream &in, Employee &objectOfEmployee)
{
    cout << "Enter Employee Name :" << endl;
    in >> objectOfEmployee.name;

    cout << "Enter Employee ID: " << endl;
    in >> objectOfEmployee.id;

    cout << "Enter Employee Salary: " << endl;
    in >> objectOfEmployee.salary;
    return in;
}

int main() {
  
  Employee e;
  cin >> e;
  cout << e;

  e.printFromBinaryFile();

};