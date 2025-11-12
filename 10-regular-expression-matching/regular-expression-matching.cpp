class Solution {
public:
    bool solve(int i , int j , string&s, string&p,vector<vector<int>>&dp){
        if(i>=s.length() && j>=p.length()){
            return true;
        }

        if(j>=p.length())return false;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //check for curr mathc
        bool currmatch = i<s.length() && ((s[i]==p[j]) || (p[j]=='.') );

        //check for next in pat
        if(j+1<p.length() && p[j+1]=='*'){
            //ya to take or skip
            bool ex = solve(i,j+2,s,p,dp);
            bool in = currmatch && solve(i+1,j,s,p,dp);
            return dp[i][j] = ex||in;
        }

        if(currmatch){
            return dp[i][j] = solve(i+1,j+1,s,p,dp);
        }else{
            return false;
        }
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(0,0,s,p,dp);
    }
};