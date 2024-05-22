#include <iostream>
using namespace std;

int largest(int a, int b, int c){
    if(a >= b && a >= c){
        return a;
    }else if(b >= c){
        return b;
    }else{
        return c;
    }
    cout << endl;
}

int main(){
    cout << largest(12, 19, 2);
    return 0;
}