# Stack Data Structure in C: Practical Exercises

## Exercise 1: Basic Stack Implementation
Implement an integer stack in C with the following features:

1. Define the `Stack` structure  
2. Write `create_empty_stack()` to initialize an empty stack  
3. Write `is_empty()` to check if the stack is empty  
4. Write `peek()` to return the top element of a non-empty stack  
5. Write `push()` to add an element to the top  
6. Write `pop()` to remove the top element from a non-empty stack  
7. Write `search()` to find a value in the stack (stack and value are parameters)

---

## Exercise 2: Postfix Expression Evaluation
Evaluate arithmetic expressions in postfix notation using only `+`, `-`, `*`, `/` operators. Assume single-digit operands (0-9) with no separators.

Example:  
`36*25+` equals `(3*6)-(2+5)`

1. Write `int evaluate_postfix(char *exp)` to evaluate postfix expressions  
   *Hint: Use an integer stack*  
2. Write a C program to test your function

---

## Exercise 3: String Operations
1. Write a function to reverse a string using a stack  
2. Write a function to check if a string is a palindrome  
   (A palindrome reads the same backward, e.g., "ressasser")

---

## Exercise 4: Delimiter Validation
Write a program to validate arithmetic expressions containing delimiters `{`, `}`, `[`, `]`, `(`, `)`. An expression is valid if:
- Every opening delimiter has a matching closing delimiter of the same type  
- The last opened delimiter must be the first to close  

**Examples:**  
Valid: `{x + (100 - [a + b]) - d}`  
Invalid: `{x + (y - [a + b]) * 20 - [d + c]}`  
*Simulate this using a stack - push openers, pop on closers*

---
