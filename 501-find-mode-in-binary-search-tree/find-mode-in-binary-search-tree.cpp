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
    void solve(vector<int>&nums ,TreeNode* root ){
        if(!root)return ;
        nums.push_back(root->val);
        solve(nums,root->left);
        solve(nums,root->right);        
    }

    vector<int> findMode(TreeNode* root) {
        vector<int>nums;
        solve(nums,root);
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int n : nums){
            mp[n]++;
        }
        int maxi = -1;
        for(auto it : mp){
            maxi = max(maxi , it.second);
        }
        //check the elems with maxi
        for(auto it : mp){
            if(it.second == maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};