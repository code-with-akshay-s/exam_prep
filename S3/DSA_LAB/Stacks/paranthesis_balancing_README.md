# Parenthesis Balancing Using Stack

## Aim
To check whether an expression contains balanced parentheses using a stack in C.

## Algorithm
1. Initialize an empty stack.
2. Read the expression character by character.
3. If an opening parenthesis `(` is encountered, push it onto the stack.
4. If a closing parenthesis `)` is encountered:
   - If the stack is empty, the expression is not balanced.
   - Otherwise, pop the top element.
5. After processing the expression:
   - If the stack is empty and no unmatched closing parenthesis was found, the expression is balanced.
   - Otherwise, it is not balanced.

## Sample Input
```text
Enter the expression: ((A+B)*C)
```

## Sample Output
```text
The parentheses are balanced
```

## Complexity Analysis
- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(n)

Here, n is the number of characters in the expression.

## Approach
Stack-based implementation using push and pop operations.

## Limitation
This implementation checks round parentheses `()` only. It does not check square brackets `[]` or curly braces `{}`.