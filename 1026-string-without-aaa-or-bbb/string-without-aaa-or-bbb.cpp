class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s = "";

        while(a>0 || b>0){
            int n = s.size();
            //last 2 char
            if( n>=2 && s[n-1] == s[n-2]){
                if(s[n-1] == 'a'){
                    s += "b";
                    b--;
                }else{
                    s += "a";
                    a--;
                }
            }else{
                //check greedily 
                if(a>=b){
                    s+= "a";
                    a--;
                }else{
                    s+= "b";
                    b--;
                }
            }
        }
        return s;
    }
};