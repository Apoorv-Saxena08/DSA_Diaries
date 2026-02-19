class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int>ans;
        int res = 0;
        int curr = s[0];
        int c =1;
        int n = s.length();
        for(int i =1;i<n;i++){
            if(curr == s[i]){
                c++;
            }else{
                curr = s[i];
                ans.push_back(c);
                c=1;
            }
        }
        ans.push_back(c);

        for(int i = 0 ; i<ans.size()-1;i++){
            res += min(ans[i],ans[i+1]);
        }

        return res;
    }
};