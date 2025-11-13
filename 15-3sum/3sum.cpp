class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0 ; i<n;i++){
            //check if i is duplicate - skip it 
            if(i > 0 && nums[i] == nums[i-1])continue;

            int j = i+1;
            int k = n-1;

            while(j<k){
                int total = nums[i]+nums[j]+nums[k];
                if(total>0){
                    k--;
                }
                else if(total<0){
                    j++;
                }
                else{
                    //mil gya ek triplet
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    //skip duplicates
                    while(j<k && nums[j]==nums[j-1] ){
                        j++;
                    } while(j<k && nums[k]==nums[k+1] ){
                        k--;
                    }
                }
            }
            
        }
        return ans;
    }
};