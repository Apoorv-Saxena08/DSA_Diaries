class Solution {
public:
    bool valid(int num){
        int bit = num%2;
         num = num/2;
        while(num){
            int curr = num%2;
            if(curr != bit){
                return false;
            } 
            num /= 2;
        }
        return true;
    }

    int countMonobit(int n) {
        if(n==1){
            return 2;
        }

        int ans = 0;
        for(int i = 0 ; i<=n;i++){
            if(valid(i)){
                ans++;
            }
        }
        return ans;
    }
};