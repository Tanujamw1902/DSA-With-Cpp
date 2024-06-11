#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str1[100] = "Hello";
    char str2[100] = " Hello";
    //strcpy(str1, str2);
    //strcat(str1, str2);
    cout << strcmp(str1, str2) << endl;
    cout << str1 << endl;

    return 0;
}