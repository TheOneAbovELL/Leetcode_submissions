class Solution:
    def gameOfLife(self, board: List[List[int]]) -> None:
        m,n=len(board),len(board[0])
        dx=[-1,-1,-1,0,0,1,1,1]
        dy=[-1,0,1,-1,1,-1,0,1]
        for i in range(m):
            for j in range(n):
                live=0
                for d in range(8):
                    ni,nj=i+dx[d],j+dy[d]
                    if 0<=ni<m and 0<=nj<n and abs(board[ni][nj])==1:
                        live+=1
                if board[i][j]==1 and (live<2 or live>3):
                    board[i][j]=-1
                if board[i][j]==0 and live==3:
                    board[i][j]=2
        for i in range(m):
            for j in range(n):
                if board[i][j]==-1:
                    board[i][j]=0
                if board[i][j]==2:
                    board[i][j]=1