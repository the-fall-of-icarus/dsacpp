#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

Node* buildTree(vector<int>& pre) {
    idx++;
    if (pre[idx] == -1) return NULL;
    Node* root = new Node(pre[idx]);
    root->left = buildTree(pre);
    root->right = buildTree(pre);
    return root;
}

void kthlevel(Node* root, int k) {
    if (root == NULL) return;
    if (k == 1) {
        cout << root->data << " ";
        return;
    }
    kthlevel(root->left, k - 1);
    kthlevel(root->right, k - 1);
}

int main() {
    vector<int> preorder = {1,2,3,7,-1,-1,-1,-1,4,-1,-1,5,-1,-1};
    idx = -1;  // Reset before building the tree
    Node* tree = buildTree(preorder);
    kthlevel(tree, 2);
    cout<< endl;
    kthlevel(tree, 4);
    return 0;
}
