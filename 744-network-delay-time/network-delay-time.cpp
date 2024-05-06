class Solution {
    int minDist(vector<int> &dist, vector<bool> &vis) {
        int mini = INT_MAX, index = -1;
        for (int i = 1; i < dist.size(); i++) {
            if (!vis[i] && dist[i] < mini) {
                mini = dist[i];
                index = i;
            }
        }
        return index;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &it : times) {
            adj[it[0]].push_back({ it[1], it[2] });
        }
        vector<int> dist(n + 1, INT_MAX);
        vector<bool> vis(n + 1, false);
        dist[k] = 0;
        for (int count = 0; count < n; count++) {
            int u = minDist(dist, vis);
            if (u == -1) break;
            vis[u] = true;
            for (auto it : adj[u]) {
                if (!vis[it.first] && dist[u] != INT_MAX && dist[u] + it.second < dist[it.first])
                    dist[it.first] = dist[u] + it.second;
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};