#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    // Check for cases where length is 0, 1, or 2
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }

    ListNode* evenStart = head->next; // Start of the even-indexed nodes
    ListNode* odd = head;              // Pointer for odd-indexed nodes
    ListNode* even = head->next;       // Pointer for even-indexed nodes

    // Reorganize nodes by separating odd and even nodes
    while (odd->next != NULL && even->next != NULL) {
        odd->next = even->next;        // Link the next odd node
        odd = odd->next;               // Move to the next odd node
        even->next = odd->next;        // Link the next even node
        even = even->next;             // Move to the next even node
    }

    odd->next = evenStart; // Attach even list at the end of odd list
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

    // Applying oddEvenList function
    head = oddEvenList(head);

    cout << "List after arranging odd and even nodes: ";
    printList(head);

    return 0;
}
