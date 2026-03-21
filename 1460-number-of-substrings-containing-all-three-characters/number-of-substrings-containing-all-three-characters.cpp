class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>count = {0,0,0};
        int j = 0 , n = s.length();

        int ans = 0 , res = 0;

        for(int i = 0 ; i<n;i++){
            count[s[i]-'a']++;

            while(j<n && count[0] && count[1] && count[2]){
                ans++;
                count[s[j]-'a']--;
                j++;
            }

            res += ans;
        }
        return res;

    }
};