#include <iostream>
using namespace std;

int main(){
    int *ptr;

    // Increment & Decrement Operators

    cout << "Before Operation ptr1 Address : " << ptr << endl;
    ptr++;
    cout << "ptr1 Address After ptr++: " << ptr << endl;
    ptr--;
    cout << "ptr1 Address After ptr--: " << ptr << endl;
    ++ptr;
    cout << "ptr1 Address After ++ptr: " << ptr << endl;
    --ptr;
    cout << "ptr1 Address After --ptr: " << ptr << endl;
    
    return 0;
}