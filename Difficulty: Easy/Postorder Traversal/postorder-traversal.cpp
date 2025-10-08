/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node* root , vector<int>&nums){
        if(!root)return;
        solve(root->left,nums);
        solve(root->right,nums);
        nums.push_back(root->data);
    }
  
    vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};