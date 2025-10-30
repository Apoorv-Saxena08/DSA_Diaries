class Solution {
public:
    int solve(vector<long long>&nums , long long i , long long leftsum , long long total){
        for(;i<nums.size()-1;i++){
            leftsum += nums[i];
            long long rs = total - leftsum;
            if(leftsum == rs)return i;
        }
        return -1;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<long long>rowwise;
        vector<long long>colwise;
        
        for(int i= 0 ; i<row ; i++){
            long long rval = 0 ;
            for(int j = 0 ; j<col ; j++){
                rval += grid[i][j];
            }
            rowwise.push_back(rval);
        }
        for(int i= 0 ; i<col ; i++){
            long long val = 0 ;
            for(int j = 0 ; j<row ; j++){
                val += grid[j][i];
            }
            colwise.push_back(val);
        }

        long long totalR = 0 , totalC = 0;
        for(int i = 0 ; i<rowwise.size();i++){
            totalR += rowwise[i];
        }
        for(int i = 0 ; i<colwise.size();i++){
            totalC += colwise[i];
        }
        int r = solve(rowwise,0,0,totalR) , c = solve(colwise,0,0,totalC);
        bool one = r != -1;
        bool two = c != -1;
        return one || two;
    }
};