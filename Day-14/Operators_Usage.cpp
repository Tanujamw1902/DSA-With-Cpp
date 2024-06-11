#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str1 = "cat";
    string str2 = "dog";

    cout << (str1 == str2) << endl;
    cout << (str1 != str2) << endl;
    cout << (str1 < str2) << endl;
    cout << (str1 > str2) << endl;

    return 0;
}