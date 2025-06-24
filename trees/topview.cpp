#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void topview(Node* root){
    queue<pair<Node* , int>> q;
    map<int, int> m; //Node value and horizontal distance
    q.push({root, 0});
    while(q.size() > 0){
        Node* curr=q.front().first;
        int currHD=q.front().second;
        q.pop();

        if(m.find(currHD) == m.end()){
            m[currHD] = curr->data;
        }

        if(curr->left != NULL){
            q.push({curr->left, currHD-1});
        }

        if(curr->right){
            q.push({curr->right, currHD+1});
        }
    }

    for(auto it: m){
        cout << it.second << " ";
    }

    cout << endl;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,6,-1,-1,7,-1,-1,5,-1,-1};
    Node* tree = buildTree(preorder);
    topview(tree);

    return 0;
}