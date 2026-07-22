class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> traversal;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> currLevel;

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                currLevel.push_back(node->val);

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);
            }

            traversal.push_back(currLevel);
        }

        return traversal;
    }
};