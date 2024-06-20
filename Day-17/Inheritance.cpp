#include <iostream>
using namespace std;

class Animal{
public:
    string color;

    void eat(){
        cout << "Eats" << endl;
    }

    void breathe(){
        cout << "Breathes" << endl;
    }
};


class Fish : protected Animal{
public:
    int fins;

    void swim(){
        eat();
        cout << "Swims" << endl;
    }
};

int main(){
    Fish f1;
    f1.fins = 3;
    cout << f1.fins << endl;
    f1.swim();
    //f1.eat();
    //f1.breathe();

    return 0;
}