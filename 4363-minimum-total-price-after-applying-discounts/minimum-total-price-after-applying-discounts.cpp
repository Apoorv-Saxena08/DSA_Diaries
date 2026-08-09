class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        sort(p.rbegin() , p.rend());
        sort(d.rbegin() , d.rend());
        int n = p.size() , m = d.size() , i = 0;;
        double ans = 0 ;
        for(i = 0 ; i<m && i<n ; i++){
            ans += (double)p[i] * (100 - d[i]) / 100.0;
        }
        while(i<n){
            ans += (double)p[i];
            i++;
        }
        return ans;
    }
};