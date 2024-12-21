class Solution {
    int dfs(int curr,int par,vector<int> adj[],vector<int> &values,int k,int &ans){
        int sum=0;
        for(auto it:adj[curr]){
            if(it!=par){
                sum+= dfs(it,curr,adj,values,k,ans);
                sum%=k;
            }
        }
        sum+= values[curr];
        sum%=k;
        if(sum==0) ans++;
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adj[n];
        for(auto &it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans =0;
        dfs(0,-1,adj,values,k,ans);
        return ans;
    }
};