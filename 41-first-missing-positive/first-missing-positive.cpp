class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>check(n);

        for(int i = 0 ; i<n;i++){
            if(nums[i]>0 && nums[i]<=n){
                check[nums[i]-1] = nums[i];
            }
        }

        for(int i = 0 ; i<n;i++){
            if(check[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};