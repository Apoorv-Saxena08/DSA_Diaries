class Solution {
public:
    int maxIceCream(vector<int>& costs, int total) {
        int ans = 0 ;
        sort(costs.begin() , costs.end());
        for(int i = 0 ; i<costs.size(); i++){
            if(costs[i]<=total){
                ans++;
                total -= costs[i];
            }
        }
        return ans;
    }
};