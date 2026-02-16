/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
            return root;

        queue<TreeNode*> q;
        q.push(root);

        int level = 0;

        while (!q.empty()) {
            int sz = q.size();
            if (level % 2 == 0) {
                for (int i = 0; i < sz; i++) {
                    auto node = q.front();
                    q.pop();
                    if (node->left) {
                        q.push(node->left);
                    }
                    if (node->right) {
                        q.push(node->right);
                    }
                }
                level++;
                continue;
            }
            vector<int> vals;
            vector<TreeNode*> nodes;
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                vals.push_back(node->val);
                nodes.push_back(node);
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            reverse(vals.begin(),vals.end());
            for (int i = 0; i < vals.size(); i++) {
                nodes[i]->val = vals[i];
            }
            level++;
        }

        return root;
    }
};