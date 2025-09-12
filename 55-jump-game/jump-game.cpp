class Solution {
public:
    bool solve(vector<int>& nums , int i,vector<int>&dp ){
        if(i >= nums.size()-1){//max jump len di h , crossed or on last index
            return true;
        }
        
        if(nums[0] == 0)return false; // aage hi ni bd skte

        if(dp[i] != -1){
            return dp[i];
        }

        //try possible jumps from 1 to n
        for(int j =1 ; j <= nums[i];j++){
            if(solve(nums,i+j,dp)){
                //any path exists
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(nums,0,dp);
    }
};