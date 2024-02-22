class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int i,int j,char val){
        for(int k=0;k<9;k++){
            if(board[i][k]==val || board[k][j]==val)
                return false;
        }

        int r = i - i%3;
        int c = j - j%3;
        for(int p=0;p<3;p++){
            for(int q=0;q<3;q++){
                if(board[p+r][q+c]==val) return false;
            }
        }
        return true;
    }

    bool sudoku(vector<vector<char>>& board){
        bool flag=false;
        int i,j;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                if(board[i][j]=='.'){
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }
        if(i==9 && j==9) return true;

        for(char x='1';x<='9';x++){
            if(isSafe(board,i,j,x)){
                board[i][j]=x;
                if(sudoku(board)) return true;
                board[i][j]='.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board);
    }
};