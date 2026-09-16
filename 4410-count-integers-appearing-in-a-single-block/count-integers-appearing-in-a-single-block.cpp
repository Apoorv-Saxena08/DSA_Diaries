class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i = 0; i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int c = 0;
        for(auto it : mp){
            int m = it.second.size();
            bool flag = true;
            for(int j = 0 ; j<m-1;j++){
                if(it.second[j]+1 != it.second[j+1]){
                    flag = false;
                    break;
                }
            }
            if(flag)c++;
        }
        return c;
    }
};