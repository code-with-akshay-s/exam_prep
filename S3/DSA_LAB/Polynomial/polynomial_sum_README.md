# Polynomial Addition Using Structures

## Aim
To add two polynomials using arrays of structures in C.

## Operations Supported
- Addition of two polynomials
- Addition of terms with matching exponents
- Copying terms with different exponents
- Elimination of terms with zero coefficients

## Algorithm
1. Read the number of terms in both polynomials.
2. Read the coefficients and exponents of each term.
3. Initialize three pointers `i`, `j`, and `k` to zero.
4. Compare the exponents of both polynomials:
   - If equal, add the coefficients and store the result if non-zero.
   - If the first exponent is greater, copy the first term.
   - Otherwise, copy the second term.
5. Copy any remaining terms from either polynomial.
6. Display the resulting polynomial.

## Sample Input
```text
First polynomial:
3
5 3
4 2
2 0

Second polynomial:
3
3 3
-4 2
6 1
```

## Sample Output
```text
The final added result:
8x^3 + 6x^1 + 2x^0
```

## Complexity Analysis
- **Time Complexity:** O(n + m)
- **Auxiliary Space Complexity:** O(n + m)

Here, `n` and `m` are the number of terms in the first and second polynomials respectively.

## Approach
Array of structures with two-pointer traversal. Both polynomials must be entered in descending order of exponents.