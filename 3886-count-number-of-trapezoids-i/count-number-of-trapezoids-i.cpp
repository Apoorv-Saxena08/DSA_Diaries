class Solution {
public:
    const int mod = 1000000007;

    int nc2(int x){
        long long y = x;
        return (y * (y - 1) / 2) % mod;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,int> mp;

        for (auto &p : points)
            mp[p[1]]++;

        vector<int> freq;
        for (auto &it : mp)
            if (it.second > 1)
                freq.push_back(it.second);

        if (freq.size() <= 1) return 0;

        // convert each freq to nC2
        for (int i = 0; i < freq.size(); i++) {
            freq[i] = nc2(freq[i]);
        }

        long long ans = 0;
        int m = freq.size();
        vector<long long> pre(m, 0);

        for (int i = m - 2; i >= 0; i--) {
            pre[i] = (pre[i + 1] + freq[i + 1]) % mod;
        }

        for (int i = 0; i < m; i++) {
            ans = (ans + (1LL * freq[i] * pre[i]) % mod) % mod;
        }

        return ans;
    }
};
