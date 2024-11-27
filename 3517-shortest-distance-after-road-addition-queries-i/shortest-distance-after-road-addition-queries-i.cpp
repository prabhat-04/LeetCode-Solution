class Solution {
    int bfs(vector<vector<int>> &adj,int n){
        queue<int> q;
        vector<int> vis(n,false);
        q.push(0);
        vis[0]=true;
        int ans=0;
        while(!q.empty()){
            int sz =q.size();
            for(int i=0;i<sz;i++){
                int curr = q.front();
                q.pop();
                if(curr==n-1) return ans;
                for(int &it:adj[curr]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
            ans++;
        }
        return ans;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int> ans;
        for(auto &it:queries){
            adj[it[0]].push_back(it[1]);
            ans.push_back(bfs(adj,n));
        }
        return ans;
    }
};