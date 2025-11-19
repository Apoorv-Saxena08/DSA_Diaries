class Solution {
  public:
    int solve(int n , int r , vector<int>&dp){
        if(r==0)return 1;
        if(r==1)return n;
        if(r>n)return 0;

        if(dp[r] != -1)return dp[r];

        int prev = solve(n, r-1, dp);

        int num = n - r + 1;  
        int den = r;         

        // reduce fraction before multiplying
        int g1 = __gcd(num, den);
        num /= g1;
        den /= g1;

        int g2 = __gcd(prev, den);
        prev /= g2;
        den /= g2;

        // now safe from overflow
        return dp[r] = (prev * num) / den;
    }
  
    int nCr(int n, int r) {
        vector<int> dp(r+1, -1);
        return solve(n, r, dp);
    }
};
