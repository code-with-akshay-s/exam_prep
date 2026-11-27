
# Dijkstra's Shortest Path Algorithm in C

## Aim
To implement Dijkstra's algorithm to find the shortest distances from a given source vertex to all other vertices in a weighted directed graph.

## Algorithm
1. Read the number of vertices and their city names.
2. Read the number of edges and initialize the adjacency matrix.
3. Store each edge along with its weight.
4. Initialize all vertices as unvisited and set their distances to infinity.
5. Set the source vertex distance to 0.
6. Find the unvisited vertex with the minimum distance.
7. Mark that vertex as visited.
8. Update the distances of its adjacent unvisited vertices if a shorter path is found.
9. Repeat until all reachable vertices are visited or no reachable unvisited vertex remains.
10. Display the shortest distances from the source vertex.

## Sample Input

    Enter the number of vertices: 5
    Enter the city names:
    A B C D E
    Enter the number of edges: 6
    Enter source destination weight (1-based):
    1 2 10
    1 3 3
    3 2 4
    2 4 2
    3 4 8
    4 5 5
    Enter the source vertex (1 to 5): 1

## Sample Output

    Shortest distances from A:
    A -> A: 0
    A -> B: 7
    A -> C: 3
    A -> D: 9
    A -> E: 14

## Complexity Analysis

- **Time Complexity:** O(V²), where V is the number of vertices.
- **Space Complexity:** O(V²), due to the adjacency matrix.

## Notes
- The program uses an adjacency matrix representation.
- The graph is directed.
- Negative edge weights are not allowed because Dijkstra's algorithm does not support them.
- Unreachable vertices are displayed as "No path".
- Vertices are entered using 1-based numbering.

## Language
C