class Solution {
  public:
    
    int solve(vector<int>& arr,int i, int target,vector<vector<int>>&dp){
        if(i==arr.size()){
            if(target==0){
                return 1;
            }
            else{
            return 0;                
            }
        }
        if(target<0)return 0;
        
        if(dp[i][target] != -1)return dp[i][target];
        //pick
        int take = solve(arr,i+1,target-arr[i],dp);
        //not pick
        int nottake = solve(arr,i+1,target,dp);
    
        return dp[i][target] = take+nottake;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(target+1,-1));
        return solve(arr,0,target,dp);
     
    }
};