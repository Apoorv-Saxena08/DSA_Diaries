class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0 ;
        for(int bitIdx = 0 ; bitIdx <= 31 ; bitIdx++){
            int count = 0 ;
            for(int i = 0 ; i< nums.size() ; i++){
                //check bit of each number
                if(nums[i] & (1<<bitIdx)){
                    count++;
                }
            }

            //agr count 3 ka multiple nhi h , set ith biy
            if(count%3==1){
                //set bit
                ans = ans | (1<<bitIdx);
            }
        }
        return ans;
    }
};