class Solution {
public:
    bool solve(int i , int j , string&s, string&p){
        if(i>=s.length() && j>=p.length()){
            return true;
        }

        if(j>=p.length())return false;

        //check for curr mathc
        bool currmatch = i<s.length() && ((s[i]==p[j]) || (p[j]=='.') );

        //check for next in pat
        if(j+1<p.length() && p[j+1]=='*'){
            //ya to take or skip
            bool ex = solve(i,j+2,s,p);
            bool in = currmatch && solve(i+1,j,s,p);
            return ex||in;
        }

        if(currmatch){
            return solve(i+1,j+1,s,p);
        }else{
            return false;
        }
    }

    bool isMatch(string s, string p) {
        return solve(0,0,s,p);
    }
};