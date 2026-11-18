
# Reversing a Singly Linked List

## Aim
To reverse a singly linked list using an iterative approach in C.

## Algorithm
1. Initialize `prev` to NULL.
2. Traverse the linked list using `current`.
3. Store the next node in `next`.
4. Reverse the link by assigning `current->next = prev`.
5. Move `prev` and `current` one step forward.
6. Update the head pointer to `prev`.

## Sample Input
```text
Enter the number of nodes: 5
Enter the data: 10
Enter the data: 20
Enter the data: 30
Enter the data: 40
Enter the data: 50
```

## Sample Output
```text
Reversed linked list: 50  40  30  20  10
```

## Complexity Analysis
- Time Complexity: O(n)
- Auxiliary Space Complexity: O(1)

## Approach
The three-pointer technique (`prev`, `current`, and `next`) is used to reverse the links without creating additional nodes.