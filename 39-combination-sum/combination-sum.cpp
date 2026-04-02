class Solution {
public:
    vector<vector<int>>ans;

    void solve(vector<int>& c, int t , int i ,vector<int>&temp){
        if(i== c.size() || t<0){
            if(t==0){
                ans.push_back(temp);
            }
            return;
        }

        //pick
        temp.push_back(c[i]);
        solve(c,t-c[i],i,temp);
        temp.pop_back();

        //unpick
        solve(c,t,i+1,temp);

    }

    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        sort(c.begin() , c.end());
        vector<int>temp;
        solve(c,t,0,temp);
        set<vector<int>> s(ans.begin() , ans.end());
        vector<vector<int>>res (s.begin() , s.end());
        return res;
    }
};