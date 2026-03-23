class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        int ans1 = 0, ans2 = 0;
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] > s2[i])
                ans1++;
            else if (s2[i] > s1[i])
                ans2++;
            else {
                ans1++;
                ans2++;
            }
        }
        
        if (ans1 == n || ans2 == n)
            return 1;
        else
            return 0;
    }
};