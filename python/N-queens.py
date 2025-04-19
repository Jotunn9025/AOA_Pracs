def PrintBoard(board,N):
    boardstr=""
    for i in range(N):
        rowstr=""
        for j in range(N):
            if board[i][j]==True:
                rowstr+="Q"
            else:
                rowstr+="."
        boardstr+=(rowstr+"\n")
    print(boardstr)
def isSafe(row,col,board):
    for i in range(len(board)):
        if board[i][col]==True or board[row][i]==True:
            return False
    i=row-1
    j=col-1
    while i>=0 and j>=0:
        if board[i][j]==True:
            return False
        i,j=i-1,j-1
    i=row-1
    j=col+1
    while i>=0 and j<len(board):
        if board[i][j]==True:
            return False
        i,j=i-1,j+1
    return True
def SolveNQueens(board,row,N):
    if row==N:
        PrintBoard(board,N)
        return
    for col in range(N):
        if isSafe(row,col,board):
            board[row][col]=True
            SolveNQueens(board,row+1,N)
            board[row][col]=False

def NQueens(N):
    board=[[False for i in range(N)]for j in range(N)]
    SolveNQueens(board,0,N)
    
NQueens(12)