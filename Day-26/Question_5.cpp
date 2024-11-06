#include <iostream>
#include <vector>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted lists
ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* merged = new ListNode(-1);  // Dummy node
    ListNode* mptr = merged;
    ListNode* left = list1;
    ListNode* right = list2;

    // Merge the lists
    while (left != NULL && right != NULL) {
        if (left->val <= right->val) {
            mptr->next = left;
            mptr = mptr->next;
            left = left->next;
        } else {
            mptr->next = right;
            mptr = mptr->next;
            right = right->next;
        }
    }

    // Attach any remaining elements
    if (left != NULL) {
        mptr->next = left;
    }
    if (right != NULL) {
        mptr->next = right;
    }

    return merged->next;  // Return head of merged list
}

// Function to merge K sorted lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) {
        return NULL;
    }
    if (lists.size() == 1) {
        return lists[0];
    }

    ListNode* head = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        head = merge(head, lists[i]);
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
    // Creating example lists
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    // Adding lists to vector
    vector<ListNode*> lists = {list1, list2, list3};

    // Merging K lists
    ListNode* result = mergeKLists(lists);

    // Printing merged list
    cout << "Merged K lists: ";
    printList(result);

    return 0;
}
