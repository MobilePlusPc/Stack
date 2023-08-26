#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack {
     unsigned int capacity;
     int* data;
};

struct Stack* create_stack();
void push(struct Stack* stack, int data);
void pop(struct Stack* stack);
int top(struct Stack* stack);
bool is_empty(struct Stack* stack);

int main (int argc, char* argv[]) {
     struct Stack* stack = create_stack();

     push(stack, 5);
     push(stack, 4);
     push(stack, 3);
     push(stack, 2);
     push(stack, 1);

     while (!is_empty(stack)) {
          printf("%d\n", top(stack));
          pop(stack);
     }

     // Clean up
     free(stack->data);
     free(stack);
     fflush(stdout);

     return 0;
}

// Creates new stack
struct Stack* create_stack() {
     struct Stack* new_stack = (struct Stack*) malloc(sizeof(struct Stack)); // Create new stack for returning

     if (new_stack == NULL) {
          printf("Failed to allocate memory for stack\n");
          exit(1);
     }

     new_stack->capacity = 0; // Set capacity
     new_stack->data = NULL; // Set data

     return new_stack;
}

void push(struct Stack* stack, int data) {
     stack->capacity++; // Increment the capacity of the stack
     stack->data = (int*) realloc(stack->data, stack->capacity * sizeof(int)); // Re-allocate memory for new data

     if (stack->data == NULL) {
          printf("Failed to allocate memory for new data\n");
          exit(1);
     }
     
     stack->data[stack->capacity - 1] = data; // Arrays start at 0 -> [stack->capacity - 1]
}

void pop(struct Stack* stack) {
     if (!is_empty(stack)) {
          stack->capacity--; // Decrement capacity of the stack
          stack->data = (int*) realloc(stack->data, stack->capacity * sizeof(int)); // De-allocate memory of the deleted data
     } else {
          printf("Stack is empty\n");
     }
}

int top(struct Stack* stack) {
     if (!is_empty(stack)) {
          return stack->data[stack->capacity - 1];
     } else {
          printf("Stack is empty\n");
          return -1;
     }
}

bool is_empty(struct Stack* stack) {
     return (stack->capacity == 0); // Expands -> if (stack->capacity == 0) return true; else return false;
}
