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
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHit=height(root->left);
    int rightHit=height(root->right);
    int currHit=max(leftHit,rightHit)+1;
    return currHit;
}
pair<int, int>diam2(Node* root){//O(n)
    if(root==NULL){
        return make_pair(0,0);
    }
    pair<int, int>leftInfo=diam2(root->left); //(LD,LH)
    pair<int, int>rightInfo=diam2(root->right);//(RD,RH)

    int currDiam=leftInfo.second+rightInfo.second+1;
    int finalDiam=max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHt=max(leftInfo.second,rightInfo.second)+1;
    return make_pair(finalDiam,finalHt);
}
int main(){
    vector<int> nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root=buildTree(nodes);//1
    
    cout<<"Height = "<<height(root)<<endl;
    cout<<"Diameter = "<<diam2(root).first<<endl; // 5
    return 0;
}