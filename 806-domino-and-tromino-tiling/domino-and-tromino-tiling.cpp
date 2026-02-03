class Solution {
public:
    const int mod = 1000000007;

    int solve(int n ){
        if(n<=2)return n;

        vector<int>dp(n+1,0);
        
        dp[n] = 1;
        dp[n-1] = 1;
        dp[n-2] = 2;
        for(int i = n-3 ; i>=0 ; i--){
            dp[i] =  (dp[i+1]*2 %mod + dp[i+3])%mod;
        }
        return dp[0];
    }

    int numTilings(int n) {
        //vector<int>dp(n+1,-1);
        return solve(n);
    }
};