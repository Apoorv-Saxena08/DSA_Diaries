class Solution {
private:
    bool isValid(string &s){
        if(s == "") return false;
        for(char c: s){
            if(!isalnum(c) && c != '_') return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> ans;
        map<int,vector<string>> m;
        for(int i=0;i<isActive.size();i++){
            if(isActive[i] && isValid(code[i])){
                string r = businessLine[i];
                int key = -1;
                if(r =="electronics"){
                    key = 0;
                }else if(r == "grocery"){
                    key = 1;
                }else if(r == "pharmacy"){
                    key = 2;
                }else if(r == "restaurant"){
                    key = 3;
                }

                if(key != -1){
                    m[key].push_back(code[i]);
                }
            }
        }

        for(auto [n,v]: m){
            sort(v.begin(),v.end());
            for(string i : v){
                ans.push_back(i);
            }
        }

        return ans;
    }
};