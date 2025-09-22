class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        //make them string 
        vector<string> s;
        for(int n : nums){
            s.push_back(to_string(n));
        }

        //sort such that 1+2 > 2+1
        sort(s.begin() , s.end() , [](const string &a , const string &b){
            return (b+a) < (a+b);
        });

        //agr sbse bda number hi 0 aya to return 0
        if(s[0] == "0")return "0";

        //make the number
        for(auto str : s){
            ans += str;
        }
        return ans;
    }
};