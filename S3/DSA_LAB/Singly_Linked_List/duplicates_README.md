
# Removing Duplicates from a Singly Linked List

## Aim
To remove duplicate elements from a singly linked list using nested traversal in C.

## Algorithm
1. Create a singly linked list with the given number of nodes.
2. Initialize `temp` to the head of the list.
3. For each node pointed to by `temp`:
   - Initialize `prev` to `temp`.
   - Initialize `ptr` to the next node.
4. Traverse the remaining list using `ptr`.
5. If `temp->data` is equal to `ptr->data`:
   - Update `prev->next` to skip the duplicate node.
   - Free the memory occupied by the duplicate node.
6. Otherwise, move `prev` and `ptr` forward.
7. Move `temp` to the next node and repeat until the end.
8. Display the list after removing duplicates.

## Sample Input
Number of nodes: 6

Linked list: 10 20 30 20 40 10

## Sample Output
List after removing duplicates:
10 20 30 40

## Complexity Analysis
- Time Complexity: O(n²)
- Auxiliary Space Complexity: O(1)

## Approach
The program uses two nested traversals to identify and remove duplicate nodes.

The outer pointer selects each node, while the inner pointer checks all subsequent nodes for matching values. Duplicate nodes are removed by updating links and freeing their allocated memory.

This approach works for both sorted and unsorted linked lists.