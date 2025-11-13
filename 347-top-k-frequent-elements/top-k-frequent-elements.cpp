class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int n : nums){
            mp[n]++;
        }
        vector<pair<int,int>>all;
        for(auto it:mp){
            all.push_back({it.second,it.first});
        }
        sort(all.begin(),all.end(),greater<pair<int,int>>());
        vector<int>ans;
        int j = 0;
        for(int i = 0 ; i<k;i++){
            ans.push_back(all[j].second);
            j++;
        }

        return ans;
    }
};