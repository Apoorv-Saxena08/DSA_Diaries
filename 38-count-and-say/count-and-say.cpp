class Solution {
public:
    string solve(string s){
        int n = s.length();
        vector<pair<char,int>>freq;
        for(int i = 0 ; i<n ;){
            char ch = s[i];
            int count = 0;
            while(i<n && s[i]==ch){
                count++;
                i++;
            }
            freq.push_back({ch,count});
        }
        string ans = "";
        for(int i = 0 ; i<freq.size();i++){
            ans += to_string(freq[i].second);
            ans += freq[i].first;
        }
        return ans;
    }

    string countAndSay(int n) {
        string s = "1";
        if(n==1)return s;
        string ans ;
        for(int i = 2 ; i<=n ; i++){
            s = solve(s);
            if(i==n){
                ans = s;
                break;
            }
        }
        return ans;
    }
};