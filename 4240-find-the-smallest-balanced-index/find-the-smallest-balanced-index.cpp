class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        long long sum = 0 , ind = -1 ;
        long long prod = 1;

        for(int i  :nums){
            sum += i;
        }

        for(int i = nums.size()-1;i>=0;i--){
            sum -= nums[i];
            if(sum==prod)return i;

            if(prod>sum/nums[i])break;

            prod*= nums[i];
        }

        return -1;
    }
};