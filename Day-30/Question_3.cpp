#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string getSmallestString(int n, int k) {
    string ans;

    while (n != 0) {
        int ch = k - (n - 1) * 26;

        if (ch <= 0) {
            ans.push_back('a');
            k -= 1;
        } else {
            ans.push_back((char)(ch + 'a' - 1));
            k -= ch;
        }

        n--;
    }

    reverse(ans.begin(), ans.end()); // Because we build from end to front
    return ans;
}

int main() {
    int n = 5, k = 73;
    cout << "Smallest String: " << getSmallestString(n, k) << endl;
    return 0;
}
