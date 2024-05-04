#include <iostream>
using namespace std;

int main(){
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if(age >=18){
        cout << "Can Vote" << endl;
    } if(age >=45){
        cout << "Contest for  Elections" << endl;
    }else{
        cout << "Cannot Vote" << endl;
    }
    
    return 0;
}