class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m = d.size() , n = d[0].size();
        vector<vector<int>>dp(m,vector<int>(n));

        //base case 
        dp[m-1][n-1] = max(1 , 1-d[m-1][n-1]);

        //last col
        for(int i = m-2 ; i>=0 ; i--){
            dp[i][n-1] = max(1 , dp[i+1][n-1] - d[i][n-1]);
        }

        //ast row
        for(int j = n-2 ; j>=0 ;j--){
            dp[m-1][j] = max(1 , dp[m-1][j+1] - d[m-1][j]);
        }

        //all cells
        for(int i = m-2 ;i>=0 ;i--){
            for(int j = n-2 ;j>=0 ;j--){
                int need = min(dp[i+1][j] , dp[i][j+1]) - d[i][j] ;//down or right
                dp[i][j] = max(1,need);
            }
        }

        return dp[0][0];
    }
};