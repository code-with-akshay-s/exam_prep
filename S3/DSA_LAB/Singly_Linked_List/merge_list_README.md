
# Merging Two Sorted Singly Linked Lists

## Aim
To merge two sorted singly linked lists into a single sorted linked list in C.

## Algorithm
1. Create two sorted singly linked lists.
2. Initialize a dummy node and a tail pointer.
3. Compare the data of the first nodes of both lists.
4. Attach the smaller node to the merged list.
5. Move the corresponding input pointer forward.
6. Repeat until one of the lists becomes empty.
7. Attach the remaining nodes to the merged list.
8. Display the final merged list.

## Sample Input
```text
First list: 10 20 30
Second list: 15 25 40
```

## Sample Output
```text
The final merged list:
10 15 20 25 30 40
```

## Complexity Analysis
- Time Complexity: O(n + m)
- Auxiliary Space Complexity: O(1)

Where n and m are the number of nodes in the two input lists.

## Approach
The two sorted linked lists are merged by comparing their node values and rearranging existing links. A dummy node is used to simplify the merging process. Duplicate values are preserved.