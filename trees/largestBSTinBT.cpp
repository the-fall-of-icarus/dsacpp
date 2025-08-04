#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    struct Info {
        bool isBST;
        int size;
        int minVal;
        int maxVal;

        Info(bool isBST, int size, int minVal, int maxVal)
            : isBST(isBST), size(size), minVal(minVal), maxVal(maxVal) {}
    };

    int maxBSTSize = 0;

    Info dfs(TreeNode* root) {
        if (!root) {
            return Info(true, 0, INT_MAX, INT_MIN);
        }

        Info left = dfs(root->left);
        Info right = dfs(root->right);

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            int currSize = left.size + right.size + 1;
            maxBSTSize = max(maxBSTSize, currSize);
            return Info(true, currSize, min(root->val, left.minVal), max(root->val, right.maxVal));
        }

        return Info(false, max(left.size, right.size), 0, 0);
    }

    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return maxBSTSize;
    }
};

// Helper to build a sample tree
TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    Solution sol;
    int result = sol.largestBSTSubtree(root);
    cout << "Size of the largest BST is: " << result << endl;
    return 0;
}
