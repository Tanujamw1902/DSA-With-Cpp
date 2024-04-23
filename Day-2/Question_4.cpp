#include<iostream>
#define PI 3.14
using namespace std;

int main(){
    float radius;
    cin>>radius;
    cout<<"Enter the radius of the Circle = "<<endl;

    float area = PI * radius * radius;
    cout<<"An Area of Circle = "<<area<<endl;

    return 0;
}