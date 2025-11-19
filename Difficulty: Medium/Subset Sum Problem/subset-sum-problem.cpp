class Solution {
  public:
    bool solve(vector<int>& arr,int i, int sum,vector<vector<int>>&dp){
        if(i==arr.size()){
            if(sum==0){
                return true;
            }
            else{
                return false;
            }
        }
        if(sum<0)return false;
        
        if(dp[i][sum] != -1)return dp[i][sum];
        
        //pick 
        bool pick = solve(arr,i+1,sum-arr[i],dp);
        //not pick
        bool notpick = solve(arr,i+1,sum,dp);
        return dp[i][sum] = pick or notpick;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
        return solve(arr,0,sum,dp);    
    }
};