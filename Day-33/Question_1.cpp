#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isUnivalTree(TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    if (!isUnivalTree(root->left) || !isUnivalTree(root->right)) {
        return false;
    }
    if (root->left != NULL && root->val != root->left->val) {
        return false;
    }
    if (root->right != NULL && root->val != root->right->val) {
        return false;
    }
    return true;
}

int main() {
    // Example tree:
    //      1
    //     / \
    //    1   1
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    root->right = new TreeNode(1);

    if (isUnivalTree(root))
        cout << "Tree is unival" << endl;
    else
        cout << "Tree is not unival" << endl;

    return 0;
}
