class Solution {
public:
    vector<vector<int>>ans;

    void solve(vector<int>&nums , int k , int n , int i , vector<int>&temp){
        if(i==nums.size() || n<0 || temp.size()>k){
            if(n==0 && temp.size()==k){
                ans.push_back(temp);
            }
            return;
        }

        //pick
        temp.push_back(nums[i]);
        solve(nums,k,n-nums[i] , i+1,temp);
        temp.pop_back();

        //unpick 
        solve(nums,k,n, i+1,temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        solve(nums , k , n , 0 ,temp );
        set<vector<int>>s (ans.begin() , ans.end());
        vector<vector<int>> res (s.begin() , s.end());
        return res;
    }
};