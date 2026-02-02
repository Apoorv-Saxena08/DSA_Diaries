class Solution {
public:
    string reverseByType(string s) {
        vector<char>abcd;
        vector<char>sp;
        int n = s.length();
        for(int i = 0 ; i<n ;i++){
            if(isalpha(s[i])){
                abcd.push_back(s[i]);
                s[i] = '.';
            }
            else{
                sp.push_back(s[i]);
                s[i] = '_';
            }
        }

        reverse(abcd.begin() , abcd.end());
        reverse(sp.begin() , sp.end());
        int j = 0, k =0;
        for(int i = 0 ; i<n;i++){
            if(s[i] == '.'){
                s[i] = abcd[j];
                j++;
            }
            else{
                s[i] = sp[k];
                k++;
            }
        }
        return s;
    }
};