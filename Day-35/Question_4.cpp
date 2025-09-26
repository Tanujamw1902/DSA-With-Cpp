#include <iostream>
using namespace std;

// BST Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

// Function to search for a value k in BST (excluding a given node)
bool search(Node* root, Node* temp, int k) {
    Node* c = root;
    while (c != NULL) {
        if (c->data == k && c != temp) {
            cout << "Pair Found: " << temp->data << " + " << c->data << " = " << k << endl;
            return true;
        } else if (k < c->data) {
            c = c->left;
        } else {
            c = c->right;
        }
    }
    return false;
}

// Function to find if there exists a pair with sum equal to target
bool isPairPresent(Node* root, Node* temp, int target) {
    if (temp == NULL) return false;

    // Check for current node
    if (search(root, temp, target - temp->data))
        return true;

    // Recur for left and right subtrees
    return isPairPresent(root, temp->left, target) || isPairPresent(root, temp->right, target);
}

// Wrapper function
bool findPairWithSum(Node* root, int target) {
    return isPairPresent(root, root, target);
}

// Example usage
int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    int target = 28;

    if (!findPairWithSum(root, target)) {
        cout << "No pair found with sum " << target << endl;
    }

    return 0;
}
