class Solution {
public:
    void solve(vector<vector<int>>& grid , int i , int j , int&m , int&n){
        //upr 
        for(int row = i-1 ;  row>=0 ; row--){
            grid[row][j] = 0;
        }

        //niche 
        for(int row = i+1 ;  row<m ; row++){
            grid[row][j] = 0;
        }

        //left 
        for(int col = j-1 ;  col>=0 ; col--){
            grid[i][col] = 0;
        }

        //right 
        for(int col = j+1 ;  col<n ; col++){
            grid[i][col] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        //vector<pair<int,int>>v;
        vector<bool>rowZero(m,0);
        vector<bool>colZero(n,0);
        
        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n; j++){
                if(grid[i][j] == 0){
                    rowZero[i] = 1;
                    colZero[j] = 1;
                }
            }
        }

        for(int i = 0 ; i<m ; i++){
            for(int j = 0 ; j<n; j++){
                if(rowZero[i] || colZero[j]){
                    grid[i][j] = 0;
                }
            }
        }
    }
};