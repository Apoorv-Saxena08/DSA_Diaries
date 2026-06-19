class Solution {
public:
    bool checkGoodInteger(int n) {
        int a = 0 , b = 0;
        while(n){
            int rem = n%10;
            a += rem;
            b += rem*rem;
            n /= 10;
        }

        return b-a >= 50; 
    }
};