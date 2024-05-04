#include <iostream>
using namespace std;

int main(){

    //And Operator...
    cout << ((3 < 5) && (10 > 5)) << endl; //True ->1
    cout << ((3 < 5) && (10 == 5)) << endl; //False ->0
    cout << ((3 == 5) && (10 > 5)) << endl; //False ->0
    cout << ((3 == 5) && (10 == 5)) << endl; //False ->0

    //Or Operator...
    cout << ((3 < 5) || (10 > 5)) << endl; //True ->1
    cout << ((3 < 5) || (10 == 5)) << endl; //True ->1
    cout << ((3 == 5) || (10 > 5)) << endl; //True ->1
    cout << ((3 == 5) || (10 == 5)) << endl; //False ->0

    //Not Operator..
    cout << (!(3 == 5)) << endl; // True ->1
    cout << (!(3 != 5)) << endl; // False ->0
    cout << (!(3 > 5)) << endl; // True ->1

    return 0;
}