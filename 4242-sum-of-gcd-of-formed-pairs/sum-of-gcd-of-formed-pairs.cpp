class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int>pre(n,nums[0]);
        int maxi = nums[0];
        for(int i=1;i<n;i++){
            maxi = max(maxi , nums[i]);
            pre[i] = gcd(maxi,nums[i]);
        }
        if(n==1)return 0;

        sort(pre.begin(),pre.end());
        int len = pre.size()/2;
        int l = 0 , r=n-1;

        while(l<len){
            int g = gcd(pre[l],pre[r]);
            ans += g;
            l++;r--;
        }

        return ans;
    }
};