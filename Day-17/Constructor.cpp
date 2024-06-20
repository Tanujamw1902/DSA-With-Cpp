#include <iostream>
#include <string>
using namespace std;

class Car{
    string name;
    string color;

public:
    Car(){
        cout << "Constructor Without Parameters..." << endl;
    }

    Car(string name, string color){
        cout << "Constructor With Parameters..." << endl;
        this->name = name;
        this->color = color;

    }

    void start(){
        cout << "Car has started..." << endl;
    }

    void stop(){
        cout << "Car has stopped..." << endl;
    }

    //Getter
    string getName(){
        return name;
    }

    string getcolor(){
        return color;
    }
};

int main(){
    Car c0;
    Car c1("Nano", "Grey");
    cout << "Car Name: " << c1.getName() << endl;
    cout << "Color Name: " << c1.getcolor() <<endl;

    return 0;
}