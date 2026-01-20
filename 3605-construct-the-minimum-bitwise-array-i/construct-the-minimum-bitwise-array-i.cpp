class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int n : nums){
            if(n & 1){
                //odd
                int z = ((n+1) & ~n ) >> 1;
                ans.push_back(n & ~z);
            }else{
                //even 
                ans.push_back(-1);
            }
        }
        return ans;
    }
};