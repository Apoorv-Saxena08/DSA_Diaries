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
    
    int maxi = 0;

    void dfs(TreeNode* root,bool isLeft , int len){
        if(!root)return;
        maxi = max(maxi , len);

        if(isLeft){
            //go to right and increase length
            dfs(root->right,false,len+1);
            //vrna next left node se start kro
            dfs(root->left,true,1);
        }
        else{
            //go to left and inc len
            dfs(root->left,true,len+1);
            //check 
            dfs(root->right,false,1);
        }
    }

    int longestZigZag(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return 0;
        
        //left jane k liye lets say hum kehre h true , and r k liye false
        dfs(root,true,0);
        dfs(root,false,0);
        
        return maxi;
    }
};