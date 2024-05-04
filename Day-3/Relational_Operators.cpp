#include <iostream>
using namespace std;

int main(){
    // Relational Operators -> T / F
    int a = 3;
    int b = 5;
    cout << (a > b) << endl; //False -> 0
    cout << (a < b) << endl; //True -> 1

    int x = 4;
    int y = 4;
    cout << (x >= y) << endl; //True -> 1
    cout << (x <= y) << endl; //True -> 1
    cout << (x == y) << endl; //True -> 1
    cout << (x != y) << endl; //False ->0
    
    return 0;
}