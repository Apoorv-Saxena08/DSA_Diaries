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
    bool solve(TreeNode* t , TreeNode* s){
        if(!t && !s)return true;

        if(!t || !s)return false;
        
        return t->val == s->val && solve(t->left,s->left) && solve(t->right,s->right);
    }

    void find(TreeNode* &t , TreeNode* s , bool &found){
        if(!t || found)return ;
        if(solve(t,s)){
            found = true;
            return;
        }
        find(t->left,s,found);
        find(t->right,s,found);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool found = false;
        find(root,subRoot,found);
        return found;
    }
};