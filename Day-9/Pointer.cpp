#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int *ptr = &a;

    int **pptr = &ptr;

    float pi = 3.14;
    float *ptr2 = &pi;

    cout << &a << " = " << ptr << "\n";
    cout << &ptr << " = " << pptr << "\n";
    cout << &pi << " = " << ptr2 << "\n";

    cout << sizeof(ptr) << "\n";
    cout << sizeof(ptr2) << "\n";

    return 0;
}