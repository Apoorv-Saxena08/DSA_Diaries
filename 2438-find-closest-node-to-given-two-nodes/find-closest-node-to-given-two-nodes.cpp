class Solution {
public:
    vector<int>BFS(vector<int>& edges, int src){
        int n = edges.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i = 0 ; i<n;i++){
            adj[i].push_back({edges[i] , 1});//u v w
        }

        vector<int>dist(n,1e9);
        queue<pair<int,int>>q;
        q.push({src,0});
        dist[src] = 0;

        while(!q.empty()){
            auto [node , dis] = q.front();
            q.pop();

            for(auto it : adj[node]){
                int newNode = it.first;
                int newDist = it.second;

                if(newNode != -1 && dist[newNode] > dis + newDist){
                    dist[newNode] = dis + newDist;
                    q.push({newNode , dis + newDist});
                }
            }
        }

        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>dist1 = BFS(edges,node1);
        vector<int>dist2 = BFS(edges,node2);
        
        int mini = 1e9 , ans = -1;

        for(int i = 0 ; i<edges.size();i++){
            if(dist1[i] != 1e9 && dist2[i] != 1e9){
                int maxi = max(dist1[i] , dist2[i]);
                if(mini>maxi){
                    mini = maxi;
                    ans = i;
                }
            }
        }

        return ans;
    }
};