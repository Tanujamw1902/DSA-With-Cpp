#include <iostream>
using namespace std;

int main(){
    int marks[50] = {1, 2, 3}; // 0 to 49

    cout  << marks[0] << endl; // 1
    cout  << marks[1] << endl; // 2
    cout  << marks[2] << endl; // 3
    cout  << marks[3] << endl; // 0

    int marks1[] = {4, 5, 6}; // 0 to 2

    cout  << marks1[0] << endl; // 4
    cout  << marks1[1] << endl; // 5
    cout  << marks1[2] << endl; // 6

    cout << sizeof(marks)/ sizeof(int) << endl;
    
    return 0;
}