struct Stack {
    int stack[256];
    int top_elem_of_stack;
};
typedef struct Stack STACK;
STACK vm_stack = {.top_elem_of_stack = 0};

// Push "elem" to top of stack
void push(int elem) {
    vm_stack.stack[vm_stack.top_elem_of_stack + 1] = elem;
    vm_stack.top_elem_of_stack++;
}

// Pop the top element of stack and return it
int pop() {
    int popped_elem = vm_stack.stack[vm_stack.top_elem_of_stack];
    vm_stack.top_elem_of_stack--;
    return popped_elem;
}

// Return top element of stack, but don't pop it
int peek() {
    int peek_elem = vm_stack.stack[vm_stack.top_elem_of_stack];
    return peek_elem;
}
