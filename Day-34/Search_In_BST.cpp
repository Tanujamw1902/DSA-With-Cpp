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
        return new Node(val);   // ✅ fix
    }
    if (val < root->data) { // left subtree
        root->left = insert(root->left, val);
    } else { // right subtree
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

bool search(Node* root, int key) { // O(Height); avg O(logn)
    if (root == NULL) {
        return false;
    }
    if (root->data == key) { // Found
        return true;
    }
    if (root->data > key) {
        return search(root->left, key); // left subtree
    } else {
        return search(root->right, key); // right subtree
    }
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}; 
    Node* root = buildBST(arr, 9);   // fix: use full array

    cout << search(root, 6) << endl;   // should print 1 (true)
    cout << search(root, 11) << endl;  // should print 1 (true)
    cout << search(root, 7) << endl;   // should print 0 (false)

    return 0;
}
