class Solution {
public:
    int solve(vector<int>& nums, int k){
        int l = 0 , r = 0 , odds = 0 , count = 0 , n = nums.size();
        if(k<0)return 0;
        for(r =0; r< n ; r++){
            if(nums[r]%2){
                odds++;
            }

            while(odds>k){
                if(nums[l]%2){
                    odds--;
                }
                l++;
            }

            count += (r-l+1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums , k) - solve(nums , k-1);
    }
};