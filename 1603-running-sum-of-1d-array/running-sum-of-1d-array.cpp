class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        //just want to make prefix sum array
        int n = nums.size();
        vector<int>pre(n);
        pre[0] = nums[0];
        for(int i = 1 ; i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }
        return pre;
    }
};