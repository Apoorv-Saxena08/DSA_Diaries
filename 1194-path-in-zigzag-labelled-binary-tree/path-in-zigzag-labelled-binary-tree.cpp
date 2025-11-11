class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int level = log2(label);

        while (label >= 1) {
            ans.push_back(label);
            int level_start = pow(2, level);
            int level_end = pow(2, level + 1) - 1;

            label = (level_start + level_end - label) / 2;
            level--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
