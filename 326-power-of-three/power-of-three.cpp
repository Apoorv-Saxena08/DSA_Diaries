class Solution {
public:
    bool isPowerOfThree(int n) {
        int temp = n;
        if(n==0)return false;
        while(temp){
            if(temp%3 != 0 && temp != 1)return false;
            temp = temp/3;
        }
        return true;
    }
};