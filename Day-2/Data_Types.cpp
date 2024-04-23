#include<iostream>
using namespace std;

int main(){
    int age = 25;
    int marks =-200;
    char grade ='A';
    bool isAdult = true;
    float cgpa = 8.9;
    double price = 99.99;

    cout<<age<<" "<<marks<<" "<<grade<<" "<<isAdult<<" "<<cgpa<<" "<<price<<endl;
    cout<<"Size of int = "<<sizeof(int)<<endl;
    cout<<"Size of char = "<<sizeof(char)<<endl;
    cout<<"Size of bool = "<<sizeof(bool)<<endl;
    cout<<"Size of float = "<<sizeof(float)<<endl;
    cout<<"Size of double = "<<sizeof(double)<<endl;
    return 0;
}