class Solution {
public:
    int numOfWays(int n) {
        int same=6,diff=6;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            int new_same=(1LL*same*3+1LL*2*diff)%mod;
            int new_diff=(1LL*same*2+1LL*2*diff)%mod;
            same=new_same;
            diff=new_diff;
        }
        return (same+diff)%mod;
    }
};