class Solution {
public:
    void solve(string&digits , vector<string>&ans ,int index , string temp,unordered_map<char, string>&mp){
        if(index == digits.length()){
            ans.push_back(temp);
            return;
        }

        //find letters on the numbers
        string letters = mp.at(digits[index]);
        //characters jod do
        for(char letter : letters){
            solve(digits,ans,index+1,temp+letter,mp);
        } 
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string>ans;
        string temp="";
        if(n==0) return ans;

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        solve(digits,ans,0,temp,mp);
        return ans;
    }
};