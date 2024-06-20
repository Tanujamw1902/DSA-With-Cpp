#include <iostream>
using namespace std;

class Student{
    // Properties
    string name;
    float cgpa;

    // Methods
    void getPercentage(){
        cout << (cgpa * 10) << "%" <<endl;
    }
};

class user{
    int id;
    string username;
    string password;
    string bio;

    void deactivate(){
        cout << "Deleting Account" << endl;
    }
    void editBio(string newBio){
        bio = newBio;
    }
};

int main(){
    Student s1; // object
    cout << sizeof(s1) << endl;

    Student s2; // object
    cout << sizeof(s2) << endl;

    return 0;
}