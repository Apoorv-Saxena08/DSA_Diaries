class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int>ans;
        int m = grid.size();
        int n = grid[0].size();
        for(int i= 0 ; i<n;i++){
            int maxi = 0;
            for(int j = 0 ; j<m; j++){
                string s = to_string(grid[j][i]);
                if(maxi <= s.length())maxi = s.length();
            }
            ans.push_back(maxi);
        }
        return ans;
    }

};