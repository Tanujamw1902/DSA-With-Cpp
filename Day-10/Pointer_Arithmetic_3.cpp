#include <iostream>
using namespace std;

int main(){
    int *ptr;

    //Addition & Subtraction Of Pointers

    int *ptr1, *ptr2;
    int arr[] = {1, 2, 3, 4, 5};
    ptr1 = arr;
    ptr2 = ptr1 + 3;

    // Invalid Operation
    //cout<< ptr1 + ptr2 << endl; We Cant Add Two Addresses

    cout << "ptr1 : " << ptr1 << endl;
    cout << "ptr2 : " << ptr2 << endl;
    cout << "ptr2 - ptr1 : " << ptr2 - ptr1 << endl;
    return 0;
}