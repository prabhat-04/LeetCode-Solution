class Solution {
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
       vector<vector<int>> ans;
       vector<vector<bool>> vis(land.size(),vector<bool>(land[0].size(),false));
       for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(!vis[i][j] && land[i][j]==1){
                    int minRow=i,minCol=j,maxRow=i,maxCol=j;
                    dfs(land,vis,minRow,minCol,maxRow,maxCol,i,j);
                    ans.push_back({minRow,minCol,maxRow,maxCol});
                }
            }
       }
       return ans;
    }
    void dfs(vector<vector<int>>& land,vector<vector<bool>> &vis,int &minRow,int &minCol,int& maxRow,int &maxCol,int i,int j){
        vis[i][j]=true;
        minRow = min(minRow, i);
        minCol = min(minCol, j);
        maxRow = max(maxRow, i);
        maxCol = max(maxCol, j);
        for(int k=0;k<4;k++){
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            if(x>=0 && x<land.size() && y>=0 && y<land[0].size() && land[x][y]==1 && !vis[x][y])
                dfs(land,vis,minRow,minCol,maxRow,maxCol,x,y);
        }
    }
};