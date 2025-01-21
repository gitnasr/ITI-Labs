#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
    int id;
    char *name;

public:
    Employee()
    {
        id = 0;
        name = new char[1];
        strcpy(name, "");
    }
    Employee(int id, char *EmployeeName)
    {
        this->id = id;
        name = new char[strlen(EmployeeName) + 1];

        strcpy(this->name, EmployeeName);
    }

    Employee(const Employee &e)
    {
        id = e.id;
        name = new char[strlen(e.name) + 1];
        strcpy(name, e.name);
    }
    char *getName()
    {
        return this->name;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getid()
    {
        return this->id;
    }
    void setName(const char *EmployeeName)
    {
        strcpy(this->name, "Unknown");
    }
    Employee &operator=(const Employee &e);
    Employee operator+(Employee emp);
    Employee operator+(const char *name);
    friend Employee operator+(const char *name, Employee emp);
    operator int();
    operator char *();
    Employee operator++(int dummy);
    Employee operator++();
    friend Employee operator+(int value, const Employee &emp);
    friend Employee operator+(Employee& emp, int value);
};
Employee &Employee::operator=(const Employee &e)
{
    this->id = e.id;
    strcpy(this->name, e.name);
    return *this;
}

Employee Employee::operator+(Employee emp)
{
    Employee TempEmployee;
    TempEmployee.id = this->id + emp.id;

    TempEmployee.name = new char[strlen(this->name) + strlen(emp.name) + 1];
    strcpy(TempEmployee.name, this->name);
    strcat(TempEmployee.name, " ");
    strcat(TempEmployee.name, emp.name);

    return TempEmployee;
}

Employee Employee::operator+(const char *name)
{
    Employee TempEmployee;
    TempEmployee.id = this->id;

    TempEmployee.name = new char[strlen(this->name) + strlen(name) + 1];
    strcpy(TempEmployee.name, this->name);
    strcat(TempEmployee.name, " ");
    strcat(TempEmployee.name, name);

    return TempEmployee;
}
Employee operator+(const char *name, Employee emp)
{
    Employee TempEmployee;
    TempEmployee.id = emp.id;

    TempEmployee.name = new char[strlen(emp.name) + strlen(name) + 1];
    strcpy(TempEmployee.name, name);
    strcat(TempEmployee.name, " ");
    strcat(TempEmployee.name, emp.name);

    return TempEmployee;
}
Employee::operator int()
{
    return this->id;
}
Employee::operator char *()
{
    return this->name;
}

Employee Employee::operator++(int dummy)
{
    Employee temp = *this;
    ++id;
    return temp;
}

Employee Employee::operator++()   // Prefix
{
    ++id;
    return *this;
}


Employee operator+(int value, const Employee &emp)
{
    Employee temp;
    temp.id = value + emp.id;  // Add value to Employee's id
    temp.name = new char[strlen(emp.name) + 1];
    strcpy(temp.name, emp.name);  // Copy the name
    return temp;
}
Employee operator + (Employee& emp, int value)
{
    Employee temp;
    temp.id = value + emp.id;  // Add value to Employee's id
    temp.name = new char[strlen(emp.name) + 1];
    strcpy(temp.name, emp.name);  // Copy the name
    return temp;
}
int main()
{

    Employee e(1, "John");
    Employee e2(2, "Jane");

    e2 = e;

    cout << "Employee 2 name: " << e2.getName() << endl;

    Employee e3(4, "Nasr");
    Employee e4(5, "Ali");

    e3 = e4 + e3;

    cout << "Employee 3 name: " << e3.getName() << endl;

    Employee e5(6, "Ahmed");
    e5 = e5 + "Mohamed";

    cout << "Employee 5 name: " << e5.getName() << endl;

    Employee e6(7, "Khaled");
    e6 = "Mohamed" + e6;

    cout << "Employee 6 name: " << e6.getName() << endl;

    Employee e7(8, "Hassan");

    cout << "Employee 7 id: " << (int)e7 << endl;

    Employee e8(9, "Hassan");

    cout << "Employee 8 name: " << (char *)e8 << endl;

    Employee e9(10, "Hassan");

    e9 = e9++;

    cout << "Employee 9 id: " << e9.getid() << endl;

    Employee e10(11, "Hassan");
    e10 = ++e10;
    cout << "Employee 10 id: " << e10.getid() << endl;

    Employee e11(12, "Hassan");
    e11 = 100 + e10;
    cout << "Employee 11 id: " << e11.getid() << endl;

    Employee e12(13, "Hassan");
    e12 = e12 + 100;
    cout << "Employee 12 id: " << e12.getid() << endl;

    return 0;
};
