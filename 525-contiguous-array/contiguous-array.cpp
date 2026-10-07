class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size() , sum = 0 ;
        unordered_map<int , vector<int>> mp;
        int maxi = 0, zero = 0 , ones = 0;
        mp[0].push_back(-1);
        for(int i = 0 ; i < n ; i++){
            if(nums[i]==1){
                sum++;
                ones++;
            }else{
                sum--;
                zero++;
            }
            mp[sum].push_back(i);
        }

        for(auto it : mp){
            int m = it.second.size();
            if(m==1)continue;

            maxi = max(maxi , it.second[m-1] - it.second[0] );
        }
        //if(zero==ones)return n;
        return maxi;
    }
};