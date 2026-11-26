
# DFS Traversal and Connected Components in C

## Aim
To implement Depth-First Search (DFS) using recursion and find the number of connected components in an undirected graph.

## Problem Statement
Given an undirected graph represented using an adjacency matrix, perform DFS traversal and identify all connected components.

## Algorithm

1. Read the number of vertices and edges.
2. Initialize the adjacency matrix and visited array.
3. Read the edges and construct the undirected graph.
4. Initialize the connected component count to zero.
5. Traverse all vertices:
   - If a vertex is unvisited, increment the component count.
   - Perform DFS starting from that vertex.
6. During DFS:
   - Mark the current vertex as visited.
   - Display the current vertex.
   - Check all adjacent vertices.
   - Recursively visit every unvisited adjacent vertex.
7. Display the total number of connected components.

## Data Structures Used

- **Adjacency Matrix:** Represents connections between vertices.
- **Visited Array:** Prevents repeated visits to vertices.
- **Recursion Stack:** Maintains function calls during DFS traversal.

## Sample Input

```text
Enter the number of vertices: 6
Enter the number of edges: 4
Enter the edges:
1 2
1 3
2 4
5 6
```

## Sample Output

```text
DFS Traversal:

Component 1: V1 V2 V4 V3
Component 2: V5 V6

The number of connected components is 2
```

## Complexity Analysis

- **Time Complexity:** O(V²), because an adjacency matrix is used.
- **Space Complexity:** O(V²), for the adjacency matrix and auxiliary data structures.

## Key Concepts

- Depth-First Search
- Graph representation using adjacency matrix
- Recursive traversal
- Visited array
- Connected components in an undirected graph

## Note

The outer loop ensures that DFS is performed from every unvisited vertex. This allows the program to traverse disconnected graphs and count isolated vertices as individual connected components.