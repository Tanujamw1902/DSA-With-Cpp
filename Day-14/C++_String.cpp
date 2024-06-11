#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str;
    getline(cin, str, '$');
    cout << str[0] << endl;

    return 0;
}