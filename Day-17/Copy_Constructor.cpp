#include <iostream>
using namespace std;

class Car{
    public:
        string name;
        string color;

    Car(string name, string color){
        this->name = name;
        this->color = color;
    }

    Car(Car &original){
        cout <<"Copying Original To new.." << endl;
        name = original.name;
        color = original.color;
    }
};

int main(){
    Car c1("Nano", "Grey");

    Car c2(c1);

    cout << c2.name << endl;
    cout << c2.color << endl;

    return 0;
}