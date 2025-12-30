class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int x = (int)grid.size();
        int y = (int)grid[0].size();
        int count = 0;
        auto isMagicSquare = [&](int r, int c) -> bool {
            vector<int> s;
            s.reserve(9);
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    s.push_back(grid[r + i][c + j]);
                }
            }
            vector<int> sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            for (int i = 0; i < 9; i++){
                if (sortedS[i] != i + 1)
                    return false;
            }
            return (
                s[0] + s[1] + s[2] == 15 &&
                s[3] + s[4] + s[5] == 15 &&
                s[6] + s[7] + s[8] == 15 &&
                s[0] + s[3] + s[6] == 15 &&
                s[1] + s[4] + s[7] == 15 &&
                s[2] + s[5] + s[8] == 15 &&
                s[0] + s[4] + s[8] == 15 &&
                s[2] + s[4] + s[6] == 15
            );
        };
        for (int i = 0; i <= x - 3; i++){
            for (int j = 0; j <= y - 3; j++){
                if (isMagicSquare(i, j))
                    count++;
            }
        }
        return count;
    }
};