#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void FW(int matrix[10][10],int e,int source, int v){
        for (int k=0;k<v;k++){
            for (int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    matrix[i][j]=matrix[i][j]>matrix[i][k]+matrix[k][j]?matrix[i][k]+matrix[k][j]:matrix[i][j];//find min
                    matrix[j][j]=0;
                }
            }
            printf("\nSTAGE %d:\n",k+1);
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++)
                    printf("%8d",matrix[i][j]);
                printf("\n");
            }
           
        }
}


int main(){
    printf("enter number of vertices and edges");
    int v,e;
    scanf("%d %d",&v,&e);
    int matrix[10][10];


    for(int i=0;i<v;i++)
            for(int j=0;j<v;j++)
                matrix[i][j]=0xFFFF;


    printf("\n enter the weighted edge list");
    for (int k=0;k<e;k++){
        int vi,vj,weight;
        scanf("%d %d %d",&vi,&vj,&weight);
        matrix[vi][vj]=weight;
    }
    FW(matrix,e,0,v);
        return 0;
}

