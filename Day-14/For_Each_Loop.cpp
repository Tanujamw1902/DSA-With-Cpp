#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str = "Tanuja Waware!";

    for(int i = 0; i < str.length(); i++){ // dot operator
            cout << str[i] << "-";
    }
    cout << endl;

    for(char ch : str){
        cout << ch << ",";
    }
    cout << endl;

    return 0;
}