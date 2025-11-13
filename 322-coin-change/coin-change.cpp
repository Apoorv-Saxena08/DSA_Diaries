class Solution {
public:
    int solve(vector<int>& coins, int a){
        vector<int>dp(a+1,INT_MAX);
        dp[0] =0;
        
        for(int i = 1 ; i<=a;i++){
            for(int c : coins){
                if(i-c>=0 && dp[i-c]!= INT_MAX){
                    dp[i] = min(dp[i],1+dp[i-c]);
                }
            }
        }
        return dp[a] == INT_MAX?-1:dp[a];
    }

    int coinChange(vector<int>& coins, int a) {
        return solve(coins,a);
    }
};