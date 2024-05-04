#include <iostream>
using namespace std;

int main(){
    //Arithmetic Operators(Binary)
    int a = 15;
    int b = 5;

    cout <<"+ " << (a + b) << endl; //20
    cout <<"- " << (a - b) << endl; //10
    cout <<"* " << (a * b) << endl; //75
    cout <<"/ " << (a / b) << endl; //3
    cout <<"% " << (a % b) << endl; //0(Modulo Operator which is printing the remainder value)
    
    //Arithmetic Operators(Unary)
    int x = 3;
    x++; //4
    cout << "x = " << x << endl;
    x--; //3
    cout << "x = " << x << endl;
    ++x; //4
    cout << "x = " << x << endl;
    --x; //3
    cout << "x = " << x << endl;

    int y = x++;
    cout << "x = " << x << endl; //4
    cout << "y = " << y << endl; //3

    int w = x--;
    cout << "x = " << x << endl; //3
    cout << "y = " << y << endl; //3

    int z = ++x;
    cout << "x = " << x << endl; //4
    cout << "y = " << y << endl; //3

    int c = --x;
    cout << "x = " << x << endl; //3
    cout << "y = " << y << endl; //3





    return 0;
}