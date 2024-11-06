#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Function to get the size of the linked list
int getSize(ListNode* head) {
    int size = 0;
    while (head != NULL) {
        size++;
        head = head->next;
    }
    return size;
}

// Function to get the k-th node from the end
ListNode* KthFromEnd(ListNode* head, int k) {
    ListNode* temp = head;
    int size = getSize(head);

    // Edge case: if k is greater than the size of the list
    if (k > size) {
        return NULL;
    }

    // Move temp to the (size - k) position
    for (int i = 0; i < size - k; i++) {
        temp = temp->next;
    }
    return temp;
}

// Function to swap k-th node from beginning with k-th node from end
ListNode* swapNodes(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the k-th node from the beginning
    ListNode* left = head;
    for (int i = 0; i < k - 1; i++) {
        left = left->next;
    }

    // Find the k-th node from the end
    ListNode* right = KthFromEnd(head, k);
    if (right == NULL) {
        return head; // If k is invalid, return the original list
    }

    // Swap the values of the two nodes
    int temp = left->val;
    left->val = right->val;
    right->val = temp;

    return head;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating a sample linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    head = swapNodes(head, k);

    cout << "List after swapping " << k << "-th node from start and end: ";
    printList(head);

    return 0;
}
