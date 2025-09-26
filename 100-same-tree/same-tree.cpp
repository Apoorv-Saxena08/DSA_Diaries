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
    bool value = true;

    void solve(TreeNode* p , TreeNode* q){
        if(!p && !q){
            //dono nhi h 
            value = true;
            return;
        }
        else if((!p && q)  || (p && !q) ){
            // 1 koisa nhi h 
            value = false;
            return;
        }
        else if(p->val == q->val){
            //root same ho gya aage k liye dekhlo
            solve(p->left , q->left);
            if(value == false)return;
            solve(p->right , q->right);
            if(value == false)return;
        }
        else{
            //root alg ho gya set false
            value = false;
            return;
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        if((!p && q)  || (p && !q) )return false;
        solve(p,q);
        return value;
    }
};