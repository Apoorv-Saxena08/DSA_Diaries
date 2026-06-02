class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() , maxi = INT_MIN;
        int sum = 0;
        for(int i = 0 ; i<n;i++){
            sum += nums[i];
            if(sum < 0){
                sum = 0 ;
                continue;
            }else{
                maxi = max(maxi , sum);
            }
        }
        if(maxi == INT_MIN){
            return *max_element(nums.begin() , nums.end());
        }
        
        return maxi;
    }
};