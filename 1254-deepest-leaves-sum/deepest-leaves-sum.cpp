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
    int deepestLeavesSum(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return root->val;

        vector<vector<int>>level;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            vector<int>temp;
            int sz = q.size();
            for(int i = 0 ; i<sz;i++){
                auto node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level.push_back(temp);
        }
        int sum = 0 ;
        auto last = level[level.size()-1];
        for(int i= 0 ;i<last.size();i++){
            sum += last[i];
        }
        return sum;
    }
};