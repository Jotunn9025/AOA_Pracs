#include <stdio.h>
#include <limits.h>

#define V 4  

int findMinDistance(int distance[],int visited[]) {//min dist funct
    int min=INT_MAX;
    int min_index=-1;
    for (int v=0; v<V; v++) {
        if (!visited[v] && distance[v]<min) {
            min=distance[v];
            min_index=v;
        }
    }
    return min_index;
}

void Dijkstra(int graph[V][V],int source) {
    int distance[V];
    int visited[V];

    for (int i=0; i<V; i++) {
        distance[i]=INT_MAX;
        visited[i]=0;
    }
    distance[source]=0;
    for (int count=0; count<V - 1; count++) {
        int u=findMinDistance(distance,visited);//first min dist will always be 0,0 for source 0 i.e first visit is to 0
        if (u == -1) break;  
        visited[u]=1;

        for (int v=0; v<V; v++) {
            if (graph[u][v] && !visited[v] && distance[u] != INT_MAX &&
                distance[u] + graph[u][v]<distance[v]) {
                distance[v]=distance[u] + graph[u][v];
            }
        }
    }

    printf("shoterst dist from %d:\n",source);
    for (int i=0; i<V; i++) {
        printf("to %d: %d\n",i,distance[i]);
    }
}

int main() {
    int graph[V][V]={//example
        {0,2,30,5},
        {12,0,11, 12},
        {9 ,4 ,0, 9},
        {10, 6,6,0}
    };
    Dijkstra(graph,0);
    return 0;
}
