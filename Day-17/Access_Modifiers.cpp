#include <iostream>
using namespace std;

class Student{
public:
    // Properties
    string name;
    float cgpa;

    // Methods
    void getPercentage(){
        cout << (cgpa * 10) << "%" <<endl;
    }
};

int main(){
    Student s1; // object
    s1.name = "Tanuja";
    cout << s1.name << endl;
    s1.cgpa = 9.0;
    cout <<s1.cgpa << endl;
    s1.getPercentage();

    return 0;
}