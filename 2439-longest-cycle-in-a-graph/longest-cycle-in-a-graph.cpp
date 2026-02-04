class Solution {
public:
    int ans = -1 , timer = 1;

    void dfs(int u,vector<int>& edges,vector<int>&vis,vector<int>&pathVis,vector<int>&entryTime){
        vis[u] = 1;
        pathVis[u] = 1;
        entryTime[u] = timer++;

        int v = edges[u];

        if(v != -1){
            if(!vis[v]){
                dfs(v,edges,vis,pathVis,entryTime);
            }
            else if(pathVis[v]){
                int len = entryTime[u] - entryTime[v] +1;
                ans = max(ans,len);
            }
        }

        pathVis[u] = 0;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int>vis(n,0) , pathVis(n,0) , entryTime(n,0);

        for(int i = 0 ; i<n;i++){
            if(!vis[i]){
                dfs(i,edges,vis,pathVis,entryTime);
            }
        }

        return ans;
    }
};