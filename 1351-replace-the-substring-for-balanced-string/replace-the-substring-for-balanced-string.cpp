class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        unordered_map<char,int>mp;

        for(auto&ch : s){
            mp[ch]++;
        }

        int ans = n ,l=0 ;
        int req = n/4;
        for(int r = 0 ; r<n;r++){
            mp[s[r]]--; //reduce shuru se krte chlo

            while(l<n &&
                mp['Q']<= req &&
                mp['E']<= req &&
                mp['R']<= req &&
                mp['W']<= req 
            ){
                ans = min(ans,r-l+1);
                mp[s[l]]++;
                l++;
            }
        }

        return ans;
    }
};