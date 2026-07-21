/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxDepth(TreeNode* root, int& diameter) {
        if(!root)return 0;
        int leftMaxDepth = maxDepth(root->left,diameter);
        int rightMaxDepth = maxDepth(root->right,diameter);
        diameter = max(diameter, leftMaxDepth+rightMaxDepth);
        return 1+max(leftMaxDepth,rightMaxDepth);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int height = maxDepth(root,diameter);
        return diameter;
    }
};
