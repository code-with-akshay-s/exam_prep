# Browser Navigation Using Doubly Linked List

## Aim
To implement browser navigation using a doubly linked list in C.

## Operations Supported
- Visit a new page
- Navigate to the next page
- Navigate to the previous page
- Delete forward history when visiting a new page after navigating backward

## Algorithm
1. Create a new node whenever a page is visited.
2. Connect the new node to the current page using `prev` and `next` pointers.
3. Delete all forward-history nodes when a new page is visited after moving backward.
4. Move to `current->next` for next-page navigation.
5. Move to `current->prev` for previous-page navigation.
6. Display the current page after each operation.

## Complexity Analysis
- Visit Page: O(f), where f is the number of forward-history pages deleted.
- Next Page: O(1)
- Previous Page: O(1)
- Auxiliary Space: O(n), where n is the number of stored pages.

## Approach
A doubly linked list is used to support navigation in both directions through its `next` and `prev` pointers.