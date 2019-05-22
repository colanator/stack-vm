enum DataType { type_string, type_int };

struct StackElement {
    DataType type;
    union {
        char      *str;
        int       i;
    }
};

int top_elem_of_stack = 0;

struct StackElement *vm_stack = malloc(sizeof(struct StackElement) * 1024);

// Push "elem" to top of stack (type integer)
void push(int elem) {
    top_elem_of_stack++;
    vm_stack[top_elem_of_stack].type = type_int;
    vm_stack[top_elem_of_stack].i = elem;
}

// Push "elem" to top of stack (type string)
void push(char elem[]) {
    top_elem_of_stack++;
    vm_stack[top_elem_of_stack].type = type_string;
    vm_stack[top_elem_of_stack].i = elem;
}

// Pop the top element of stack and return it
struct StackElement pop() {
    struct StackElement poppedElement:
    poppedElement = vm_stack[top_elem_of_stack];
    top_elem_of_stack--;
    return poppedElement;
}

// Return top element of stack, but don't pop it
struct StackElement pop() {
    struct StackElement poppedElement:
    poppedElement = vm_stack[top_elem_of_stack];
    return poppedElement;
}

// Remove the top element
void drop() {
    top_elem_of_stack--;
}
