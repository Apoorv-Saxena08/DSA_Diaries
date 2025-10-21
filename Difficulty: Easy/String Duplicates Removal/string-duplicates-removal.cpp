// User function template for C++
class Solution {
  public:
    string removeDuplicates(string &s) {
        // code here
        unordered_map<char,int>mp;
        for(char c : s){
            mp[c]++;
        }
        string result = "";
        for(int i = 0 ; i< s.length();i++){
            if(mp[s[i]]>=1){
                result += s[i];
                mp[s[i]] = 0;
            }
        }
        return result;
    }
};