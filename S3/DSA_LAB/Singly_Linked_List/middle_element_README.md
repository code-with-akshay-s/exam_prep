
# Finding the Middle Element of a Singly Linked List

## Aim
To find the middle element of a singly linked list using the slow and fast pointer technique in C.

## Algorithm
1. Create a singly linked list with the given number of nodes.
2. Initialize two pointers, `slow` and `fast`, to the head of the list.
3. Move the `slow` pointer one node at a time.
4. Move the `fast` pointer two nodes at a time.
5. Repeat until `fast` reaches the end of the list or its next pointer becomes NULL.
6. The `slow` pointer will point to the middle element.
7. Display the middle element.

## Sample Input
Number of nodes: 5

Linked list: 10 20 30 40 50

## Sample Output
The middle element is: 30

## Complexity Analysis
- Time Complexity: O(n)
- Auxiliary Space Complexity: O(1)

## Approach
The slow and fast pointer technique is used to find the middle element efficiently without counting the nodes or traversing the list twice.

The slow pointer moves one node at a time, while the fast pointer moves two nodes at a time. When the fast pointer reaches the end, the slow pointer points to the middle element.

For an even number of nodes, the program returns the second middle element.