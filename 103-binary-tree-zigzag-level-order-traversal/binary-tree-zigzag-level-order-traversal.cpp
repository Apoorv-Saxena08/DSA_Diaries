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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;

        TreeNode* temp = root;
        queue<TreeNode*>q;
        q.push(temp);
        while(!q.empty()){
            int size = q.size();
            vector<int>t;
            for(int i =0 ; i<size; i++){
                TreeNode* el = q.front();
                t.push_back(el->val);
                q.pop();
                if(el->left){
                    q.push(el->left);
                }
                if(el->right){
                    q.push(el->right);
                }
            }
            ans.push_back(t);
        }
        for(int i = 1 ; i<ans.size(); i= i+2){
            reverse(ans[i].begin() , ans[i].end());
        }
        return ans;
    }
};