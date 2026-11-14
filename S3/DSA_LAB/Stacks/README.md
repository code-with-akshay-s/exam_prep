# Infix to Postfix Conversion and Evaluation

## Aim
To convert an infix expression into a postfix expression using a stack and evaluate the resulting postfix expression.

## Operations Supported
- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)
- Exponentiation (^)
- Parentheses
- Single-digit numeric operands (0–9)

## Algorithm

### Infix to Postfix Conversion
1. Read the infix expression.
2. If the character is an operand, add it to the postfix expression.
3. If it is an opening parenthesis, push it onto the stack.
4. If it is a closing parenthesis, pop operators until an opening parenthesis is found.
5. If it is an operator, pop operators with higher precedence (or equal precedence for left-associative operators).
6. Push the current operator onto the stack.
7. Pop the remaining operators and append them to the postfix expression.

### Postfix Evaluation
1. Scan the postfix expression from left to right.
2. If the character is a digit, push its integer value onto the evaluation stack.
3. If it is an operator, pop two operands.
4. Perform the operation and push the result.
5. The final stack value is the evaluated result.

## Sample Input
```text
2+3*4
```

## Sample Output
```text
Postfix expression: 234*+
Final evaluated result: 14
```

## Complexity Analysis
- **Time Complexity:** O(n)
- **Auxiliary Space Complexity:** O(n)

Here, n is the number of characters in the infix expression.

## Approach
Stack-based infix-to-postfix conversion followed by postfix evaluation.