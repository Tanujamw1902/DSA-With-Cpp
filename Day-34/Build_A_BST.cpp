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

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);  // ✅ fix
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

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int arr[6] = {5, 1, 3, 4, 2, 7};   // inorder: 1 2 3 4 5 7
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}; // inorder: 1 3 4 5 6 8 10 11 14

    Node* root = buildBST(arr, 6);
    inorder(root);
    cout << endl;

    Node* root2 = buildBST(arr2, 9);
    inorder(root2);
    cout << endl;

    return 0;
}
