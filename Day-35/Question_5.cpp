#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper class to store subtree information
class nodeValue {
public:
    int minVal;
    int maxVal;
    int sum;
    nodeValue(int minVal, int maxVal, int sum) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->sum = sum;
    }
};

class Solution {
public:
    int ans = 0;

    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }

    nodeValue helper(TreeNode* root) {
        if (!root) return nodeValue(INT_MAX, INT_MIN, 0); // Empty tree is BST

        nodeValue l = helper(root->left);
        nodeValue r = helper(root->right);

        // Check if current tree is BST
        if (root->val > l.maxVal && root->val < r.minVal) {
            int currSum = root->val + l.sum + r.sum;
            ans = max(ans, currSum);
            return nodeValue(min(root->val, l.minVal), max(root->val, r.maxVal), currSum);
        }

        // If not BST, return invalid range, but keep max sum from children
        return nodeValue(INT_MIN, INT_MAX, max(l.sum, r.sum));
    }
};

// Example usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(6);

    Solution sol;
    cout << "Maximum Sum BST in Tree: " << sol.maxSumBST(root) << endl;

    return 0;
}
