class Solution {
public:
int maxi = 0;
    int solve(vector<int>& nums , int i,vector<int>&dp ){
        if(i>=nums.size()){
            return 0;
        }

        if(dp[i]!= -1)return dp[i];

        //pick
        int pick = nums[i] + solve(nums,i+2,dp);
        //int notpick 
        int notPick = solve(nums,i+1,dp);
        maxi = max(pick , notPick);
        return dp[i] = maxi;
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};