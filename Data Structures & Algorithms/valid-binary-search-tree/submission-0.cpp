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
    void inorder(TreeNode* root, TreeNode*& prev, bool& ans) {
        if (!root || !ans) return;

        inorder(root->left, prev, ans);

        if (prev && prev->val >= root->val) {
            ans = false;
            return;
        }

        prev = root;

        inorder(root->right, prev, ans);
    }

public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        bool ans = true;
        inorder(root, prev, ans);
        return ans;
    }
};