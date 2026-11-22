
# Reversing a Doubly Linked List

## Aim
To reverse a doubly linked list by swapping the next and previous pointers of each node in C.

## Algorithm
1. Create a doubly linked list with the given number of nodes.
2. Initialize `current` to the head of the list.
3. Traverse the list until `current` becomes NULL.
4. For each node:
   - Store its previous pointer in `temp`.
   - Set its previous pointer to its next pointer.
   - Set its next pointer to `temp`.
   - Move `current` to its previous pointer (the original next node).
5. Update the head pointer to the last processed node.
6. Display the reversed linked list.

## Sample Input
Number of nodes: 4

Linked list: 10 20 30 40

## Sample Output
Original List:
10 20 30 40

Reversed List:
40 30 20 10

## Complexity Analysis
- Time Complexity: O(n)
- Auxiliary Space Complexity: O(1)

## Approach
The program reverses the doubly linked list in-place by swapping the next and previous pointers of every node.

No additional linked list or array is required. The head pointer is updated after traversal to point to the new first node.