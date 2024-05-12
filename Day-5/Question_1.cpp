#include <iostream>
using namespace std;

int main(){
    int n = 6;
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    cout << "Factorial of " << n << " = " << fact << "\n";
    return 0;
}