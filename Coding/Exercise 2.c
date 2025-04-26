#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack* create_stack() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

bool is_empty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->value = v;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = s->top;
    int value = temp->value;
    s->top = s->top->next;
    free(temp);
    return value;
}

int evaluate_postfix(char *exp) {
    Stack *s = create_stack();
    int i = 0;
    
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(s, exp[i] - '0'); 
        } else {
            int operand2 = pop(s);
            int operand1 = pop(s);
            
            switch (exp[i]) {
                case '+':
                    push(s, operand1 + operand2);
                    break;
                case '-':
                    push(s, operand1 - operand2);
                    break;
                case '*':
                    push(s, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    push(s, operand1 / operand2);
                    break;
                default:
                    printf("Error: invalid operator '%c'\n", exp[i]);
                    exit(EXIT_FAILURE);
            }
        }
        i++;
    }
    
    int result = pop(s);
    if (!is_empty(s)) {
        printf("Error: invalid expression\n");
        exit(EXIT_FAILURE);
    }
    
    free(s);
    return result;
}

int main() {
    char expression[100];
    
    printf("Enter a postfix expression (without spaces): ");
    scanf("%s", expression);
    
    int result = evaluate_postfix(expression);
    printf("Result: %d\n", result);
    
    return 0;
}