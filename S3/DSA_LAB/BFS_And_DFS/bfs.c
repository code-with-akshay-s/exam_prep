
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;

void BFS(int start, int n)
{
    int u, v;

    front = rear = -1;

    queue[++rear] = start;
    visited[start] = 1;

    printf("V%d\t", start + 1);

    while(front != rear)
    {
        u = queue[++front];

        for(v = 0; v < n; v++)
        {
            if(visited[v] == 0 && adj[u][v] == 1)
            {
                visited[v] = 1;
                queue[++rear] = v;
                printf("V%d\t", v + 1);
            }
        }
    }
}

int main()
{
    int n, e, count = 0, u, v;

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

    for(int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter the edges that are adjacent:\n");

    for(int i = 0; i < e; i++)
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

    printf("\nBFS Traversal:\n");

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            count++;
            printf("\nComponent %d: ", count);
            BFS(i, n);
        }
    }

    printf("\n\nNumber of connected components: %d\n", count);

    return 0;
}