class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0 , r = 0 , len = 0 , maxF = 0 ;
        vector<int>count(26,0);
        int n = s.length();
        while(r<n){
            count[s[r] - 'A']++;
            maxF = max(maxF ,count[s[r] - 'A'] );

            int size = r-l+1;
            while(((r-l+1)-maxF)>k){
                count[s[l]-'A']--;
                l++;

                //check maxF again
                maxF = 0 ;
                for(int i = 0 ; i<26 ; i++){
                    maxF = max(maxF , count[i]);
                }
            }
            
            len = max(len , r-l+1);

            r++;
        }
        return len;
    }
};