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
    int sum = 0;
    
    // int calc(string num){
    //     reverse(num.begin(),num.end());
    //     int ans = 0;
    //     for(int i = 0;i<num.length();i++){
    //         ans += (num[i]-'0')*pow(2,i);
    //     }
    //     return ans;
    // }

    void preorder(TreeNode* root , int curr){
        if(!root)return;

         curr = curr*2+root->val;
        if(!root->left && !root->right){
            sum += curr;
            return;
        }

        preorder(root->left,curr);
        preorder(root->right,curr);
    }

    int sumRootToLeaf(TreeNode* root) {
        //string num = root->val + '0';
        preorder(root,0);
        return sum;
    }
};