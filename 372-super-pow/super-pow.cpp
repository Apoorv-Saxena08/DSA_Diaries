class Solution {
public:
    int modans(int val, int pow , int mod = 1337){
        long long res = 1;
        val %= mod;
        while(pow>0){
            if(pow%2){
                res = (res*val)%mod;
            }
            val = (val*val)%mod;
            pow = pow/2;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        int ans = 1 ;
        a = a%1337;
        int mod = 1337;
        for(int i = 0 ; i<b.size();i++){
            ans = (modans(ans,10,mod)*modans(a,b[i],mod))%1337;
        }
        return ans%1337;
    }
};