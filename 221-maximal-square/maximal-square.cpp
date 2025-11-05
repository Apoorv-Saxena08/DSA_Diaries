class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //base case
        if(matrix.size()==0)return 0;
        //variables
        int maxsqr = 0,rows = matrix.size() , cols = matrix[0].size();
        vector<vector<int>>dp(rows+1,vector<int>(cols+1,0));

        for(int i =1 ; i<=rows;i++){
            for(int j = 1 ; j<=cols;j++){
                if(matrix[i-1][j-1] == '1'){
                    //find min from left , upper, upper left
                    dp[i][j] = min({
                        dp[i][j-1] ,
                        dp[i-1][j],
                        dp[i-1][j-1]
                    }) +1 ;
                    maxsqr = max(maxsqr,dp[i][j]);
                }
            }
        }
        return maxsqr*maxsqr;
    }
};