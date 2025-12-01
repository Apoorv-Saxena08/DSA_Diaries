class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(k==0)return n;
        int value = nums[n-k];//piche se kth value
        //find lower bound of this value
        auto it = lower_bound(nums.begin(),nums.end(),value);
        return int(it- nums.begin());
    }
};