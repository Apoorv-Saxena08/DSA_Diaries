class Solution {
public:
    int cp(string s , int left , int right){
        int count = 0 ;

        while(left>=0 && right<s.length() && s[left]==s[right]){
            count++;
            left--;
            right++; // we are considering from mid then expanding it 
        }
        return count;
    }

    int countSubstrings(string s) {
        int n = s.length();
        int count = 0 ;
        for(int i = 0 ; i<n ; i++){
            count += cp(s,i,i);//odd len
            count += cp(s,i,i+1);//even len
        }
        return count;
    }
};