class Solution {
public:
    bool isbalanced(const vector<int>& freq) {
        int val = 0;
        for (int f : freq) {
            if (f > 0) {
                if (val == 0)
                    val = f;
                else if (val != f)
                    return false;
            }
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        vector<vector<int>> prefix(n + 1, vector<int>(26, 0));

        // build prefix frequency
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i];
            prefix[i + 1][s[i] - 'a']++;
        }

        int maxlen = 0;

        // check substrings using prefix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> freq(26);
                for (int k = 0; k < 26; k++) {
                    freq[k] = prefix[j + 1][k] - prefix[i][k];
                }
                if (isbalanced(freq)) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }

        return maxlen;
    }
};
