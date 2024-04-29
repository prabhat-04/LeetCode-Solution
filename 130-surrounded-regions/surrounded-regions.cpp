class Solution {
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<bool>> &vis){
        vis[i][j]=true;
        int m = board.size(),n=board[0].size();
        for(int k=0;k<4;k++){
            int x = i+dir[k][0];
            int y = j+dir[k][1];
            if(x>=0 && y>=0 && x<m && y<n && board[x][y]=='O' && !vis[x][y])
                dfs(x,y,board,vis);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            if(board[0][i]=='O' && !vis[0][i])
                dfs(0,i,board,vis);
            if(board[m-1][i]=='O' && !vis[m-1][i])
                dfs(m-1,i,board,vis);
        }
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0])
                dfs(i,0,board,vis);
            if(board[i][n-1]=='O' && !vis[i][n-1])
                dfs(i,n-1,board,vis);
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};