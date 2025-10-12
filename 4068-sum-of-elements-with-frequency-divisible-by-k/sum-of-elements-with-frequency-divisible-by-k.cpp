class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int n : nums){
            mp[n]++;
        }

        int count = 0 ;
        for(auto it : mp){
            if(it.second%k==0)count += it.second*it.first;
        }
        return count;
    }
};