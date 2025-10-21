class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int total = 0 ;
        for(int n : nums){
            if(total<0){//kadanes algo 
                total = 0 ;
            }
            total += n;
            ans = max(ans , total);
        }
        return ans ;
    }
};