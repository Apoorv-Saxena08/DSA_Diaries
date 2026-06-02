class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() , i = n-2 , j = n-1;
        //rhs se 1st dec element dhundo 
        while(i>=0){
            if(nums[i] < nums[i+1]){
                break;
            }else{
                i--;
            }
        }
        //rhs se smallest elem dhundo i.e greater than 1st dec elem 
        if(i>=0){
            while(j>=0){
                if(nums[j] > nums[i]){
                    swap(nums[i] , nums[j]);
                    break;
                }else{
                    j--;
                }
            }
        }

        //reverse the sublist 
        reverse(nums.begin()+i+1 , nums.end());
    }
};