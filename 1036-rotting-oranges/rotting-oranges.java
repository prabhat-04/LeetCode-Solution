//custom struct to store 
class Pair{
    int row;
    int col;

    public Pair(int row,int col){
        this.row=row;
        this.col=col;
    }

    public int getRow(){
        return row;
    }

    public int getCol(){
        return col;
    }
}

class Solution {
    int ans=0;
    public int orangesRotting(int[][] grid) {
        

       int rotten_row=-1;
       int rotten_col=-1;
        Queue<Pair> q=new LinkedList<>();

        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
              if(grid[i][j]==2){
                rotten_row=i;
                rotten_col=j;
                q.add(new Pair(rotten_row,rotten_col));
              }
            }
        }
         //if there is no rotten cell
        if(rotten_row==-1){
           return findone(grid);
        }

        q.add(null);
        //level order traversal with bfs
        while(!q.isEmpty()){ 
            Pair p=q.poll();
            //ending of each level
            if(p==null ){
                if(q.isEmpty()){
                break;
            }
            else{
                q.add(null);
                 //increment in ans after each level
                  ans++;
                continue;
            }  
            }
            //continuataion of same level
            int row=p.getRow();
            int col=p.getCol();
            bfs(grid,row,col,q);
        }
        
        //incase there is any fresh orange left-> returning -1
        if(findone(grid)==-1){
            return -1;
        }
        
        // returning final answer
        return ans;
    }

    //function to find 1 (fresh oranges if any)
    public int findone(int[][] grid){
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    //if any fresh orange found -> -1
                    return -1;
                }
            }
        }
        //no fresh oranges in grid
        return 0;
    }

   //bfs for rotting the left , right, up down fresh oranges
   void bfs(int[][] grid, int row, int col, Queue<Pair> q){
        boolean changed=false;
        int r=row;
        int c=col;

        c++;
         if(c<grid[r].length &&  grid[r][c]==1){
            grid[r][c]=2;
            changed=true;
            q.add(new Pair(r,c));
        }
        c-=2;
        if(c>=0 && grid[r][c]==1){
            grid[r][c]=2;
            changed=true;
            q.add(new Pair(r,c));
        }
       c++;
       r--;
        if(r>=0 && grid[r][c]==1){
            grid[r][c]=2;
            changed=true;
            q.add(new Pair(r,c));
        }
       r+=2;
        if(r<grid.length && grid[r][c]==1){
            grid[r][c]=2;
            changed=true;
            q.add(new Pair(r,c));
        }
       
   }
}