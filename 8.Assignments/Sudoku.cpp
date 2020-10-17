struct p{
    int first,row,col;
};


p find(int board[][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                return {1,i,j};
            }
        }
    }
    return {0,0,0};
    
}

bool possible(int board[][9],int key,int row,int col){
    for(int i=0;i<9;i++){
        if((board[i][col]==key)||(board[row][i]==key)) return 0;
    }
    int x=row-row%3,y=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[x+i][y+j]==key) return 0;
        }
    }
    return 1;
}


bool sudokuSolver(int board[][9]){
    //no zero found
    p x =find(board);
    if(!x.first){
       return true; 
    }
    else{
      
        for(int val=1;val<=9;val++){
            if(possible(board,val,x.row,x.col)){
                board[x.row][x.col]=val;
                if(sudokuSolver(board)){
                     return 1;    
                }
                board[x.row][x.col]=0;
            }
        }
    }
    return 0;
    
    
}
