class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini = p[0];
        int ans = 0 ;
        for(int i = 1 ; i<p.size();i++){
            int diff = p[i]-mini;
            ans = max(ans,diff);
            mini = min(mini,p[i]);
        }
        return ans;
    }
};