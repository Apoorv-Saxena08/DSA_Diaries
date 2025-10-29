class Solution {
public:

    bool solve(int n){
        return ((n & (n+1)) == 0 );
    }

    int smallestNumber(int n) {
        int ans ;
        for(int i = n ; i<=1023 ; i++){
            if(solve(i)){
                ans = i;
                break;
            }
        }
        return ans;
    }
};