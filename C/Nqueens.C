#include<stdio.h>
#define N 5

int isSafe(int board[N][N],int row,int col){
    for (int i=0;i<N;i++){
        if (board[row][i]==1 || board[i][col]==1)
            return 0;
        int p=row-1,q=col-1;
        while(p>=0 && q>=0){
            if (board[p--][q--]==1)
                return 0;
        }
        int r=row-1,s=col+1;
        while(r>=0 && s<N){
            if (board[r--][s++]==1)
                return 0;
        }
    }
    return 1;
}
void SolveNQueens(int board[N][N],int row){
    if(row==N){
        printf("\n\n");
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if (board[i][j])
                    printf("Q");
                else
                    printf(".");
            }
            printf("\n");
        }
    }
    for(int col=0;col<N;col++){
        if (isSafe(board,row,col)){
            board[row][col]=1;
            SolveNQueens(board,row+1);
            board[row][col]=0;
        }
    }
}
int main() {
    int board[N][N] = {0};
    SolveNQueens(board, 0);
    return 0;
}
