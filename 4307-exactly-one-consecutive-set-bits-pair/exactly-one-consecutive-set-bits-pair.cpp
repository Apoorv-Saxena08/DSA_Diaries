class Solution {
public:
    bool consecutiveSetBits(int n) {
        bool oneFound = false;
        int prev = n%2;
        n /=2 ;
        while(n){
            int rem = n%2;
            if((prev & rem) == 1){
                if(!oneFound){
                    oneFound = true;
                }
                else{
                    oneFound = false;
                    break;
                }
            }
            prev = rem;
            n /=2 ;
        }
        return oneFound;
    }
};