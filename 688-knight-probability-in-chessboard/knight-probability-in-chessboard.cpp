class Solution {
public:
    double dp[30][30][105];
    double f(int i, int j, int k, int n) {
        if (i < 0 || j < 0 || i >= n || j >= n) // grid ke bahar chale gye
            return 0;
        if (k == 0)
            return 1;
        if (dp[i][j][k] > -0.9)
            return dp[i][j][k];
        return dp[i][j][k] = (f(i + 1, j + 2, k - 1, n) * 1 / 8) +
                             (f(i + 2, j + 1, k - 1, n) * 1 / 8) +
                             (f(i - 1, j + 2, k - 1, n) * 1 / 8) +
                             (f(i - 2, j + 1, k - 1, n) * 1 / 8) +
                             (f(i + 1, j - 2, k - 1, n) * 1 / 8) +
                             (f(i + 2, j - 1, k - 1, n) * 1 / 8) +
                             (f(i - 1, j - 2, k - 1, n) * 1 / 8) +
                             (f(i - 2, j - 1, k - 1, n) * 1 / 8);
    }
    double knightProbability(int n, int k, int row, int column) {

        memset(dp, -1, sizeof dp);

        return f(row, column, k, n);
    }
};