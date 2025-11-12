class Solution {
public:
    vector<string>all;

    void expand(string s , int l , int r ){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            all.push_back(s.substr(l,r-l+1));
            l--;
            r++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1,start = 0;
        if(n<=1)return s;
        int maxi = INT_MIN;
        for(int i = 0; i<n-1 ; i++){
            expand(s,i,i);//odd len
            expand(s,i,i+1);//even len
        }
        string ans ;
        for(auto it : all){
            int len = it.length();
            if(len>maxi){
                maxi = len;
                ans = it;
            }
        }
        return ans;

        return s.substr(start,maxLen);
    }
};