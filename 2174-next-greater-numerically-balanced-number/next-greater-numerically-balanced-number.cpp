class Solution {
public:
    bool possible(int n){
        int temp = n;
        unordered_map<int,int>mp;
        int rem;
        while(temp){
            rem = temp%10;
            mp[rem]++;
            temp /= 10;
        }
        for(auto&it:mp){
            if(it.first != it.second){
                return false;
            }
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int ans = 666666;
        if(n==0)return 1;
        if(n>=666666)return 1224444;
        for(int i = n+1 ; i<=666666;i++){
            if(possible(i)){
                ans = i;
                break;
            }
        } 
        return ans;
    }
};