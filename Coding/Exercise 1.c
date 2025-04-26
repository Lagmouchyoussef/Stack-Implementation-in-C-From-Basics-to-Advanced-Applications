#include <stdio.h>
#include <stdlib.h>
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

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->top->value;
}

void push(Stack *s, int v) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->value = v;
        newNode->next = s->top;
        s->top = newNode;
    } else {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
}

void pop(Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack is empty\n");
        exit(EXIT_FAILURE);
    }
    Node *toRemove = s->top;
    s->top = s->top->next;
    free(toRemove);
}

bool search(Stack *s, int searchValue) {
    bool found = false;
    Stack *tempStack = create_stack();
    
    while (!is_empty(s)) {
        if (peek(s) == searchValue) {
            found = true;
            break;
        }
        push(tempStack, peek(s));
        pop(s);
    }
    
    while (!is_empty(tempStack)) {
        push(s, peek(tempStack));
        pop(tempStack);
    }
    
    free(tempStack);
    return found;
}

void print_stack(Stack *s) {
    Node *current = s->top;
    printf("Top -> ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Stack *myStack = create_stack();
    
    printf("Is stack empty? %s\n", is_empty(myStack) ? "Yes" : "No");
    
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    
    print_stack(myStack);
    
    printf("Top element: %d\n", peek(myStack));
    printf("Is stack empty? %s\n", is_empty(myStack) ? "Yes" : "No");
    printf("Search for 20: %s\n", search(myStack, 20) ? "Found" : "Not found");
    printf("Search for 40: %s\n", search(myStack, 40) ? "Found" : "Not found");
    
    pop(myStack);
    print_stack(myStack);
    
    pop(myStack);
    pop(myStack);
    printf("Is stack empty? %s\n", is_empty(myStack) ? "Yes" : "No");
    
    free(myStack);
    return 0;
}