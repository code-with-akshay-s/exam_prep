# Binary Search

## Aim
To implement Binary Search in C to find a given element in a sorted array.

## Algorithm
1. Initialize `low = 0` and `high = n - 1`.
2. Calculate the middle index.
3. If the middle element equals the search key, return its index.
4. If the search key is smaller, search the left half.
5. Otherwise, search the right half.
6. Repeat until the element is found or `low > high`.
7. If the element is not found, return `-1`.

## Important Condition
The input array must be sorted in ascending order.

## Sample Input
```text
Enter the number of elements: 5
Enter the elements in ascending order:
10 20 30 40 50
Enter the element to search: 30
```

## Sample Output
```text
Element found at index 2
```

## Complexity Analysis
- **Best Case:** O(1)
- **Average Case:** O(log n)
- **Worst Case:** O(log n)
- **Auxiliary Space:** O(1)

## Approach
Iterative Binary Search.