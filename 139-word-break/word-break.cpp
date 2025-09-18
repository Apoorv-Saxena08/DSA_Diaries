class Solution {
public:
    bool solve(int start ,string s ,unordered_set<string>&st ,unordered_map<int,bool>&memo){
        if(start==s.length()){
            return true;
        }
        if(memo.count(start))return memo[start];

        string temp = "";
        for(int end = start ; end< s.length() ;end++){
            temp += s[end];
            if(st.count(temp)){
                if(solve(end+1,s,st,memo)){
                    return memo[start] = true;
                }
            }
        }
        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& dict) {
        unordered_set<string> st(dict.begin(),dict.end());
        unordered_map<int,bool> memo;
        return solve(0,s,st,memo);
    }
};