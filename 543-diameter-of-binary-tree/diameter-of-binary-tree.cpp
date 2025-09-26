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
    int diameter = 0 ;
    int solve(TreeNode* root){
        if(!root)return 0;

        int lefth = solve(root->left);
        int righth = solve(root->right);
        
        diameter = max(diameter,lefth+righth);

        return 1+max(lefth , righth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        solve(root);
        return diameter;
    }
};