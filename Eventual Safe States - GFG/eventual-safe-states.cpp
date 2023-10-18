//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> ans;
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(isSafe(i,adj,vis))
                ans.push_back(i);
        }
        return ans;
    }
    
    bool isSafe(int i,vector<int> adj[],vector<int> &vis){
        if(vis[i]==1) return false;
        if(vis[i]==2) return true;
        
        vis[i]=1;
        for(int x : adj[i]){
            int a = vis[x];
            if(a==1) return false;
            if(a==2) continue;
            if(!isSafe(x,adj,vis)) return false;
        }
        vis[i]=2;
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends