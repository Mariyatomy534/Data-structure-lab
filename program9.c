#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;                         
    int u, v, i, j, ne = 1;
    int visited[10] = {0}, min, mincost = 0, cost[10][10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    visited[1] = 1;

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (visited[i] && !visited[j] && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        printf("\nEdge %d: {%d, %d}  cost = %d", ne, u, v, min);

        mincost += min;
        visited[v] = 1;
        cost[u][v] = cost[v][u] = 999;
        ne++;
    }

    printf("\nMinimum cost = %d\n", mincost);

    return 0;
}

