#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root, int& maxi) {
    if (root == NULL) {
        return 0;
    }
    
    int lh = max(0, height(root->left, maxi));   // Ignore negative paths
    int rh = max(0, height(root->right, maxi));  // Ignore negative paths
    
    maxi = max(maxi, lh + rh + root->val); // Update max path sum
    
    return root->val + max(lh, rh); // Return best path including current node
}

int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    height(root, res);
    return res;
}

// Helper: Inorder traversal to verify tree
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    /*
          -10
          /  \
         9   20
            /  \
           15   7
    */
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    return 0;
}
