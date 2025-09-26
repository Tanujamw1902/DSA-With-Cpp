#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to perform in-order traversal and find kth smallest
int search(TreeNode* root, int &K) {
    if (root == NULL) return -1;

    // Search in left subtree
    int leftVal = search(root->left, K);
    if (leftVal != -1) return leftVal;

    // Visit current node
    K--;
    if (K == 0) return root->val;

    // Search in right subtree
    return search(root->right, K);
}

// Function to return kth smallest element in BST
int kthSmallest(TreeNode* root, int k) {
    return search(root, k);
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    int k = 3;
    cout << "The " << k << "rd smallest element is " << kthSmallest(root, k) << endl;

    return 0;
}
