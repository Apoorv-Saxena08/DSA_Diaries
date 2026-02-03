class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();

        // node -> edge score
        map<int, long long> score;

        for (int i = 0; i < n; i++) {
            score[i] = 0;
        }

        // map index values
        for (int i = 0; i < n; i++) {
            score[edges[i]] += i;
        }

        long long maxi = -1;
        int ans = 0;

        //check max score
        for (auto it : score) {
            if (it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            }
        }

        return ans;
    }
};
