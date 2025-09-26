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
    int height(TreeNode* root){
        if(!root)return 0;
        if(!root->left && !root->right)return 1;
        return 1 + max(height(root->left) , height(root->right));
    }

    bool solve(TreeNode* root){
        if(!root)return true;
        if(!root->left && !root->right)return true;
        int left = height(root->left);
        int right = height(root->right);
        int diff = abs(left - right);
        return (diff <= 1) && solve(root->left) && solve(root->right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        if(!root->left && !root->right)return true;
        return solve(root);
    }
};