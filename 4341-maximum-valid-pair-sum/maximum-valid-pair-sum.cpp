class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size() ,ans = 0 ;
        for(int i = 0 ; i<n;i++){
            if(i >= k){
                ans = max(ans , nums[i] + nums[i-k]);
            }
            if(i > 0){
                nums[i] = max(nums[i] , nums[i-1]);
            }
        }
        return ans;
    }
};