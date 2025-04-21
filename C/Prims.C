#include <limits.h>
#include <stdio.h>

void prims(int graph[10][10], int source, int v, int selected[]) {
    selected[source] = 1;
    int cost = 0;
    int ne = 0;

    printf("Edges in MST:\n");

    while (ne < v - 1) {
        int min = INT_MAX;
        int x = -1, y = -1;

        for (int i = 0; i < v; i++) {
            if (selected[i]) {
                for (int j = 0; j < v; j++) {
                    if (!selected[j] && graph[i][j] && graph[i][j] < min) {
                        min = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x != -1 && y != -1) {
            printf("%d - %d: %d\n", x, y, graph[x][y]);
            cost += graph[x][y];
            selected[y] = 1;
            ne++;
        }
    }

    printf("Total cost: %d\n", cost);
}
int main() {
    int graph[10][10] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int v = 5; 
    int selected[10] = {0};

    prims(graph, 0, v, selected); 
    return 0;
}