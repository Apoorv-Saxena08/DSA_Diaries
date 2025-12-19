class Solution {
public:
#define ppr pair<int, int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        sort(meetings.begin(), meetings.end());
        vector<vector<pair<int, int>>> adj(n);
        for (auto& x : meetings) {
            int u = x[0];
            int v = x[1];
            int w = x[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        priority_queue<ppr, vector<ppr>, greater<ppr>> pq;
        pq.push({0, 0});
        pq.push({0, firstPerson});
        vector<int> visited(n, 0);

        while (!pq.empty()) {
            auto top = pq.top();
            int time = top.first;
            int person = top.second;
            pq.pop();
            if (visited[person])
                continue;
            visited[person] = true;

            for (auto it : adj[person]) {

                if (!visited[it.first] && it.second >= time) {
                    pq.push({it.second, it.first});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};