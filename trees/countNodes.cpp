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

int count(Node* root){
    if(root==NULL) return 0;
    int lc=count(root->left);
    int rc=count(root->right);
    return lc+rc+1;
}

int sum(Node* root){
    if(root==NULL) return 0;
    int ls=sum(root->left);
    int rs=sum(root->right);
    return ls+rs+root->data;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* tree = buildTree(preorder);
    cout << tree->data << endl;
    cout << tree->left->data << " " << tree->right->data << endl;
    cout << "Total Nodes in the tree: " << count(tree) << endl;
    cout << "Sum of all nodes: " << sum(tree) << endl;

    return 0;
}