class Solution {
public:
    const int mod = 1000000007;

    int solve(int n , vector<int>&dp){
        if(n<3){
            return (n<2)?1:2;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] =  (solve(n-1,dp)*2%mod + solve(n-3,dp))%mod;
    }

    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};