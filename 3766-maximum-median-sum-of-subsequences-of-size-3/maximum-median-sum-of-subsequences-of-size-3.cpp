class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int total = n/3;
        long long ans = 0;
        int l = 0 , r = n-1;
        while(total--){
            r--;
            ans += nums[r];
            r--;
            l++;
            // nums.pop_back();
            // ans += nums.back();
            // nums.pop_back();
            // nums.erase(nums.begin()); // O(n)
        }
        return ans;
    }
};