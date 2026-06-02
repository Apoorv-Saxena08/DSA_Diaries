class Solution {
public:
    vector<int> getRow(int row) {
        if(row == 0 )return {1};
        // vector<int>res(1,1);
        // long long prev = 1;
        // for(int k = 1 ; k<= row ; k++){
        //     long long next_val = prev * (row-k+1)/k;
        //     res.push_back(next_val);
        //     prev = next_val;
        // }

        // return res;

        vector<int>ans(row+1,0);
        ans[0] = 1;
        for(int i = 1 ; i<row+1;i++){
            for(int j = i ; j>=1;j--){
                ans[j] += ans[j-1];
            }
        }

        return ans;
    }
};