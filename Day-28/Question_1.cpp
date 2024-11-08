#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Helper function to check if a string is a palindrome
bool isPalin(string str) {
    int n = str.size();
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

// Function to check if the linked list values form a palindrome
bool isPalindrome(ListNode* head) {
    string str = "";
    ListNode* temp = head;
    while (temp != NULL) {
        str += to_string(temp->val); // Convert integer to string before appending
        temp = temp->next;
    }
    return isPalin(str);
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    // Free the allocated memory
    ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
