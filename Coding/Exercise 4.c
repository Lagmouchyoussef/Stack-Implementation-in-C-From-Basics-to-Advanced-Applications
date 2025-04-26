#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char delimiter;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} DelimiterStack;

DelimiterStack* create_stack() {
    DelimiterStack *s = (DelimiterStack*)malloc(sizeof(DelimiterStack));
    s->top = NULL;
    return s;
}

bool is_empty(DelimiterStack *s) {
    return s->top == NULL;
}

void push(DelimiterStack *s, char c) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->delimiter = c;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(DelimiterStack *s) {
    if (is_empty(s)) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = s->top;
    char c = temp->delimiter;
    s->top = s->top->next;
    free(temp);
    return c;
}

bool is_matching_pair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

bool is_balanced(char *expr) {
    DelimiterStack *s = create_stack();
    int length = strlen(expr);

    for (int i = 0; i < length; i++) {
        char c = expr[i];
        
        
        if (c == '(' || c == '[' || c == '{') {
            push(s, c);
        }
       
        else if (c == ')' || c == ']' || c == '}') {
            if (is_empty(s)) {
                free(s);
                return false; 
            }
            char popped = pop(s);
            if (!is_matching_pair(popped, c)) {
                free(s);
                return false; 
            }
        }
    }

    bool balanced = is_empty(s);
    free(s);
    return balanced; 
}

int main() {
    char expr[100];

    printf("Enter an arithmetic expression: ");
    fgets(expr, sizeof(expr), stdin);

    expr[strcspn(expr, "\n")] = '\0';

    if (is_balanced(expr)) {
        printf("The expression is balanced.\n");
    } else {
        printf("The expression is NOT balanced.\n");
    }

    return 0;
}