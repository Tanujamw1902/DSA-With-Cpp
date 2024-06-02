#include <iostream>
using namespace std;

int main(){
    int *ptr;

    // Comparison Operator

    int *ptr1, *ptr2;
    cout << "ptr1 : " << ptr1 << endl;
    cout << "ptr2 : " << ptr2 << endl;
    cout << "ptr1 == ptr2 : " << (ptr1 == ptr2) << endl;
    cout << "ptr1 > ptr2 : " << (ptr1 > ptr2) << endl;
    cout << "ptr1 < ptr2 : " << (ptr1 < ptr2) << endl;
    cout << "ptr1 <= ptr2 : " << (ptr1 <= ptr2) << endl;
    cout << "ptr1 >= ptr2 : " << (ptr1 >= ptr2) << endl;

    return 0;
}