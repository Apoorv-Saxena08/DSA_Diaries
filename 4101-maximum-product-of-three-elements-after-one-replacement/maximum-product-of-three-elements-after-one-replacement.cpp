class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        const long long M = 100000; // replacement value

        long long one   = 1LL * nums[0] * nums[1] * M;
        long long two   = (nums[n-1] < 0 && nums[n-2] < 0) ? 
                          1LL * nums[n-1] * nums[n-2] * M : LLONG_MIN;
        long long three = (nums[n-1] < 0) ? 
                          1LL * nums[0] * nums[n-1] * (-M) : LLONG_MIN;
        long long four  = 1LL * nums[0] * nums[1] * nums[2];
        long long five  = 1LL * nums[n-1] * nums[n-2] * nums[0];
        long long six   = 1LL * nums[0] * nums[1] * (-M);

        return max({one, two, three, four, five, six});
    }
};
