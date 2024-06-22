#include <iostream>
#include <string>
using namespace std;

class Parent{
public:
    void show(){
        cout << "Parent Class Show.." << endl;
    }

    virtual void hello(){
        cout << "Parent Hello" << endl;
    }
};

class Child : public Parent{
public:
    void show(){
        cout << "Child Class Show.." << endl;
    }

    void hello(){
        cout << "Child Hello" << endl;
    }
};

int main(){
    Child child1;
    Parent *ptr;

    ptr = &child1;
    ptr->hello();

    return 0;
}