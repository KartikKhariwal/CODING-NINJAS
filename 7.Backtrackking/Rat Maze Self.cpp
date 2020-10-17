int board[21][21];
#include<bits/stdc++.h>


void solve(int maze[][20],int n,int row,int col){
//soln found
    if(row==n-1&&col==n-1){
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    else{
        //solve subproblem
        //to right constraint
        if(col<n-1&&maze[row][col+1]&&!board[row][col+1]){
            board[row][col+1]=1;
            solve(maze,n,row,col+1);
            board[row][col+1]=0;
        }
        
        //to left
        if(col>0&&maze[row][col-1]&&!board[row][col-1]){
             board[row][col-1]=1;
            solve(maze,n,row,col-1);
            board[row][col-1]=0;
            
        }
        
        //to up
        if(row>0&&maze[row-1][col]&&!board[row-1][col]){
             board[row-1][col]=1;
            solve(maze,n,row-1,col);
            board[row-1][col]=0;
            
        }
        
        //to down
        
        if(row<n-1&&maze[row+1][col]&&!board[row+1][col]){
            board[row+1][col]=1;
            solve(maze,n,row+1,col);
            board[row+1][col]=0;
        }
        
      return ;  
    }
    
    
    
}


void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    memset(board,0,21*21*(sizeof(int)));
    board[0][0]=1;
    solve(maze,n,0,0);
}
