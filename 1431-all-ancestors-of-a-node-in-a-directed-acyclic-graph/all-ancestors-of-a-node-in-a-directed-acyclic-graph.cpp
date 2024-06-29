class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(n);
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            vector<bool> vis(n,false);
            vis[i]=true;
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                if(it!=i)
                    ans[i].push_back(it);
                for(auto t : adj[it]){
                    if(!vis[t]){
                    q.push(t);
                    vis[t]=true;
                    }
                }
            }
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};