#include <iostream>
#include <vector>
#include <queue>
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

static int idx = -1;

// Build tree from preorder vector (-1 means NULL)
Node* buildTree(vector<int> nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }
    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // left subtree
    currNode->right = buildTree(nodes); // right subtree
    return currNode;
}

// Transform into sum tree
int transform(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;
    if (root->left != NULL) {
        root->data += root->left->data;
    }
    if (root->right != NULL) {
        root->data += root->right->data;
    }

    return currOld;
}

// Level order traversal
void levelorder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            Node* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes); // Build tree
    transform(root);               // Transform into sum tree
    levelorder(root);               // Print transformed tree
    return 0;
}
