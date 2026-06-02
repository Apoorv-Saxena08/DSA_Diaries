class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n>=2){
            ans.push_back({1,1});
        }else{
            return ans;
        }

        for(int i = 2 ; i<n;i++){
            vector<int>row;
            row.push_back(1);
            for(int s = 0; s<ans[i-1].size()-1 ; s++){
                row.push_back(ans[i-1][s] + ans[i-1][s+1] );
            }
            row.push_back(1);

            ans.push_back(row);
        }

        return ans;

    }
};