#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

// Definition for a BST node
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int x) : key(x), left(NULL), right(NULL) {}
};

// Utility function to find the key closest to k
void maxDiffUtil(Node* ptr, int k, int &min_diff, int &min_diff_key) {
    if (ptr == NULL) return;

    // If exact key found
    if (ptr->key == k) {
        min_diff_key = ptr->key;
        min_diff = 0;
        return;
    }

    // Update min_diff and min_diff_key if current node is closer
    if (abs(ptr->key - k) < min_diff) {
        min_diff = abs(ptr->key - k);
        min_diff_key = ptr->key;
    }

    // Recur down the BST
    if (k < ptr->key)
        maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
    else
        maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}

// Function to return the key in BST closest to k
int maxDiff(Node* root, int k) {
    int min_diff = INT_MAX;
    int min_diff_key = -1;
    maxDiffUtil(root, k, min_diff, min_diff_key);
    return min_diff_key;
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    int k = 12;
    cout << "Closest key to " << k << " is " << maxDiff(root, k) << endl;

    return 0;
}
