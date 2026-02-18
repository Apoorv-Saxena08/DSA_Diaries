class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0 , r = 0 , maxi = 0 , n = s.length();
        unordered_set<char>st;
        if(n==0)return 0;

        while(r<n){
            int len = r-l+1;
            if(st.find(s[r]) == st.end()){
                maxi = max(maxi , len);
                st.insert(s[r]);
                r++;
            }else{
                st.erase(s[l]);
                l++;
            }
        }

        return maxi;
    }
};