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

Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(val <= root->data){
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

Node* buildBST(vector<int> arr){
    Node* root = NULL;

    for(int val: arr){
        root= insert(root, val);
    }
    return root;
}

bool search(Node* root, int key){
    if(root==NULL) return false;
    if(root->data == key) return true;

    if(key < root->data) return search(root->left, key);
    else return search(root->right, key);
}

int min(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int max(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty\n";
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}


int main(){
    vector<int> arr = {13,15,6,82,19,11,10,16};
    Node* tree = NULL; 
    tree = buildBST(arr); 
    cout << tree->data << endl;
    cout << tree->left->data << " ";
    cout << tree->right->data << endl;
    cout << "Is 3 present? : " <<search(tree, 3) << endl;
    cout << "Is 82 present? : " << search(tree, 82) << endl;
    cout << "Mininum in BST: " << min(tree) << endl ;
    cout << "Maximum in BST: " << max(tree) << endl;
    return 0;
}
