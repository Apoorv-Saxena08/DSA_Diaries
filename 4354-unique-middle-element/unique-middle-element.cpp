class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(101,0);
        for(int &i : nums){
            arr[i]++;
        }
        return arr[nums[n/2]] == 1;
    }
};