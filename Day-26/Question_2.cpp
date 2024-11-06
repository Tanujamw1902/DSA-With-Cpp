#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode* pre = head;

    while (pre) {
        // Skip m nodes
        for (int i = 1; i < m && pre != NULL; ++i) {
            pre = pre->next;
        }
        if (pre == NULL) {
            return head;
        }

        // Start deleting next n nodes
        ListNode* cur = pre->next;
        for (int i = 0; i < n && cur != NULL; ++i) {
            ListNode* temp = cur;
            cur = cur->next;
            delete temp; // Free the memory
        }

        // Link the remaining part
        pre->next = cur;
        pre = cur;
    }
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
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    cout << "Original list: ";
    printList(head);

    int m = 2, n = 2;
    head = deleteNodes(head, m, n);

    cout << "List after deleting " << n << " nodes after every " << m << " nodes: ";
    printList(head);

    return 0;
}
