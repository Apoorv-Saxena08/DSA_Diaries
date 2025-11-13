class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int t , int i , vector<int>&temp){
        if(i==nums.size() || t<0){
            if(t==0){
                ans.push_back(temp);
            }
            return ;
        }

        //inc 
        temp.push_back(nums[i]);
        solve(nums,t-nums[i],i,temp);
        temp.pop_back();

        //ex
        solve(nums,t,i+1,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(nums,t,0,temp);
        set<vector<int>>st(ans.begin(),ans.end());
        vector<vector<int>>res(st.begin(),st.end());
        return res;
    }
};