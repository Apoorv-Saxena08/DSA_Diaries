class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size() , maxi = 0;
        int small = p[0] , diff;
        for(int i= 0 ; i<n;i++){
            diff = p[i] - small;
            maxi = max(maxi, diff);
            small = min(small, p[i]);
        }
        return maxi;
    }
};