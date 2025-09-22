class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int n : nums){
            mp[n]++;
        }
        int maxi = INT_MIN;
        for(auto it : mp){
            maxi = max(maxi , it.second);
        }
        int count = 0 ;
        for(auto it : mp){
            if(it.second == maxi){
                count += maxi;
            }
        }
        return count;
    }
};