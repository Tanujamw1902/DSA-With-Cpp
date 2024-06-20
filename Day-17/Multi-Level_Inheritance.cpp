#include <iostream>
#include<string>
using namespace std;

class Animal{
public:
    void eat(){
        cout << "Eats" << endl;
    }

    void breathe(){
        cout << "Breathes" << endl;
    }
};

class Mammal : public Animal{
public:
    string bloodType;
    Mammal(){
        bloodType = "Warm";
    }
};

class Dog : public Mammal{
public:
    void tailWag(){
        cout << "A dog wags its tail." << endl;
    }
};

int main(){
    Dog d1;

    d1.eat();
    d1.breathe();
    d1.tailWag();
    cout << d1.bloodType << endl;

    return 0;
}