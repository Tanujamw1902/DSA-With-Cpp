#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};
static int idx =- 1;
Node* buildTree(vector<int> nodes){
    idx++;
    if(nodes[idx]== -1){
        return NULL;
    }
    Node* currNode=new Node(nodes[idx]);
    currNode->left=buildTree(nodes);//left subtree
    currNode->right=buildTree(nodes);// right subtree
    return currNode;
}
bool isSubtree(Node* root, Node* subRoot){
    if(root->data==subRoot->data){
        return isIdentical(root,subRoot){
            return true;
        }
    }
    int isLeftSubtree = isSubtree(root->left,subRoot);
    if(!isLeftSubtree){
        isSubtree(root->right,subRoot);
    }
    return true;
}
bool isIdentical(Node* root1,Node* root2){
    if(root1 = NULL && root2 = NULL){
        return true;
    }else if(root1==NULL|| subRoot == NULL){
        return false;
    }if(root1->data != root2->data){
        return false;
    }
    return isIdentical(root1->left,root2->left)&&
            isIdentical(root1->right,root2->right);
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);//1
    
    Node* subRoot=new Node(2);
    subRoot->left=new Node(4);
    subRoot->right=new Node(5);
    return 0;
}