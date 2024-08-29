class Solution {
    void dfs(vector<vector<int>> &adj,int node,vector<bool> &vis){
        vis[node] = true;
        for(auto &it:adj[node]){
            if(!vis[it])
                dfs(adj,it,vis);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> vis(n,false);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(adj,i,vis);
            }
        }
        return n - cnt;

    }
};