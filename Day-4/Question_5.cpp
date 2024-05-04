#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter a 3 digit  number: " << endl;
    cin >> n;

    int num = n; //creating a copy

    int dig1 = num % 10;
    num /= 10;
    int dig2 = num % 10;
    num /= 10;
    int dig3 = num;
    int cubeSum = dig1 * dig1 * dig1 + dig2 * dig2 * dig2 + dig3 * dig3 * dig3;

    if (cubeSum == n) {
        cout << n << " is anArmstrong Number. \n";
    } else {
        cout << n << " is not an Armstrong Number. \n";
    }
    
    return 0;
}