#include <iostream>
#include <string>
using namespace std;

class A{
public:
    A(){
        cout << "Constructor A" << endl;
    }

    ~A(){
        cout << "Destructor A" << endl;
    }
};

class B : public A{
public:
    B(){
        cout << "Constructor B" << endl;
    }

    ~B(){
        cout << "Destructor B" << endl;
    }
};

int main(){
    B obj;

    return 0;
}