class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int maxLen = 1,start = 0;
        if(n<=1)return s;

        //lambda function usecase
        auto expand = [&](int left , int right){
            while(left>=0 && right<n && s[left] == s[right]){
                if(right-left+1 > maxLen){
                    maxLen = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for(int i = 0; i<n-1 ; i++){
            expand(i,i);//odd len
            expand(i,i+1);//even len
        }

        return s.substr(start,maxLen);
    }
};