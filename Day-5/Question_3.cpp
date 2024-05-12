#include <iostream>
using namespace std;

int main(){
    int n = 371;
    int num = n;
    int cubeSum = 0;

    while(num > 0){
        int lastDig = num % 10;
        cubeSum += lastDig * lastDig * lastDig;
        num /= 10;
    }

    if(n == cubeSum){
        cout << "Armstrong number\n";
    }else{
        cout << "Not anArmstrong number\n";
    }
    return 0;
}