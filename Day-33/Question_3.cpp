#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    if (root == NULL)
    {
        return NULL;
    }

    TreeNode *left = removeLeafNodes(root->left, target);
    TreeNode *right = removeLeafNodes(root->right, target);

    // If both children are NULL and node value is target → remove it
    if (left == NULL && right == NULL && root->val == target)
    {
        return NULL;
    }

    root->left = left;
    root->right = right;
    return root;
}

// Helper function to print tree in-order
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    /*
         1
        / \
       2   3
      /   / \
     2   2   4
    */
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    cout << "Original tree (Inorder): ";
    inorder(root);
    cout << endl;

    int target = 2;
    root = removeLeafNodes(root, target);

    cout << "After removing leaf nodes with value " << target << " (Inorder): ";
    inorder(root);
    cout << endl;

    return 0;
}
