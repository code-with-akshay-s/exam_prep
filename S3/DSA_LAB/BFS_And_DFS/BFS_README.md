
# BFS Traversal and Connected Components in C

## Aim
To implement Breadth-First Search (BFS) traversal using a queue and find the number of connected components in an undirected graph.

## Problem Statement
Given an undirected graph represented using an adjacency matrix, perform BFS traversal and identify all connected components in the graph.

## Algorithm

1. Read the number of vertices and edges.
2. Initialize the adjacency matrix and visited array.
3. Read the edges and construct the undirected graph.
4. Initialize the connected component count to zero.
5. Traverse all vertices:
   - If a vertex is unvisited, increment the component count.
   - Perform BFS starting from that vertex.
6. During BFS:
   - Insert the starting vertex into the queue.
   - Mark it as visited.
   - Remove vertices from the queue one by one.
   - Visit all unvisited adjacent vertices and insert them into the queue.
7. Display the BFS traversal of each component.
8. Display the total number of connected components.

## Data Structures Used

- **Adjacency Matrix:** Represents connections between vertices.
- **Queue:** Maintains the order of vertices during BFS.
- **Visited Array:** Prevents repeated visits to vertices.

## Sample Input

```text
Enter the number of vertices: 6
Enter the number of edges: 4
Enter the edges that are adjacent:
1 2
1 3
2 4
5 6
```

## Sample Output

```text
BFS Traversal:

Component 1: V1 V2 V3 V4
Component 2: V5 V6

Number of connected components: 2
```

## Complexity Analysis

- **Time Complexity:** O(V²), since an adjacency matrix is used and all vertices are examined.
- **Space Complexity:** O(V²), for the adjacency matrix and auxiliary data structures.

## Key Concepts

- Breadth-First Search
- Graph representation using adjacency matrix
- Queue operations
- Visited array
- Connected components in an undirected graph

## Note

The outer loop ensures that BFS is performed from every unvisited vertex. This allows the program to traverse disconnected graphs and count isolated vertices as individual connected components.