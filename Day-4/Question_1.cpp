#include <iostream>
using namespace std;

int main(){
    int num;
    cout << "Enter a Number: " << endl;
    cin >> num;

    if ( num > 0) {
        cout << "Number is Positive. \n";
    } else if (num < 0) {
        cout << "Number is Negative. \n";
    }else {
        cout << "Number is Zero. \n";
    }

    return 0;
}