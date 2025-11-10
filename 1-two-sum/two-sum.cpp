class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i = 0 ; i<n; i++){
            int reqsum = t-nums[i];
            if(mp.count(reqsum)){
                return {i,mp[reqsum]};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};