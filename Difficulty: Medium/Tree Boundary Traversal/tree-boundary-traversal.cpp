/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solveLeft(Node *root , vector<int>&ans){
        if(!root)return;
        
        if(root->left){
            ans.push_back(root->data);
            solveLeft(root->left , ans);
        }
        else if(root->right){
            ans.push_back(root->data);
            solveLeft(root->right,ans);
        }
    }
    
    void solveLeaf(Node *root , vector<int>&ans){
        if(!root)return;
        
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        
        solveLeaf(root->left, ans);
        solveLeaf(root->right, ans);
        
    }
  
    void solveRight(Node *root , vector<int>&ans){
        if(!root)return;
        
        if(root->right){
            solveRight(root->right , ans);
            ans.push_back(root->data);
            
        }
        else if(root->left){
            solveRight(root->left,ans);
            ans.push_back(root->data);
            
        }
    }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(!root)return ans;
        
        if(root->left || root->right) 
            ans.push_back(root->data);
        
        solveLeft(root->left,ans);
        
        solveLeaf(root,ans);
        
        vector<int>rightPart;
        solveRight(root->right,rightPart);
        for(int val : rightPart){
            ans.push_back(val);
        }
        return ans;
    }
};