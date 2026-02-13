class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {

            vector<int> filtered;

            // Keep numbers having this bit set
            for (int x : nums) {
                if (x & (1 << bit)) {
                    filtered.push_back(x);
                }
            }

            // Compute LIS on filtered
            vector<int> lis;

            for (int x : filtered) {
                auto it = lower_bound(lis.begin(), lis.end(), x);

                if (it == lis.end())
                    lis.push_back(x);
                else
                    *it = x;
            }

            ans = max(ans, (int)lis.size());
        }

        return ans;
    }
};
