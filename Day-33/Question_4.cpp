#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to serialize subtree and detect duplicates
string duplicate(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& v) {
    if (root == NULL) return "";

    string a = duplicate(root->left, mp, v);
    string b = duplicate(root->right, mp, v);

    // Serialize subtree as "value,left_serial,right_serial"
    string temp = to_string(root->val) + "," + a + "," + b;

    mp[temp]++;
    if (mp[temp] == 2) { // Found duplicate for the first time
        v.push_back(root);
    }

    return temp;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, int> mp;
    vector<TreeNode*> v;
    duplicate(root, mp, v);
    return v;
}

// Helper: print a subtree (preorder)
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    /*
         1
        / \
       2   3
      /   / \
     4   2   4
        /
       4
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->left->left = new TreeNode(4);
    root->right->right = new TreeNode(4);

    vector<TreeNode*> duplicates = findDuplicateSubtrees(root);

    cout << "Duplicate Subtrees (Preorder Traversal):" << endl;
    for (auto node : duplicates) {
        preorder(node);
        cout << endl;
    }

    return 0;
}
