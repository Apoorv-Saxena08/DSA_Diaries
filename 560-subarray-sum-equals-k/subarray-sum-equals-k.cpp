class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp; // sum : freq
        mp[0] = 1;

        int count = 0 , sum = 0;
        for(int x : nums){
            sum += x;

            if(mp.count(sum-k)){
                //agr exist krtah 
                count += mp[sum-k];
            }

            mp[sum]++;
        }

        return count;
    }
};