class Solution {
public:
    bool hasAlternatingBits(int n) {
        int val = n;
        int prev = n%2;
        val /= 2;
        while(val){
            int bit = val %2;
            if(prev == bit){
                return false;
            }
            prev = bit;
            val /= 2;
        }
        return true;
    }
};