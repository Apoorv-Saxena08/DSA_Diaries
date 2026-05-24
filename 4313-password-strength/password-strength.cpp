class Solution {
public:
    int passwordStrength(string p) {
        set<char>st;
        for(char c :p ){
            st.insert(c);
        }
        int ans = 0 ;
        for(auto ch : st){
            if(ch >= 'a' && ch <= 'z'){
                ans++;
            }
            else if(ch >= 'A' && ch <= 'Z'){
                ans += 2;
            }
            else if(ch >= '0' && ch <= '9'){
                ans += 3;
            }
            else if(ch == '!' || ch == '@' || ch == '#' || ch == '$'){
                ans += 5;
            }
        }
        return ans;
    }
};