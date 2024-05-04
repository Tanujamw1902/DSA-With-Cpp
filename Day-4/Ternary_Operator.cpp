#include <iostream>
using namespace std;

int main(){
    bool isAdult; // 1, 0
    int age;
    cout << "Enter age: ";
    cin >> age;

    if(age >= 18){
        isAdult = true;
    } else{
        isAdult = false;
    }

    isAdult = age >= 18 ? true : false;

    //Largest of 2 numbers
    int a = 10;
    int b = 5;

    int largest = a >= b ? a : b;
    cout << "Largest is " << largest << endl;

    //Odd or Even
    int num = 13;
    bool isEven = num % 2 == 0 ? true : false;
    return 0;
}