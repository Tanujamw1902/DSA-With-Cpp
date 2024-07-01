#include <iostream>
#include <string>
using namespace std;

void towerOfHanoi(int n, string src, string helper, string dest){
    if(n == 1){
        cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
        return;
    }
    // transfer top n - 1 from src to helper using dest as 'helper'
    towerOfHanoi(n - 1, src, dest, helper);
    // transfer nth from src to dest
    cout << "Transfer disk " << n << " from " << src << " to " << helper << endl;
    // transfer n - 1 from helper to dest using src as 'helper'
    towerOfHanoi(n - 1, helper, src, dest);
}

int main(){
    int n = 4;
    towerOfHanoi(4, "A", "B", "C");
    
    return 0;
}