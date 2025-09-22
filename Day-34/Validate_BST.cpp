#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) { // O(logn)
    if (root == NULL) {
        return new Node(val); // ✅ fix
    }
    if (val < root->data) { 
        root->left = insert(root->left, val);
    } else { 
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

bool validateHelper(Node* root, Node* min, Node* max) {
    if (root == NULL) return true;

    if (min != NULL && root->data <= min->data) return false; // ✅ fix
    if (max != NULL && root->data >= max->data) return false; // ✅ fix

    return validateHelper(root->left, min, root) &&
           validateHelper(root->right, root, max);
}

bool validateBST(Node* root) {
    return validateHelper(root, NULL, NULL);
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9);

    cout << "Before modification: " << validateBST(root) << endl; // should print 1

    root->data = 15; // break BST
    cout << "After modification: " << validateBST(root) << endl; // should print 0

    return 0;
}
