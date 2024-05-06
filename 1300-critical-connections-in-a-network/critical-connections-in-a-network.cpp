class Solution {
    int time=1;
void dfs(int u,int parent,vector<bool> &vis,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,vector<vector<int>>&ans){
    vis[u]=true;
    disc[u]=low[u]=time++;
    for(auto it:adj[u]){
        if(it==parent) continue;
        if(!vis[it]){
            dfs(it,u,vis,adj,disc,low,ans);
            low[u]=min(low[u],low[it]);
            if(low[it]>disc[u]){
                ans.push_back({u,it});
            }
        }
        else{
            low[u] = min(low[u],low[it]);
        }
    }
}

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;
        vector<bool> vis(n,false);
        vector<int> disc(n),low(n);
        dfs(0,-1,vis,adj,disc,low,ans);
        return ans;
    }
};