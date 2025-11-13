class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int t,int i , vector<int>&temp){
        if(t==0){
            ans.push_back(temp);
            return;
        }

        for(int start = i ;start<nums.size();start++){
            if(start>i && nums[start]==nums[start-1])continue;

            if(nums[start]>t)break; //pruning

            temp.push_back(nums[start]);
            solve(nums,t-nums[start],start+1,temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(nums,t,0,temp);
        return ans;
    }
};