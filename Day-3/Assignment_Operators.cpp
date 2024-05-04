#include <iostream>
using namespace std;

int main(){
    int a = 10;

    a += 5;// a = a + 5 => 15
    cout << a << endl; //15
    a -= 5;// a = a - 5 => 10
    cout << a << endl; //10
    a *= 5;// a = a * 5 => 50
    cout << a << endl; //50
    a /= 5;// a = a / 5 => 10
    cout << a << endl; //10

    return 0;
}