class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int row = 0, countMax = 0;

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) count++;
            }

            if (count > countMax) {
                countMax = count;
                row = i;
            }
        }

        return {row, countMax};
    }
};
