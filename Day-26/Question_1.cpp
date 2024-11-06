#include <iostream>
using namespace std;

class ListNode {
public:
    int data;
    ListNode* next;
    ListNode(int val) : data(val), next(NULL) {}
};

int getSize(ListNode* head) {
    int size = 0;
    while (head != NULL) {
        head = head->next;
        size++;
    }
    return size;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int m = getSize(headA);
    int n = getSize(headB);
    ListNode* t1 = headA;
    ListNode* t2 = headB;
    int diff = 0;

    // Advance the pointer of the longer list by the difference in lengths
    if (m >= n) {
        diff = m - n;
        for (int i = 0; i < diff; i++) {
            t1 = t1->next;
        }
    } else {
        diff = n - m;
        for (int i = 0; i < diff; i++) {
            t2 = t2->next;
        }
    }

    // Move both pointers together until they intersect or reach the end
    while (t1 != NULL && t2 != NULL && t1 != t2) {
        t1 = t1->next;
        t2 = t2->next;
    }

    // If they intersect, return the intersection node; otherwise, return NULL
    if (t1 == NULL) {
        return NULL;
    } else {
        return t1;
    }
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    // Creating two lists with an intersection
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(9);
    headA->next->next->next = common;

    ListNode* headB = new ListNode(4);
    headB->next = common;

    ListNode* intersection = getIntersectionNode(headA, headB);

    if (intersection) {
        cout << "Intersection at node with value: " << intersection->data << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    return 0;
}
