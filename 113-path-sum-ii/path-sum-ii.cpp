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
    vector<vector<int>>ans;
    vector<int>temp;

    void solve(TreeNode* root, int ts){
        if(!root)return;

        temp.push_back(root->val);

        //agr leaf pr aa gye and value set h to push in ans
        if(!root->left && !root->right && root->val == ts){
            ans.push_back(temp);
        }

        solve(root->left,ts-root->val);
        solve(root->right,ts-root->val);
        
        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        if(!root)return ans;
        solve(root,ts);
        return ans;
    }
};