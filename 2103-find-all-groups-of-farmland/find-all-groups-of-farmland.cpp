class Solution {
public:
    vector<vector<int>> ans;

    // void solve(int i, int j, vector<vector<int>>& land) {
    //     if (i >= land.size() || j >= land.size()) {
    //         return;
    //     }

    //     if (land[i][j] == 1) {
    //         int row = i, col = j;
    //         while (row < m && land[row][col] == 1) {
    //             row++;
    //         }
    //         while (col < n && land[row][col] == 1) {
    //             col++;
    //         }
    //     }
    // }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    int row = i, col = j;
                    while (row < m-1 && land[row+1][col] == 1) {
                        row++;
                    }
                    while (col < n-1 && land[row][col+1] == 1) {
                        col++;
                    }
                    for(int x = i ; x<=row ;x++ ){
                        for(int y = j; y<=col;y++){
                            land[x][y] = 0;
                        }
                    }
                    ans.push_back({i,j,row,col});
                }
            }
        }

        return ans;
    }
};