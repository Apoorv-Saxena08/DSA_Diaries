class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = target.size();
        unordered_set<int>ans;
        for (int i = 0; i < n; i++) {
            if(nums[i] != target[i]){
                ans.insert(nums[i]);
            }
        }
        return ans.size();
    }
};