class Solution {
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<int>>& heights,vector<vector<int>> &vec,vector<vector<bool>> &vis){
        vis[i][j]=true;
        vec[i][j]+=1;
        int n = heights.size(),m=heights[0].size();
        for(int k=0;k<4;k++){
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && heights[x][y]>=heights[i][j])
                dfs(x,y,heights,vec,vis);
        }

    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size(),m=heights[0].size();
        vector<vector<int>> vec(n,vector<int>(m,0));
        vector<vector<bool>> vis1(n,vector<bool>(m,false));
        vector<vector<bool>> vis2(n,vector<bool>(m,false));
        for(int j=0;j<m;j++){
            if(!vis1[0][j])
                dfs(0,j,heights,vec,vis1);
            if(!vis2[n-1][j])
                dfs(n-1,j,heights,vec,vis2);
        }
        for(int i=0;i<n;i++){
            if(!vis1[i][0])
                dfs(i,0,heights,vec,vis1);
            if(!vis2[i][m-1])
                dfs(i,m-1,heights,vec,vis2);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vec[i][j]>=2)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};