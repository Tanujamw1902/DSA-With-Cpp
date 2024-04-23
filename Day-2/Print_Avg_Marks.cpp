#include<iostream>
using namespace std;

int main(){
    float eng;
    float sci;
    float math;

    cout<<"Enter English Marks :";
    cin>>eng;

    cout<<"Enter Science Marks :";
    cin>>sci;

    cout<<"Enter Mathematics Marks :";
    cin>>math;

    float avg = (eng + sci + math) / 3;
    cout<<"Average Marks : "<<avg<<endl;

    return 0;
}