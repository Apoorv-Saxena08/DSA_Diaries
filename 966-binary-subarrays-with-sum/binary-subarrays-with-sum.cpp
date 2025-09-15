class Solution {
public:
    int countAns(vector<int>& nums, int goal) {
        if (goal < 0) return 0;  

        int l = 0, sum = 0, count = 0, n = nums.size();
        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            count += (r - l + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // count (goal) - count(goal -1)
        return countAns(nums, goal) - countAns(nums, goal - 1);
    }
};
