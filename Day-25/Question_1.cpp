#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class List {
public:
    Node* head;

    List() : head(NULL) {}

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;

        // Step 1: Find the middle of the linked list
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        Node* prev = NULL;
        Node* curr = slow;
        while (curr) {
            Node* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }

        // Step 3: Compare the two halves
        Node* firstHalf = head;
        Node* secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->data != secondHalf->data) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: Optional - Restore the list
        // You can reverse the second half again here if needed

        return true;
    }
};

int main() {
    List ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    ll.push_back(1);

    if (ll.isPalindrome()) {
        cout << "The linked list is a palindrome.\n";
    } else {
        cout << "The linked list is not a palindrome.\n";
    }

    return 0;
}
