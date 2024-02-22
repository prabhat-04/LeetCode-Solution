class Solution {
public:
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}} ;

    bool rec(vector<vector<char>>& board,vector<vector<int>> &vis,string word,int x,int y,int ind){
        if(ind==word.size())
            return true;
        int n = board.size(),m=board[0].size();
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int new_x = x + dir[i][0];
            int new_y = y + dir[i][1];
            if(new_x>=0 &&  new_x<n && new_y>=0 && new_y<m && vis[new_x][new_y]==0 && board[new_x][new_y]==word[ind]){
                if(rec(board,vis,word,new_x,new_y,ind+1)) return true;
            }    
        }
        vis[x][y]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    if(rec(board,vis,word,i,j,1)) return true;
                    vis[i][j]=false;
                }
            }
        }
        return false;
    }
};