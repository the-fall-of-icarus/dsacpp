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

vector<int> inorder(Node* root){
    vector<int> ans;
    Node* curr = root;

    while(curr != NULL){
        if(curr->left == NULL){
            ans.push_back(curr->data);
            curr = curr->right;
        } else {
            // Find inorder predecessor
            Node* IP = curr->left;
            while(IP->right != NULL && IP->right != curr){
                IP = IP->right;
            }

            if(IP->right == NULL){
                IP->right = curr;
                curr = curr->left;
            } else {
                IP->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return ans;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* tree = buildTree(preorder);

    cout << "Morris Inorder Traversal: ";
    vector<int> result = inorder(tree);
    for(int val : result){
        cout << val << " ";
    }

    return 0;
}
