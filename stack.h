typedef enum {type_string, type_int} TYPE;

struct StackElement {
    TYPE type;
    union {
        char      *string;
        int       integer;
    };
};

int top_elem_of_stack;   
struct StackElement *vm_stack;

void init_stack() {
    top_elem_of_stack = 0;
    vm_stack = malloc(sizeof(struct StackElement) * 1024);
}

// Push "elem" to top of stack (type integer)
void push_int(int elem) {
    top_elem_of_stack++;
    vm_stack[top_elem_of_stack].type = type_int;
    vm_stack[top_elem_of_stack].integer = elem;
}

// Push "elem" to top of stack (type string)
void push_string(char elem[]) {
    //Copy instruction string to temporary variable to avoid side effects.
    char elem_copied[32];
    strcpy(elem_copied, elem);
    top_elem_of_stack++;
    vm_stack[top_elem_of_stack].type = type_string;
    vm_stack[top_elem_of_stack].string = elem;
}

// Pop the top element of stack and return it
struct StackElement pop() {
    struct StackElement poppedElement;
    poppedElement.type = vm_stack[top_elem_of_stack].type;
    if(poppedElement.type == type_int){
        poppedElement.integer = vm_stack[top_elem_of_stack].integer;
    }
    if(poppedElement.type == type_string){
        poppedElement.string = strdup(vm_stack[top_elem_of_stack].string);
    }
    top_elem_of_stack--;
    return poppedElement;
}

// Return top element of stack, but don't pop it
struct StackElement peek() {
    struct StackElement poppedElement;
    poppedElement = vm_stack[top_elem_of_stack];
    return poppedElement;
}

// Remove the top element
void drop() {
    top_elem_of_stack--;
}
