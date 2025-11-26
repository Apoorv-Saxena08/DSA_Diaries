class Solution {
public:
    int mod = 1000000007;
    int solve(vector<vector<int>>& grid, int k,int i , int j , int m , int n,int currsum,vector<vector<vector<int>>>&dp){
        if(i>=m || j>=n)return 0;
        
        if(i==m-1 && j==n-1){
            if(currsum%k==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[i][j][currsum] != -1){
            return dp[i][j][currsum];
        }

        int down = 0 , right = 0;
        //int go down
        if(i+1<m)
         down = solve(grid,k,i+1,j,m,n,(currsum+grid[i+1][j])%k,dp) %mod ;
        //go right
        if(j+1<n)
         right = solve(grid,k,i,j+1,m,n,(currsum+grid[i][j+1])%k,dp) %mod;
        
        return dp[i][j][currsum] = (down+right)%mod;

    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(grid,k,0,0,m,n,grid[0][0]%k,dp) %mod;
    }
};