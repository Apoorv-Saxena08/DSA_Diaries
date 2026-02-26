class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        vector<int>inDeg(n);
        for(auto v:p){
            adj[v[1]].push_back(v[0]);
            inDeg[v[0]]++;
        }
        
        queue<int>q;
        for(int i =0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        
        if(q.empty())return false;
        
        vector<int>topo;
        
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i<sz;i++){
                int u = q.front();
                q.pop();
                topo.push_back(u);
                for(int v : adj[u]){
                    inDeg[v]--;
                    if(inDeg[v]==0){
                        q.push(v);
                    }
                }
            }
        }
        //for(auto i : topo)cout<<i<<" ";
        return topo.size()==n;
        
    }
};