class Solution {
  public:
    // Function to count the number of digits in n that evenly divide n
    int evenlyDivides(int n) {
        // code here
        int count = 0 ;
        int temp = n;
        while(temp){
            int digit = temp%10;
            if(digit != 0){
                if(n%digit == 0){
                    count++;
                }
            }
            temp = temp/10;
        }
        return count;
    }
};