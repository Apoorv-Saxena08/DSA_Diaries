class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum = 0 , i = 0 ;
        while(i<nums.size()){
            sum += nums[i];
            i = i +2;
        }
        return sum;
    }
};