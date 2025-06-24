#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* right;
    Node* left;

    Node(int val){
        data=val;
        left=right=NULL;
    }
};

static int idx=-1;

Node* buildTree(vector<int> pre){
    idx++;
    Node* root = new Node(pre[idx]);
    if(pre[idx]==-1) return NULL;
    root->left=buildTree(pre);
    root->right=buildTree(pre);
    return root;
}

int sumTree(Node* root){
    if(root==NULL) return 0;
    int ls=sumTree(root->left);
    int rs=sumTree(root->right);
    root->data += ls+rs;
    return root->data;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* tree = buildTree(preorder);
    cout << "root of sum tree: " << sumTree(tree);

    return 0;
}