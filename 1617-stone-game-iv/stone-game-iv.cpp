class Solution {
public:
    vector<int> ps;

    bool solve(int n,vector<int>&dp) {
        if (n == 0) return false;

        if(dp[n] != -1){
            return dp[n];
        }

        for (int sq : ps) {
            if (sq > n) break;   
            // If opponent loses after this move, I win
            if (!solve(n - sq,dp)) {
                return dp[n] = true;
            }
        }

        // If all moves lead to opponent winning
        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        for (int i = 1; i * i <= n; i++) {
            ps.push_back(i * i);
        }
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
