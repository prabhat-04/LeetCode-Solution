class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = help(rowConditions,k);
        vector<int> colOrder = help(colConditions,k);

        if(rowOrder.size()<k || colOrder.size()<k)
            return {};
        
        unordered_map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[colOrder[i]]=i;
        }

        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            ans[i][mp[rowOrder[i]]] = rowOrder[i];
        }
        return ans;
    }

    vector<int> help(vector<vector<int>> conditions,int k){
        vector<vector<int>> graph(k+1);
        vector<int> indegree(k+1,0);

        for(auto it:conditions){
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=1;i<=k;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it:graph[curr]){
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return ans;
    }
};