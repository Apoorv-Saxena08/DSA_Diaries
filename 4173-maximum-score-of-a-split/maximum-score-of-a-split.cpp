class Solution {
public:
    long long min(int a , int b){
        if(a<b)return a;
        return b;
    }

    long long maximumScore(vector<int>& nums) {
        long long maxi = LLONG_MIN;
        int n = nums.size();
        vector<long long>pre(n,nums[0]);
        for(int i = 1 ; i<n;i++){
            pre[i] = pre[i-1]+nums[i];
        }

        vector<long long>suf(n,nums[n-1]);
        for(int i = n-2;i>=0;i--){
            suf[i] = min( (long long) nums[i] , suf[i+1]);
        }

        for(int i = 0 ; i<n-1;i++){
            long long p = pre[i] , m = suf[i+1];
            long long score = p - m;
            maxi = max(maxi , score);
        }
        return maxi;
    }
};