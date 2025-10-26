class Solution {
public:
    int solve(vector<int>& nums, int i ,int leftSum , int total){
        if(i == nums.size())return -1;

        int rightSum = total - leftSum - nums[i];
        if(leftSum == rightSum)return i;

        return solve(nums , i+1,leftSum+nums[i] , total);
    }

    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for(int n : nums)total += n;

        return solve(nums,0,0,total);
    }
};