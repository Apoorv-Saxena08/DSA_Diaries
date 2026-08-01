class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.length();
        int count0 = 0;
        int count1 = 0;
        int ans = 0;
        for (char c : s) {
            if (c == '0') {
                count0 += 1;
            }
            if (c == '1') {
                count1 += 1;
            }
            int count = count1 - count0;
            if (abs(count) <= 1) {
                ans += 1;
            }
        }
        return ans;
    }
};