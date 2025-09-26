#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0; // Base case: empty node
    
    if (root->val >= low && root->val <= high) {
        return root->val 
             + rangeSumBST(root->left, low, high) 
             + rangeSumBST(root->right, low, high);
    } 
    else if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    } 
    else { // root->val > high
        return rangeSumBST(root->left, low, high);
    }
}

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7, high = 15;
    cout << "Range Sum: " << rangeSumBST(root, low, high) << endl;

    return 0;
}
