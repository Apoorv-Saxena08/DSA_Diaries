class Solution {
public:
    int f(int i, int j, bool chosen, vector<int>& nums1, vector<int>& nums2, vector<vector<vector<int>>> &dp){
        if(i >= nums1.size() or j >= nums2.size())
            return chosen ? 0 : -1e9;
        if(dp[i][j][chosen] != -1e9)
            return dp[i][j][chosen];
        int take = nums1[i] * nums2[j] + f(i+1, j+1, true, nums1, nums2, dp);
        int skipLeft = f(i+1, j, chosen, nums1, nums2, dp);
        int skipRight = f(i, j+1, chosen, nums1, nums2, dp);
        return dp[i][j][chosen] = max(take, max(skipLeft, skipRight));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<vector<int>>> dp(nums1.size(), vector<vector<int>>(nums2.size(), vector<int>(2, -1e9)));
        return f(0, 0, false, nums1, nums2, dp);
    }
};