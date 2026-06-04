class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto it : nums){
            if(mp[it]){
                return it;
            }else{
                mp[it]++;
            }
        }
        return 0;
    }
};