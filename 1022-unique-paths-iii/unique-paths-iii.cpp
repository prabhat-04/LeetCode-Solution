class Solution {
public:
    int dirx[4] = {1,-1,0,0};
    int diry[4] = {0,0,1,-1};

    void help(pair<int,int> start,pair<int,int> end,vector<vector<int>>& grid,vector<vector<bool>>& vis,int &ans,int &cnt,int temp){
        if(start==end){
            if(temp==cnt-1)
                ans++;
            return;
        }
        vis[start.first][start.second]=true;
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<4;i++){
            int new_x = start.first+dirx[i];
            int new_y = start.second+diry[i];
            if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && !vis[new_x][new_y] && grid[new_x][new_y]!=-1){
                help({new_x,new_y},end,grid,vis,ans,cnt,temp+1);
            }
        }
        vis[start.first][start.second]=false;
        // temp--;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans =0;
        pair<int,int> start,end;
        int cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) start={i,j};
                if(grid[i][j]==2) end={i,j};
                if(grid[i][j]==-1) cnt++;
            }
        }
        cnt = grid.size() * grid[0].size() - cnt;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        // int  temp=0;
        help(start,end,grid,vis,ans,cnt,0);
        return ans;
    }
};