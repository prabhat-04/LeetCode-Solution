class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> col(V,-1);
        queue<pair<int,int>> q;
        for(int i=0;i<V;i++){
            if(col[i]==-1){
                q.push({i,0});
                col[i]=0;

                while(!q.empty()){
                    pair<int,int> p = q.front();
                    q.pop();

                    int v = p.first;
                    int c = p.second;
                    // cout<<v<<" "<<c<<endl;
                    for(int j : graph[v]){
                        if(col[j]==c)
                            return 0;
                        if(col[j]==-1){
                            col[j] = c? 0:1;
                            q.push({j,col[j]});
                            // cout<<i<<" "<<j<<" "<<col[j]<<endl;
                        }
                    }
                }
            }
        }
        return 1;
    }
};