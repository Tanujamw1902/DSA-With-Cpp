#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<int> st;          // Stack for storing repeat counts
    stack<string> st1;      // Stack for storing previous strings
    string sb = "";         // Current substring being processed
    int n = 0;              // To accumulate the repeat count for each '['

    for (char c : s) {
        if (isdigit(c)) { // If character is a digit
            n = n * 10 + (c - '0'); // Accumulate the number
        } else if (c == '[') { // Start of a new encoded section
            st.push(n);       // Push the accumulated number to stack
            n = 0;            // Reset the number
            st1.push(sb);     // Push the current string to stack
            sb = "";          // Reset the current string
        } else if (c == ']') { // End of an encoded section
            int k = st.top(); // Get the repeat count
            st.pop();
            string temp = sb; // Store the current substring
            sb = st1.top();   // Retrieve the previous string
            st1.pop();
            while (k-- > 0) {
                sb += temp;   // Repeat the substring `k` times
            }
        } else { // Regular character, add to current substring
            sb += c;
        }
    }
    return sb;
}

int main() {
    string s1 = "3[a]2[bc]";       // Expected output: "aaabcbc"
    string s2 = "3[a2[c]]";        // Expected output: "accaccacc"
    string s3 = "2[abc]3[cd]ef";   // Expected output: "abcabccdcdcdef"
    
    cout << "Decoded string for '" << s1 << "' : " << decodeString(s1) << endl;
    cout << "Decoded string for '" << s2 << "' : " << decodeString(s2) << endl;
    cout << "Decoded string for '" << s3 << "' : " << decodeString(s3) << endl;

    return 0;
}
