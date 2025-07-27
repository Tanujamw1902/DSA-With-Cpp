#include <iostream>
#include <string>
using namespace std;

string largestOddNumber(string num) {
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit = num[i] - '0';
        if (digit & 1) { // Check if digit is odd
            return num.substr(0, i + 1);
        }
    }
    return "";
}

int main() {
    string num = "3542706";
    string result = largestOddNumber(num);
    if (result.empty())
        cout << "No odd number prefix exists." << endl;
    else
        cout << "Largest odd number: " << result << endl; // Output: 35427
    return 0;
}
