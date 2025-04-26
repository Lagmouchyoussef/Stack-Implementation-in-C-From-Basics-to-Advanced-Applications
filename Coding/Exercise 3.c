#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char character;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} CharStack;

CharStack* create_char_stack() {
    CharStack *s = (CharStack*)malloc(sizeof(CharStack));
    s->top = NULL;
    return s;
}

bool is_char_stack_empty(CharStack *s) {
    return s->top == NULL;
}

void char_push(CharStack *s, char c) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->character = c;
    newNode->next = s->top;
    s->top = newNode;
}

char char_pop(CharStack *s) {
    if (is_char_stack_empty(s)) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    Node *temp = s->top;
    char c = temp->character;
    s->top = s->top->next;
    free(temp);
    return c;
}

void reverse_string(char *str) {
    CharStack *s = create_char_stack();
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        char_push(s, str[i]);
    }
    
    for (int i = 0; i < length; i++) {
        str[i] = char_pop(s);
    }
    
    free(s);
}

int main() {
    char input[100];
    
    printf("Enter a string to reverse: ");
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = '\0';
    
    printf("Original string: %s\n", input);
    reverse_string(input);
    printf("Reversed string: %s\n", input);
    
    return 0;
}