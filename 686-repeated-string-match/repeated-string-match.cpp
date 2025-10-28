class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length() , m = b.length();
        int ans = m/n +1 ;
        string temp = a;
        if(b=="")return 0;
        for(int i = 1 ; i<= ans+1 ; i++){
            if(a.find(b) != string::npos){
                return i;
            }
            a += temp;
        }
        return -1;
    }
};