class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }        
        vector<int> dis(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int stop = curr.first;
            int u = curr.second.first;
            int val = curr.second.second;
            if(stop==k+1 && u==dst)
                break;
            if(stop>k+1)
                continue;
            for(auto it:adj[u]){
                int v = it.first;
                int d = it.second;
                if(d+val<dis[v] && stop<k+1){
                    dis[v]=d+val;
                    q.push({stop+1,{v,dis[v]}});
                }
            }
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};