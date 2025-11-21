class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)return false;
        if(n==1)return 1;
        vector<int>val = {2,3,5};

        for(int p : val){
            while(n%p == 0){
                n /= p;
            }
        }

        return n==1;
    }
};