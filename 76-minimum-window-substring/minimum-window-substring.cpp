class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() , m = t.size();
        unordered_map<char,int>mp;
        //step 1 map bnao
        for(char c : t){
            mp[c]++;
        }
        //step 2 variables;
        int l = 0 , count = m , minLen = INT_MAX , start = 0;

        //loop
        for(int r = 0 ; r<n;r++){
            if(mp[s[r]]>0){
                //char mila 
                count--;
            }
            mp[s[r]]--;

            //main cond
            while(count==0){
                //check len
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }

                //shrink
                mp[s[l]]++;
                if(mp[s[l]]>0){
                    count++;//leaving 
                }
                l++;
            }
        }

        return minLen == INT_MAX? "" : s.substr(start , minLen);
    }
};