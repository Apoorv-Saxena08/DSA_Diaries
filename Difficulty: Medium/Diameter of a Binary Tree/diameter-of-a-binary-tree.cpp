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

// class Solution {
//   public:
//     int solve(Node* root , int &res){
//         if(root == nullptr)return 0;
        
//         int left  = solve(root->left , res);
//         int right  = solve(root->right , res);
        
//         int temp = 1 + max(left,right);
//         int ans =  1 + left + right;
//         res = max(res,ans);
//         return temp;
//     }
  
//     int diameter(Node* root) {
//         // code here
//         int res = 0;
//         solve(root,res);
//         return res;
//     }
// };

class Solution {
  public:
    int solve(Node* root, int &res) {
        if (root == nullptr) return 0;
        
        int left = solve(root->left, res);
        int right = solve(root->right, res);
        
        int temp = 1 + max(left, right);
        int ans = 1 + left + right;
        
        res = max(res, ans);  // ✅ keep global max diameter
        return temp;
    }
  
    int diameter(Node* root) {
        int res = 0;          // ✅ initialize to 0
        solve(root, res);
        return res-1;
    }
};
