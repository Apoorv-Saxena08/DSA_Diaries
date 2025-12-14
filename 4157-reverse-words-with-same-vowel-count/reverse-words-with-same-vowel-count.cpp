class Solution {
public:
    int findVowelCount(string temp){
        int ct = 0;
        for(auto c : temp){
            if(c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u'){
                ct++;
            }
        }
        return ct;
    }

    string reverseWords(string s) {
        vector<string>words;
        for(int i = 0;i<s.length();i++){
            string temp = "";
            while(i<s.length() && s[i] != ' '){
                temp += s[i];
                i++;
            }
            words.push_back(temp);
        }
        string temp = words[0];
        int count = findVowelCount(temp) ;

        for(int i = 1 ; i<words.size();i++){
            int c = findVowelCount(words[i]);
            if(c==count){
                reverse(words[i].begin(),words[i].end());
            }
        }

        string ans = "";
        for(int i = 0 ; i<words.size();i++){
            ans += words[i];
            if(i<words.size()-1)
            ans += " ";
        }
        return ans;
    }
};