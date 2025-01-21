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
};
ostream &operator<<(ostream &out, Employee objectOfEmployee)
{
    ofstream F1("employee.txt");
    F1 << objectOfEmployee.id << endl;
    F1 << objectOfEmployee.name << endl;
    F1 << objectOfEmployee.salary << endl;
    F1.close();
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

};