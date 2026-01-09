class Solution {
public:
    long long solve(vector<vector<int>>& q , int i,vector<long long>&dp ){
        if(i>=q.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        long long inc = q[i][0] + solve(q,i+1+q[i][1],dp);
        long long exc = solve(q,i+1,dp);

        long long maxi = max(inc,exc);
        return dp[i] = maxi;
    }

    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long>dp(n,-1);
        return solve(q,0,dp);
    }
};