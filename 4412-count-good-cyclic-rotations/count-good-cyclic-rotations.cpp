class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        long long sum1 = 0  , sum2 =0;

        for(int i =0;i< n/2 ;i++){
            sum1 += nums[i];
        }
        
        for(int i =n/2;i< n ;i++){
            sum2 += nums[i];
        }

        for(int i = 0 ; i<n;i++){
            if(sum1>sum2)ans++;

            int mid = (i + (n/2))%n;

            sum1 += nums[mid];
            sum2 -= nums[mid];

            sum1 -= nums[i];
            sum2 += nums[i];
        }
        return ans;
    }
};