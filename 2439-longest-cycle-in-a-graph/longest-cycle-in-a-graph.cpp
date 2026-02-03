class Solution {
public:
    int maxi  = -1;

    void dfs(int node ,vector<bool>&visited,vector<int>&inR,vector<int>&edges,int depth ){
        visited[node] = true;
        inR[node] = depth;

        int neigh = edges[node];
        if(neigh != -1){
            if(!visited[neigh]){
                dfs(neigh,visited,inR,edges,depth+1);
            }
            else if(inR[neigh] != -1){
                maxi = max(maxi , depth +1 - inR[neigh]);
            }
        }

        inR[node] = -1;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>visited(n,false);
        vector<int>inR(n,-1);

        for(int i = 0 ; i<n;i++){
            if(!visited[i]){
                dfs(i,visited,inR,edges,0);
            }
        }
        return maxi;
    }
};