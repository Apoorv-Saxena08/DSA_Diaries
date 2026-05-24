class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i : nums){
            mp[i]++;
            if(mp[i]>k){
                mp[i]=k;
            }
        }
        vector<int>ans;
        for(auto it : mp){
            for(int i = 0 ; i < it.second;i++){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};