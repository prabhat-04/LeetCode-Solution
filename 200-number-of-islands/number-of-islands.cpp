class Solution {
    int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
    void dfs(vector<vector<char>>& grid,vector<vector<bool>> &vis,int i,int j){
        vis[i][j] = true;
        int n = grid.size(),m=grid[0].size();
        for(int k=0;k<4;k++){
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]=='1'){
                dfs(grid,vis,x,y);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};