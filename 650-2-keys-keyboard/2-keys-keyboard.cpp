class Solution {
public:
    int solve(int curr, int copy, int n, vector<vector<int>>& dp) {
        if (curr == n) return 0;
        if (curr > n) return 1e9;

        if (dp[curr][copy] != -1)
            return dp[curr][copy];

        int copyOp = 1e9;
        int pasteOp = 1e9;

        // Copy All
        if (copy != curr) {
            copyOp = 1 + solve(curr, curr, n, dp);
        }

        // Paste
        if (copy != 0) {
            pasteOp = 1 + solve(curr + copy, copy, n, dp);
        }

        return dp[curr][copy] = min(copyOp, pasteOp);
    }

    int minSteps(int n) {
        if (n == 1) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solve(1, 0, n, dp);
    }
};