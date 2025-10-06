class Solution {
public:
    bool solve(int i , int j , string&s,string&p){
        if(i>=s.length() && j>=p.length())return true;
        //p khtm
        if(j>=p.length())return false;

        //s remain and .
        bool currmatch = i<s.length() && (p[j]=='.' || s[i]==p[j]);

        if(j+1<p.length() && p[j+1]=='*'){
            bool ex = solve(i,j+2,s,p);
            bool inc = currmatch && solve(i+1,j,s,p);
            return ex||inc;
        }

        if(currmatch){
            return solve(i+1,j+1,s,p);
        }
        else{
            return false;
        }

    }

    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
    }
};