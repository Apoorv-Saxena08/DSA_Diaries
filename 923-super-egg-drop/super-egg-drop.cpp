class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        // Base cases:
        // 0 floors = 0 trials, 1 floor = 1 trial
        for (int i = 1; i <= k; i++) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }

        // 1 egg → i floors = i trials
        for (int j = 1; j <= n; j++) {
            dp[1][j] = j;
        }

        // Fill the DP table
        for (int eggs = 2; eggs <= k; eggs++) {
            for (int floors = 2; floors <= n; floors++) {

                int low = 1, high = floors, ans = floors;

                while (low <= high) {
                    int mid = (low + high) / 2;
                    int breaks = dp[eggs - 1][mid - 1];   // egg breaks
                    int survives = dp[eggs][floors - mid]; // egg doesn’t break
                    int worst = 1 + max(breaks, survives);

                    if (breaks < survives) {
                        low = mid + 1;     // move up
                    } else {
                        high = mid - 1;    // move down
                    }
                    ans = min(ans, worst);
                }

                dp[eggs][floors] = ans;
            }
        }

        return dp[k][n];
    }
};
