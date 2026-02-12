class Solution {
public:

    int solve(vector<int>& nums, int i, int dir, int remove, vector<vector<vector<int>>>&dp){
        if(i == nums.size()-1)return 1;

        if(dp[i][dir][remove] != -1){
            return dp[i][dir][remove];
        }

        int take = 1 , nottake = 1;

        if((dir && nums[i]<nums[i+1]) || (!dir && nums[i]>nums[i+1]) ){
            take = 1+solve(nums,i+1,!dir,remove,dp); //without remove vala step tha y 
        }

        //with removal
        if(remove && i+2 <nums.size() && ((dir && nums[i]<nums[i+2]) || (!dir && nums[i]>nums[i+2]) )  ){
            nottake = 1 + solve(nums,i+2,!dir,remove-1,dp);
        }

        return  dp[i][dir][remove] = max(take , nottake);
    }

    int longestAlternating(vector<int>& nums) {
        int ans = 0;
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        //index , direction (0,1 for up or down expectation) , remove left or not
        for(int i = 0; i<nums.size();i++){
            ans = max(ans , solve(nums,i,1,1,dp));
            ans = max(ans , solve(nums,i,0,1,dp));
        }

        return ans;
    }
};