class Solution {
public:
    long long minEnergy(int n, int b, vector<vector<int>>& interval) {
        long long active = ceil((double)b/3);

        sort(interval.begin() , interval.end());
        int no = interval.size();
        vector<vector<int>>ans;
        ans.push_back(interval[0]);
        for(int i = 1;i<no;i++ ){
            if(interval[i][0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1] , interval[i][1] );
            }else{
                ans.push_back(interval[i]);
            }
        }
        long long total = 0 ;
        for(auto&it : ans){
            total += it[1] - it[0] +1;
        }
        return active*total;
    }
};