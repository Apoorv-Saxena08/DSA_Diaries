class Solution {
public:// recusive + dp approach 
    int solve(int row , int col , vector<vector<int>>& t, vector<vector<int>>&dp){
        if(row == t.size()-1){
            return t[row][col];
        }
        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int downRow = solve(row+1,col,t,dp);
        int diagRow = solve(row+1,col+1,t,dp);

        return dp[row][col] = t[row][col] + min(downRow, diagRow);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp (n , vector<int>(n , INT_MAX));
        return solve(0,0,triangle,dp);        
    }
};