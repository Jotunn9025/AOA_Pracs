def PrintBoard(board,N):
    boardstr=""
    for i in range(N):
        rowstr=""
        for j in range(N):
            if board[i][j]==True:#if queen print q
                rowstr+="Q"
            else:
                rowstr+="."#if no queen print a .
        boardstr+=(rowstr+"\n")
    print(boardstr)
def isSafe(row,col,board):#function to see if position is safe
    for i in range(len(board)):
        if board[i][col]==True or board[row][i]==True:
            return False
    i=row-1
    j=col-1
    while i>=0 and j>=0:#check upper left diag
        if board[i][j]==True:
            return False
        i,j=i-1,j-1
    i=row-1
    j=col+1
    while i>=0 and j<len(board):#check upper right diag
        if board[i][j]==True:
            return False
        i,j=i-1,j+1
    return True
def SolveNQueens(board,row,N):#reursive function to go down the rows and get all valid solutions
    if row==N:
        PrintBoard(board,N)
        return
    for col in range(N):
        if isSafe(row,col,board):
            board[row][col]=True
            SolveNQueens(board,row+1,N)
            board[row][col]=False

def NQueens(N):#function that prints all solutions for a particular size board
    board=[[False for i in range(N)]for j in range(N)]
    SolveNQueens(board,0,N)
    
NQueens(9)