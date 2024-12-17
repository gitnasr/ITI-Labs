#include <iostream>

using namespace std;



// if default were in the middle, it will generate a compilation error 
int DefaultParameter(int a, int b, int c =3) {

    return a * b * c;

}



int scope;
int scope_1 = 0;
int main() {
    int result = DefaultParameter(1, 2);
    int scope = 1;
    cout << "I'm the local scope " << scope  << endl;
    cout << "I'm the global scope " << ::scope  << endl;

    int scope_1 = 0;

    cout << "Enter Number for Scope 2 private : " ;

    cin >> scope_1;

    cout << "Enter Number for Scope 2 public : " ;

    cin >> ::scope_1;


    cout << "I'm the global scope of scope_1  " << ::scope_1  << endl;

    cout << "I'm the local scope of scope_1   " << scope_1  << endl;


    float bi = 3.1445647512;

    cout << "I'm the float value of bi  " << bi  << endl;

    cout << "I'm the int value of bi  " << (int)bi  << endl;


    // Precision

    cout.precision(3);

    cout << "I'm the float value of 2 of bi  " << bi  << endl;


    return 0;
}