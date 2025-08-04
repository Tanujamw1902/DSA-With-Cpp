#include<iostream>
#include<vector>
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

// Build Tree (from preorder with -1 for NULLs)
static int idx = -1;
Node* buildTree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);
    return currNode;
}

// Check if two trees are identical
bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    if (root1 == NULL || root2 == NULL) {
        return false;
    }
    if (root1->data != root2->data) {
        return false;
    }
    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

// Check if subRoot is a subtree of root
bool isSubtree(Node* root, Node* subRoot) {
    if (root == NULL) return false;

    if (root->data == subRoot->data) {
        if (isIdentical(root, subRoot)) {
            return true;
        }
    }

    return isSubtree(root->left, subRoot) ||
            isSubtree(root->right, subRoot);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    // Creating subtree manually: subRoot = [2, 4, 5]
    Node* subRoot = new Node(2);
    subRoot->left = new Node(4);
    subRoot->right = new Node(5);

    if (isSubtree(root, subRoot)) {
        cout << "subRoot is a subtree of root" << endl;
    } else {
        cout << "subRoot is NOT a subtree of root" << endl;
    }

    return 0;
}
