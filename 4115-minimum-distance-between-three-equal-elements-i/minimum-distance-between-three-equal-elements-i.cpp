class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        int mini = INT_MAX;
        bool found = false;

        for (auto &it : mp) {
            auto &v = it.second;
            if (v.size() >= 3) {
                sort(v.begin(), v.end());
                // Try all consecutive triplets
                for (int i = 0; i + 2 < v.size(); i++) {
                    int a = v[i], b = v[i+1], c = v[i+2];
                    int diff = abs(a-b) + abs(b-c) + abs(a-c);
                    mini = min(mini, diff);
                    found = true;
                }
            }
        }
        return found ? mini : -1;
    }
};
