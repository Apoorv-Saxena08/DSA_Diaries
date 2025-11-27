class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        //make prefix sum
        int n = nums.size();
        vector<long long>pref(n+1,0);
        for(int i = 1; i<=n;i++){
            pref[i] = pref[i-1]+nums[i-1];
        }
        vector<long long>best(k,LLONG_MAX);
        best[0] = pref[0];
        long long ans = LLONG_MIN;

        for(int x =1 ; x<=n;x++){
            int mod = x%k;
            if(best[mod] != LLONG_MAX){
                ans = max(ans,pref[x]-best[mod]);
            }
            best[mod] = min(best[mod],pref[x]);
        }
        return ans;
    }
};