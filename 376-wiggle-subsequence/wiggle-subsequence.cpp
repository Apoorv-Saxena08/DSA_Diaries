class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size() , count , diff , prevdiff;
        if(n<2)return n;

        prevdiff = nums[1] - nums[0];
        count = (prevdiff != 0)?2:1;

        for(int i =2 ; i<n;i++){
            diff = nums[i]- nums[i-1];

            if( (diff > 0 && prevdiff<=0 ) ||
                (diff < 0 && prevdiff>=0 )
             ){
                count++;
                prevdiff = diff;
             }
        }

        return count;
    }
};