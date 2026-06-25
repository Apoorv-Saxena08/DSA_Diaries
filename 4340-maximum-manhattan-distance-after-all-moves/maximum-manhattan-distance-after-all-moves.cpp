class Solution {
public:
    int maxDistance(string moves) {
        int h = 0 , v = 0 , u = 0;
        for(auto&c : moves){
            if(c=='L' ){
                h--;
            }
            else if(c=='R'){
                h++;
            }
            else if(c=='U'){
                v--;
            }
            else if(c=='D'){
                v++;
            }
            else{
                u++;
            }
        }
        int ans = abs(h) + abs(v);
        return ans + u;
    }
};