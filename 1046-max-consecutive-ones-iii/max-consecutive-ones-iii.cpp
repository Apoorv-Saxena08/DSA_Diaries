class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int c = 0 ,  j = 0 , n = nums.size();
        int res = INT_MIN;

        for(int i =0 ; i<n;i++){
            if(nums[i] == 0)c++;
            //shrink

            while(c>k && j<n){
                if(nums[j]==0)c--;

                j++;
            }


            res = max(res,i-j+1);
        }

        return res == INT_MIN?( (c<=k)?n:0 ):res;
    }
};