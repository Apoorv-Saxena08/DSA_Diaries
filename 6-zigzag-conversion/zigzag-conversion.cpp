class Solution {
public:
    string convert(string s, int num) {
        int n = s.size();
        if(num==1)return s;
        vector<string>rows(min(num,n));
        int curr = 0 , dir = -1;
        for(char c:s){
            rows[curr] += c;

            if(curr==0 || curr==num-1)dir = -dir;

            curr += dir;
        }
        string res;
        for(int i =0 ; i<rows.size();i++){
            res += rows[i];
        }
        return res;
    }
};