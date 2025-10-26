class Solution {
  public:
    int reverseExponentiation(int n) {
        // code here
        if(n>=1 && n<=9){
            return pow(n,n);
        }
        return n;
    }
};