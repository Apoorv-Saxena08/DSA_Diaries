class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        while(n){
            int rem = n%10;
            mp[rem]++;
            n /=10;
        }

        int ans = 0 ;
        for(auto it : mp){
            ans += it.first * it.second;
        }
        return ans;
    }
};