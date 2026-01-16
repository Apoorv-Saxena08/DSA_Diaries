class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        const int MOD = 1e9 + 7;

        int hsize = hFences.size();
        int vsize = vFences.size();

        vector<int> row(hsize + 2);
        vector<int> col(vsize + 2);

        row[0] = 1;
        col[0] = 1;

        for (int i = 0; i < hsize; i++) row[i + 1] = hFences[i];
        for (int i = 0; i < vsize; i++) col[i + 1] = vFences[i];

        row[hsize + 1] = m;
        col[vsize + 1] = n;

        sort(row.begin(), row.end());
        sort(col.begin(), col.end());

        unordered_set<int> st;

        for (int i = 0; i < row.size(); i++) {
            for (int j = i + 1; j < row.size(); j++) {
                st.insert(row[j] - row[i]);
            }
        }

        int finalAns = 0;

        for (int i = 0; i < col.size(); i++) {
            for (int j = i + 1; j < col.size(); j++) {
                int diff = col[j] - col[i];
                if (st.find(diff) != st.end()) {
                    finalAns = max(finalAns, diff);
                }
            }
        }

        if (finalAns == 0) return -1;

        return (1LL * finalAns * finalAns) % MOD;
    }
};