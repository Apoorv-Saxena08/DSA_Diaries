class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {      sort(tokens.begin() , tokens.end());
        int n = tokens.size() , score = 0 , maxi = 0;
        int l = 0 , r= n-1;
        while(l <= r){
            if(tokens[l] <= power){
                //up
                power -= tokens[l];
                score++; 
                maxi = max(maxi, score);
                l++;
            }

            else if(score>0){
                //down
                score--;
                power += tokens[r];
                r--;
            }

            else{
                break;
            }
        }

        return maxi;
    }
};