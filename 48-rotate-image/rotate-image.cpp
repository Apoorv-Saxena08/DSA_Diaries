class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int  n = grid[0].size();
        //transpose 
        for(int i = 0 ; i<n-1;i++ ){
            for(int j = i; j<n ; j++){
                if(i==j)continue;
                swap(grid[i][j] , grid[j][i]);
            }
        }
        //reverse every vector 
        for(auto&it : grid ){
            reverse(it.begin() , it.end());
        }
    }
};