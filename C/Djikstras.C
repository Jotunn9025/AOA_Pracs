#include <stdio.h>
#include <limits.h>
void Djikstras(int graph[10][10],int distance[10],int v,int source,int visited[10]){
    visited[source]=1;
    distance[source]=0;
    for (int i=0;i<v;i++){
        if (graph[source][i]!=INT_MAX)
            distance[i]=graph[source][i];
    }
    int curr_vertex=source;
    int minvertex=-1;
    int min=INT_MAX;
    while (1){
        int visitcount=0;
        for (int i=0;i<v;i++){
            if (visited[i])
                visitcount++;
        }
        if (visitcount==v)
            break;
        int minvertex=-1;
        int min=INT_MAX;
        for(int i=0;i<v;i++){
            if (distance[i]<min && !visited[i]){
                min=distance[i];
                minvertex=i;
            } 
        }
        if (minvertex==-1){
            printf("cant reach");
            return;
        }
        visited[minvertex]=1;   
        for(int i=0;i<v;i++){
            if (!visited[i]&& graph[minvertex][i]!=INT_MAX){
                int travel=distance[minvertex]+graph[minvertex][i];
                distance[i]=distance[i]<travel?distance[i]:travel;
            }
        }
    }
}

int main() {
    int v = 5;
    int graph[10][10] = {
        {0,     10,    3,     INT_MAX, INT_MAX},
        {INT_MAX, 0,     1,     2,     INT_MAX},
        {INT_MAX, 4,     0,     8,     2},
        {INT_MAX, INT_MAX, INT_MAX, 0,     7},
        {INT_MAX, INT_MAX, INT_MAX, 9,     0}
    };

    int distance[10]={INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX};
    int visited[10]={0};
    int source = 0;

    for (int i = 0; i < v; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    Djikstras(graph, distance, v, source, visited);

    printf("Shortest distances from vertex %d:\n", source);
    for (int i = 0; i < v; i++) {
        if (distance[i] == INT_MAX) {
            printf("Vertex %d: Unreachable\n", i);
        } else {
            printf("Vertex %d: %d\n", i, distance[i]);
        }
    }

    return 0;
}
