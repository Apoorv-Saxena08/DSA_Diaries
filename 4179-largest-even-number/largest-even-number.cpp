class Solution {
public:
    string largestEven(string s) {
        int n = s.length();
        int i = n-1;
        while(i>=0 && s[i]=='1' ){
            s.pop_back();
            i--;
        }
        return s;
    }
};