void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int m=boardSize,n=boardColSize[0];
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int live=0;
            for(int d=0;d<8;d++){
                int ni=i+dx[d],nj=j+dy[d];
                if(ni>=0&&ni<m&&nj>=0&&nj<n&&abs(board[ni][nj])==1){
                    live++;
                }
            }
            if(board[i][j]==1&&(live<2||live>3)){
                board[i][j]=-1;
            }
            if(board[i][j]==0&&live==3){
                board[i][j]=2;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]==-1) board[i][j]=0;
            if(board[i][j]==2) board[i][j]=1;
        }
    }
}