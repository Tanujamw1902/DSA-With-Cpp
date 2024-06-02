#include <iostream>
using namespace std;

int main(){
    int *ptr;

    // Addition & Subtraction of constants

    cout << "ptr current address : " << ptr << endl;
    ptr = ptr + 3;
    cout << "ptr address after ptr + 3 : " << ptr << endl;
    ptr = ptr - 3;
    cout << "ptr address after ptr - 3 : " << ptr << endl;

    return 0;
}