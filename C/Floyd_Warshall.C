#include <stdio.h>
#include <math.h>

int min(int a,int b){
    return a<b?a:b;
}
void FW(int graph[10][10],int v){
    for(int k=0;k<v;k++){
        printf("\n\nNextITERATION\n");
        for(int i=0;i<v;i++)
            for(int j=0;j<v;j++){
                if (graph[i][k]!=0xFFFF ||graph[k][j]!=0xFFFF)
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }

        for(int i=0;i<v;i++){
            for (int j=0;j<v;j++)
                printf("%6d",graph[i][j]);
            printf("\n");
        }
    }
}
int main(){
    int graph[10][10]={{0,2,3,4},{0xFFFF,0,0xFFFF,15},{0xFFFF,4,0,30},{0xFFFF,0xFFFF,0xFFFF,0}};
    FW(graph,4);
    return 0;
}
