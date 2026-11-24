
# Priority Queue Using Array

## Aim
To generate the customer completion sequence based on priority using an array and Bubble Sort in C.

## Problem Statement
The General Post Office gives preferential treatment to customers based on their category.

The priority order is:

1. Differently abled
2. Senior citizen
3. Defence personnel
4. Ordinary person

The program arranges customers in decreasing order of preference (highest priority first).

## Algorithm

1. Read the number of customers.
2. Read each customer's ID and category priority.
3. Validate the number of customers and priority values.
4. Sort the customers according to priority using Bubble Sort.
5. Whenever two priorities are swapped, swap their corresponding customer IDs as well.
6. Display the customer completion sequence.

## Priority Mapping

| Priority | Customer Category |
|---|---|
| 1 | Differently abled |
| 2 | Senior citizen |
| 3 | Defence personnel |
| 4 | Ordinary person |

## Sample Input

Number of customers: 5

| Customer ID | Priority |
|---|---:|
| 101 | 4 |
| 102 | 1 |
| 103 | 3 |
| 104 | 2 |
| 105 | 1 |

## Sample Output

```text
Customer Completion Sequence:
ID: 102 | Priority: 1 | Category: Differently abled
ID: 105 | Priority: 1 | Category: Differently abled
ID: 104 | Priority: 2 | Category: Senior citizen
ID: 103 | Priority: 3 | Category: Defence personnel
ID: 101 | Priority: 4 | Category: Ordinary person
```

## Complexity Analysis

- Time Complexity: O(n²) - Bubble Sort
- Auxiliary Space Complexity: O(1)
- Array Storage Space: O(n)

## Key Concept

A priority queue serves elements according to their priority rather than simply following their arrival order.

This implementation uses Bubble Sort to arrange customers in increasing order of priority values, where priority 1 represents the highest preference.

The sorting is stable, so customers belonging to the same category retain their original arrival order.