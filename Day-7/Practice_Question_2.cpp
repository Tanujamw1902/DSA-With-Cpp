#include <iostream>
using namespace std;

//even -> true; odd -> false
bool isEven(int n){
    if(n % 2 == 0){
        return true;
    }else{
        return false;
    }
}

int main(){
    cout << isEven(19) << endl;
    return 0;
}