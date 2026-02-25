class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        int n = arr.size();
        for(int i = 0 ; i<n;i++){
            int a = __builtin_popcount(arr[i]);
            mp[a].push_back(arr[i]);
        }
        vector<int>ans;
        for(auto it : mp){
            int sz = it.second.size();
            sort(it.second.begin(),it.second.end());
            for(int i = 0 ; i<sz;i++){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};