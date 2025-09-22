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

Node* insert(Node* root, int val) { // O(logn)
    if (root == NULL) {
        return new Node(val);   // ✅ fix
    }
    if (val < root->data) { // left subtree
        root->left = insert(root->left, val);
    } else { // right subtree
        root->right = insert(root->right, val);
    }
    return root;
}

Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}

void printPath(vector<int> path) {
    cout << "Path: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

void pathHelper(Node* root, vector<int> &path) {
    if (root == NULL) {
        return;
    }

    // include current node
    path.push_back(root->data);

    // leaf node
    if (root->left == NULL && root->right == NULL) {
        printPath(path);
        path.pop_back();
        return;
    }

    // recursive calls
    pathHelper(root->left, path);
    pathHelper(root->right, path);

    // backtrack
    path.pop_back();
}

void rootToLeafPath(Node* root) {
    vector<int> path;
    pathHelper(root, path);
}

int main() {
    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14}; 
    Node* root = buildBST(arr, 9);   // ✅ fix
    rootToLeafPath(root);
    return 0;
}
