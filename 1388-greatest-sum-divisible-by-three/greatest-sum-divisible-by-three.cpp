class Solution {
public:
    int solve(vector<int>& nums, int i, int r, vector<vector<int>>& dp) {
        if (i == nums.size()) {
            return (r == 0 ? 0 : INT_MIN); 
        }

        if (dp[i][r] != -1) return dp[i][r];

        // pick nums[i]
        int pick = nums[i] + solve(nums, i + 1, (r + nums[i]) % 3, dp);

        // not pick nums[i]
        int notpick = solve(nums, i + 1, r, dp);

        return dp[i][r] = max(pick, notpick);
    }

    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(3, -1));
        int ans = solve(nums, 0, 0, dp);
        return max(ans, 0);  
    }
};
