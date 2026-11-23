
# Circular Queue Using Array

## Aim
To implement a circular queue using an array in C and perform enqueue, dequeue, and display operations.

## Operations

1. **Enqueue:** Inserts an element at the rear of the queue.
2. **Dequeue:** Removes an element from the front of the queue.
3. **Display:** Displays all elements currently present in the queue.
4. **Overflow:** Occurs when the queue is full.
5. **Underflow:** Occurs when the queue is empty.

## Algorithm

### Enqueue
1. Check whether the queue is full using `(rear + 1) % N == front`.
2. If full, display Overflow.
3. If the queue is empty, set `front = 0` and `rear = 0`.
4. Otherwise, update `rear = (rear + 1) % N`.
5. Insert the new element at `queue[rear]`.

### Dequeue
1. Check whether the queue is empty (`front == -1`).
2. If empty, display Underflow.
3. Otherwise, store the element at `queue[front]`.
4. If `front == rear`, reset both pointers to `-1`.
5. Otherwise, update `front = (front + 1) % N`.

### Display
1. Check whether the queue is empty.
2. Start traversal from `front`.
3. Display each element until `rear` is reached.
4. Move to the next position using `(i + 1) % N`.

## Sample Input

Queue size: 3

Operations:
- Enqueue 10
- Enqueue 20
- Enqueue 30
- Dequeue
- Enqueue 40
- Display

## Sample Output

```text
10 deleted successfully
40 added successfully
20    30    40
```

## Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Display | O(n) |

- Auxiliary Space Complexity: O(1)
- Queue Storage Space: O(n)

## Key Concept

A circular queue connects the last array position back to the first position. The modulo operator (%) allows the front and rear pointers to wrap around, enabling reuse of vacant positions.

This avoids the space wastage that can occur in a linear queue implemented using an array.