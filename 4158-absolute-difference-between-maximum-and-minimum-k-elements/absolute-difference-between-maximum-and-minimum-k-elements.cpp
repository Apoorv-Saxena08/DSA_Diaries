class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int sumfirst = 0 , sumLast = 0 ;
        sort(nums.begin(),nums.end());
        for(int i =0;i<k;i++){
            sumfirst += nums[i];
        }
        int i = n-1;
        while(k--){
            sumLast += nums[i];
            i--;
        }
        return abs(sumfirst - sumLast);
    }
};