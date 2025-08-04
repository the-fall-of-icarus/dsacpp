#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void helper(TreeNode* root, vector<int>& result) {
    if (root == NULL) return;
    helper(root->left, result);
    result.push_back(root->data);
    helper(root->right, result);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    helper(root, ans);
    return ans;
}

TreeNode* buildBST(vector<int> arr) {
    TreeNode* root = NULL;
    for (int val : arr) {
        root = insert(root, val);
    }
    return root;
}

vector<int> merge(TreeNode* root1, TreeNode* root2) {
    vector<int> arr1 = inorderTraversal(root1);
    vector<int> arr2 = inorderTraversal(root2);
    vector<int> temp;

    int i = 0, j = 0;
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            temp.push_back(arr1[i]);
            i++;
        } else {
            temp.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        temp.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        temp.push_back(arr2[j]);
        j++;
    }

    return temp;
}

int main() {
    vector<int> arr1 = {5, 3, 8, 1};
    vector<int> arr2 = {7, 2, 6, 9};

    TreeNode* root1 = buildBST(arr1);
    TreeNode* root2 = buildBST(arr2);

    vector<int> mergedInorder = merge(root1, root2);

    cout << "Merged inorder traversal of both BSTs: ";
    for (int val : mergedInorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
