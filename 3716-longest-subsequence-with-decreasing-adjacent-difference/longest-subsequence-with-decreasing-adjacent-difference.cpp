class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<vector<int>>dp(301,vector<int>(301,0));
        int ans =0;
        int n = nums.size();
        for(int i = 0 ; i<n;i++){
            //outer loop iterate on elem - to maintain subseq order
            int num = nums[i];

            for(int diff = 299; diff>=0;diff--){
                int l = 0 , r = 0;
                if(num+diff <301){
                    l = dp[num+diff][diff];
                }
                if(num-diff >0){
                    r = dp[num-diff][diff];
                }

                dp[num][diff] = max(
                    dp[num][diff+1] , // slip this
                    1+ max(l,r) // extend subseq
                );

                ans = max(ans , dp[num][diff]);
            }

        }
        return ans;
    }
};