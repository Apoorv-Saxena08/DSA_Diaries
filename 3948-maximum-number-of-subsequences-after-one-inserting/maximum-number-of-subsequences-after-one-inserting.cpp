class Solution {
public:
    long long getcount(const string& s){
        long long ans = 0 , l= 0 , t = count(s.begin() , s.end() , 'T');
        for(char ch:s){
            if(ch == 'L'){
                l++;
            }
            else if(ch == 'T'){
                t--;
            }
            else if(ch == 'C'){
                ans += l*t;
            }
        }
        return ans;
    }

    long long numOfSubsequences(string s) {
        long long res = max(getcount("L" +s) , getcount(s + "T") );
        //res btara h subseq if we add L or T , no let we check for C
        long long ans = 0 , l= 0 , t = count(s.begin() , s.end() , 'T');
        for(char ch: s){
            if(ch == 'L'){
                l++;
            }
            else if(ch == 'T'){
                t--;
            }
            ans = max(ans , l*t);
        }

        return max(res , getcount(s) + ans);
    }
};