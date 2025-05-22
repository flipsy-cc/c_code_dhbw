#include <stdio.h>
#include <stdlib.h>

// Define the structure for a stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure for the stack itself
typedef struct Stack {
    Node* top;
} Stack;


// variable_type* -> pointer that points to the variable_type
// &x -> address of the variable x
// *x -> dereference the pointer x to access the value it points to
// int* p = &x -> p is a pointer to an integer, and it points to the address of x


// Initialize a new stack
Stack* createStack() {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Error: Not enough memory to create stack.\n");
        return NULL;
    }
    stack->top = NULL;
    return stack;
}

// Push a value onto the stack
void push(Stack* stack, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Not enough memory to push value %d. Destroying stack.\n", value);
        // Destroy stack and exit
        free(stack);
        exit(1);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("Pushed: %d\n", value);
}

// Pop the top value off the stack
int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty. Cannot pop.\n");
        return -1; // Or handle error differently
    }

    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    printf("Popped: %d\n", poppedValue);
    return poppedValue;
}

// Destroy the stack and free memory
void destroyStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(stack);
    printf("Stack destroyed.\n");
}

// Print current contents of the stack
void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack contents (top to bottom): ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function for testing
int main() {
    Stack* myStack = createStack();
    if (myStack == NULL) return 1;

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printStack(myStack);

    pop(myStack);
    printStack(myStack);

    destroyStack(myStack);

    return 0;
}
