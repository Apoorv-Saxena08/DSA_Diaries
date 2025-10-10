class Solution {
public:
    void solve(vector<vector<int>> &ans,int n,vector<int>& nums,vector<int>&temp,int index){
        if(index == n){
            ans.push_back(temp);
            return;
        }

        //include 
        temp.push_back(nums[index]);
        solve(ans,n,nums,temp,index+1);
        temp.pop_back();
        //exclude
        solve(ans,n,nums,temp,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int>temp;
        solve(ans,n,nums,temp,0);
        return ans;
    }
};