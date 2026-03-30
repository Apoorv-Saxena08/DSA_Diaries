class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int num: nums)mp[num]++;

        int n = nums.size();

        for(auto it : mp){
            if(it.second > floor(n/3)){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};