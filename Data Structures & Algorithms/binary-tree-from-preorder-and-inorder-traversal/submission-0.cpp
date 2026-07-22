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
   public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> inorderLeft, inorderRight;
        unordered_set<int>inLeft;
        int rootFound = 0;
        for (const int& i : inorder) {
            if (i == root->val) {
                rootFound = 1;
                continue;
            }
            if (!rootFound) {
                inorderLeft.push_back(i);
                inLeft.insert(i);
            } else {
                inorderRight.push_back(i);
            }
        }
        vector<int>preorderLeft,preorderRight;
        for(const int& i:preorder){
            if(i==root->val)continue;
            if(inLeft.count(i)){
                preorderLeft.push_back(i);
            }else{
                preorderRight.push_back(i);
            }
        }
        root->left = buildTree(preorderLeft,inorderLeft);
        root->right = buildTree(preorderRight, inorderRight);
        return root;
    }
};
