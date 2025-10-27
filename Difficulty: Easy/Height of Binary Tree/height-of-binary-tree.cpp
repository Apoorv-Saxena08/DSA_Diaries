/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int solve(Node* root){
        if(!root)return 0;
        return 1+max(solve(root->left) , solve(root->right));
    }
  
    int height(Node* root) {
        // code here
        return solve(root)-1;
    }
};