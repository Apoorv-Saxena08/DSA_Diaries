class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if(V==1)return {0};
        
        vector<vector<int>>adj(V);
        vector<int>deg(V,0);
        
        for(auto&e : edges){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[v]++;
            deg[u]++;
        }
        
        queue<int>q;
        
        for(int i = 0 ; i<V;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }
        
        int rem = V;
        while(rem>2){
            int sz = q.size();
            rem -= sz;
            while(sz--){
                auto node = q.front();
                q.pop();
                
                for(auto neig : adj[node]){
                    deg[neig]--;
                    if(deg[neig]==1){
                        q.push(neig);
                    }
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};