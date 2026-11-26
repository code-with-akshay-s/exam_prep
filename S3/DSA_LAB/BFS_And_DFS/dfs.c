
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX], visited[MAX];

void DFS(int u, int n)
{
    int v;

    visited[u] = 1;
    printf("V%d\t", u + 1);

    for(v = 0; v < n; v++)
    {
        if(adj[u][v] == 1 && visited[v] == 0)
        {
            DFS(v, n);
        }
    }
}

int main()
{
    int n, e, i, j, u, v, count = 0;

    printf("Enter the number of vertices: ");

    if(scanf("%d", &n) != 1 || n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter the number of edges: ");

    if(scanf("%d", &e) != 1 || e < 0)
    {
        printf("Invalid number of edges\n");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;

        for(j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges:\n");

    for(i = 0; i < e; i++)
    {
        if(scanf("%d %d", &u, &v) != 2 ||
           u < 1 || u > n || v < 1 || v > n)
        {
            printf("Invalid edge\n");
            return 1;
        }

        adj[u-1][v-1] = 1;
        adj[v-1][u-1] = 1;
    }

    printf("\nDFS Traversal:\n");

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            count++;
            printf("\nComponent %d: ", count);
            DFS(i, n);
        }
    }

    printf("\n\nThe number of connected components is %d\n", count);

    return 0;
}