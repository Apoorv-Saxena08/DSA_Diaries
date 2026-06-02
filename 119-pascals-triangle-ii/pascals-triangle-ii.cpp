class Solution {
public:
    vector<int> getRow(int row) {
        if(row == 0 )return {1};
        vector<int>res(1,1);
        long long prev = 1;
        for(int k = 1 ; k<= row ; k++){
            long long next_val = prev * (row-k+1)/k;
            res.push_back(next_val);
            prev = next_val;
        }

        return res;
    }
};