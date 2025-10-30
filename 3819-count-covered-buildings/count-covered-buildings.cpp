class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        unordered_map<int ,vector<int>> rows,cols;
        int m = b.size();
        rows.reserve(m*2);
        cols.reserve(m*2);

        //group by rows and cols
        for(auto v:b){
            rows[v[0]].push_back(v[1]);
            cols[v[1]].push_back(v[0]);
        }
        //sort it
        for(auto &[x,ys] : rows){
            sort(ys.begin(), ys.end());
        }
        for(auto &[y,xs] : cols){
            sort(xs.begin(),xs.end());
        }

        unordered_set<long long> coveredRow , coveredCol;
                // Covered in row direction (not first or last)
        for (auto &[x, ys] : rows) {
            for (int i = 1; i < ys.size() - 1; i++) {
                long long key = (long long)x * 1000000 + ys[i];
                coveredRow.insert(key);
            }
        }

        // Covered in column direction (not first or last)
        for (auto &[y, xs] : cols) {
            for (int i = 1; i < xs.size() - 1; i++) {
                long long key = (long long)xs[i] * 1000000 + y;
                coveredCol.insert(key);
            }
        }

        // Intersection of both sets
        int count = 0;
        for (auto &key : coveredRow)
            if (coveredCol.count(key)) count++;

        return count;

    }
};