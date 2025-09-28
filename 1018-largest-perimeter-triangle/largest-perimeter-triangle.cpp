class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end() , greater<int>());
        int n  = nums.size();
        for(int len = 0 ; len<n-2;len++){
            if(nums[len+1] + nums[len+2] > nums[len]){
                return nums[len] + nums[len+1] + nums[len+2]; 
            }
        }
        return 0;
    }
};