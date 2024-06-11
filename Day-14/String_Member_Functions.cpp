#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str ="Tanuja Waware!";

    cout << str.length() << endl;
    cout << str.at(3) << endl;
    cout << str.substr(1,5) << endl;
    cout << str.find("a", 5) << endl;

    return 0;
}