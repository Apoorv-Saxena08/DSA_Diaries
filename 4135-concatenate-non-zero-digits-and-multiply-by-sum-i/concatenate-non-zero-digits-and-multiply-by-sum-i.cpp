class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int> digits;
        long long sum = 0;

        while (n) {
            int rem = n % 10;
            if (rem != 0) {
                digits.push_back(rem);
                sum += rem;
            }
            n /= 10;
        }

        reverse(digits.begin(), digits.end());

        long long newnum = 0;
        for (int d : digits) {
            newnum = newnum * 10 + d;
        }

        return newnum * sum;
    }
};
