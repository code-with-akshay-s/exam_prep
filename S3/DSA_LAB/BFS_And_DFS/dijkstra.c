
#include <stdio.h>

#define MAX 20
#define INF 1000000000

int main()
{
    int adj[MAX][MAX], visited[MAX], dist[MAX];
    int i, u, v, j, count, min, n, e, source, weight;
    char city[MAX][30];

    printf("Enter the number of vertices: ");

    if(scanf("%d", &n) != 1 || n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter the city names:\n");

    for(i = 0; i < n; i++)
    {
        if(scanf("%29s", city[i]) != 1)
        {
            printf("Invalid city name\n");
            return 1;
        }
    }

    printf("Enter the number of edges: ");

    if(scanf("%d", &e) != 1 || e < 0 || e > n * (n - 1))
    {
        printf("Invalid number of edges\n");
        return 1;
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                adj[i][j] = 0;
            else
                adj[i][j] = INF;
        }
    }

    printf("Enter source destination weight (1-based):\n");

    for(i = 0; i < e; i++)
    {
        if(scanf("%d %d %d", &u, &v, &weight) != 3 ||
           u < 1 || u > n || v < 1 || v > n ||
           weight < 0 || weight >= INF)
        {
            printf("Invalid edge or weight\n");
            return 1;
        }

        adj[u-1][v-1] = weight;
    }

    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
        dist[i] = INF;
    }

    printf("Enter the source vertex (1 to %d): ", n);

    if(scanf("%d", &source) != 1 || source < 1 || source > n)
    {
        printf("Invalid source vertex\n");
        return 1;
    }

    source--;

    dist[source] = 0;

    // Dijkstra's algorithm
    for(count = 0; count < n; count++)
    {
        min = INF;
        u = -1;

        // Find the unvisited vertex with minimum distance
        for(i = 0; i < n; i++)
        {
            if(visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for(v = 0; v < n; v++)
        {
            if(adj[u][v] != INF && visited[v] == 0)
            {
                if(dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    printf("\nShortest distances from %s:\n", city[source]);

    for(i = 0; i < n; i++)
    {
        if(dist[i] == INF)
        {
            printf("%s -> %s: No path\n", city[source], city[i]);
        }
        else
        {
            printf("%s -> %s: %d\n", city[source], city[i], dist[i]);
        }
    }

    return 0;
}