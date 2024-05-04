#include <iostream>
using namespace std;

int main(){
    int a, b;
    cout << "Enter a:" << endl;
    cin >> a;
    cout << "Enter b:" <<  endl;
    cin >> b;
    if(a > b){
        cout << "Print value:" << a << endl;
    } else{
        cout << "Print value:" << b << endl;
    }

    return 0;
}