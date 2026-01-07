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
    long long mx = LLONG_MIN;
    static const int MOD = 1000000007;

    int maxProduct(TreeNode* root) {
        long long sum = totalSum(root);
        dfs(root, sum);
        return (int)(mx % MOD);
    }

    long long dfs(TreeNode* root, long long sum) {
        if (!root) return 0;

        long long left = dfs(root->left, sum);
        long long right = dfs(root->right, sum);
        long long currSum = left + right + root->val;

        mx = max(mx, (sum - currSum) * currSum);
        return currSum;
    }

    long long totalSum(TreeNode* root) {
        if (!root) return 0;
        return totalSum(root->left) + totalSum(root->right) + root->val;
    }
};