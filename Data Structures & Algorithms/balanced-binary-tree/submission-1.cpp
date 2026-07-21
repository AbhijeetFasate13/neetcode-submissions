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
int maxDepth(TreeNode* root) {
        if(!root)return 0;
        int leftMaxDepth = maxDepth(root->left);
        if(leftMaxDepth==-1)return -1;
        int rightMaxDepth = maxDepth(root->right);
        if(rightMaxDepth==-1)return -1;
        if(abs(leftMaxDepth-rightMaxDepth)>1)return -1;
        return 1+max(leftMaxDepth,rightMaxDepth);
    }
public:
    bool isBalanced(TreeNode* root) {
        int height = maxDepth(root);
        return height!=-1;
    }
};
