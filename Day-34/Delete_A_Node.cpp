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
        return new Node(val);
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

Node* getInorderSuccessor(Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node* delNode(Node* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    
    if (val < root->data) {
        root->left = delNode(root->left, val);
    } 
    else if (val > root->data) {
        root->right = delNode(root->right, val);
    } 
    else {
        // root->data == val

        // Case 1: 0 children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: 1 child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data);
    }
    return root;
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = buildBST(arr, 9); // ✅ pass full array size

    inorder(root);
    cout << endl;

    root = delNode(root, 4); // ✅ assign back after deletion
    inorder(root);
    cout << endl;

    return 0;
}
