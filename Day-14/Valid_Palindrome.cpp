#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char str[], int n){
    int st = 0, end = n - 1;
    while(st < end){
        if(str[st++] != str[end--]){
            cout << "Not Valid Palindrome" << endl;
            return false;
        }
    }
    cout << "Valid Palindrome" << endl;
}

int main(){
    char word[] = "racecar";
    isPalindrome(word, strlen(word));

    return 0;
}