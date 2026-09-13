class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        // row shift
        for (int i = 0; i < n; i++) {
            vector<int> temp(n);

            for (int j = 0; j < n; j++) {
                temp[j] = grid[i][(j + rowShift[i]) % n];
            }

            grid[i] = temp;
        }

        vector<vector<int>> ans = grid;

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                ans[i][j] = grid[(i + colShift[j]) % n][j];
            }
        }

        return ans;
    }
};