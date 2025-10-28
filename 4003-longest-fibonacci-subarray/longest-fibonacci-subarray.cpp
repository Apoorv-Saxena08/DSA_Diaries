class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 2;
        int curr= 2;
        for(int i = 2 ; i<n;i++){
            if(nums[i] == (nums[i-1]+nums[i-2]) ){
                curr++;
                maxi = max(maxi,curr);
            }
            else{
                curr = 2;
            }
        }
        return maxi;
    }
};