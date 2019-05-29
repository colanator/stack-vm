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
    vm_stack[top_elem_of_stack].string = strdup(elem_copied);
    free((char*)elem);
}

// Pop the top element of stack and return it
struct StackElement pop() {
    struct StackElement popped_element;
    popped_element.type = vm_stack[top_elem_of_stack].type;
    if(popped_element.type == type_int){
        popped_element.integer = vm_stack[top_elem_of_stack].integer;
    }
    if(popped_element.type == type_string){
        if (vm_stack[top_elem_of_stack].string == NULL){
            popped_element.string = "";
        } else {
            popped_element.string = strdup(vm_stack[top_elem_of_stack].string);
        }
    }
    top_elem_of_stack--;
    return popped_element;
}

// Return top element of stack, but don't pop it
struct StackElement peek() {
    struct StackElement popped_element;
    popped_element.type = vm_stack[top_elem_of_stack].type;
    if(popped_element.type == type_int){
        popped_element.integer = vm_stack[top_elem_of_stack].integer;
    }
    if(popped_element.type == type_string){
        if (vm_stack[top_elem_of_stack].string == NULL){
            popped_element.string = "";
        } else {
            popped_element.string = strdup(vm_stack[top_elem_of_stack].string);
        }
    }
    return popped_element;
}

// Remove the top element
void drop() {
    if(vm_stack[top_elem_of_stack].type == type_string){
        if(vm_stack[top_elem_of_stack].string){
            free((char*)vm_stack[top_elem_of_stack].string);
        }
    }
    top_elem_of_stack--;
}

// Duplicate top element of stack
void dup() {
    struct StackElement topmost_element;
    topmost_element.type = vm_stack[top_elem_of_stack].type;
    if(topmost_element.type == type_int){
        topmost_element.integer = vm_stack[top_elem_of_stack].integer;
        push_int(topmost_element.integer);
    }
    if(topmost_element.type == type_string){
        if (vm_stack[top_elem_of_stack].string == NULL){
            topmost_element.string = "";
            push_string(topmost_element.string);
        } else {
            topmost_element.string = strdup(vm_stack[top_elem_of_stack].string);
            push_string(topmost_element.string);
        }
    }
}

// Rotate the two top elements of stack
void rot() {
    // fetch two topmost elements
    struct StackElement topmost_element;
    struct StackElement second_topmost_element;
    topmost_element.type = vm_stack[top_elem_of_stack].type;
    if(topmost_element.type == type_int){
        topmost_element.integer = vm_stack[top_elem_of_stack].integer;
    }
    if(topmost_element.type == type_string){
        if (vm_stack[top_elem_of_stack].string == NULL){
            topmost_element.string = "";
        } else {
            topmost_element.string = vm_stack[top_elem_of_stack].string;
        }
    }
    second_topmost_element.type = vm_stack[top_elem_of_stack-1].type;
    if(second_topmost_element.type == type_int){
        second_topmost_element.integer = vm_stack[top_elem_of_stack-1].integer;
    }
    if(second_topmost_element.type == type_string){
        if (vm_stack[top_elem_of_stack-1].string == NULL){
            second_topmost_element.string = "";
        } else {
            second_topmost_element.string = vm_stack[top_elem_of_stack-1].string;
        }
    }
    // store topmost in temp variable
    struct StackElement temp_topmost_element;
    temp_topmost_element.type = topmost_element.type;
    if(temp_topmost_element.type == type_int){
        temp_topmost_element.integer = topmost_element.integer;
    }
    if(temp_topmost_element.type == type_string){
        if (topmost_element.string == NULL){
            temp_topmost_element.string = "";
        } else {
            temp_topmost_element.string = topmost_element.string;
        }
    }
    // store second topmost element to topmost
    vm_stack[top_elem_of_stack].type = second_topmost_element.type;
    if(vm_stack[top_elem_of_stack].type == type_int){
        vm_stack[top_elem_of_stack].integer = second_topmost_element.integer;
    }
    if(vm_stack[top_elem_of_stack].type == type_string){
        if (vm_stack[top_elem_of_stack].string == NULL){
            vm_stack[top_elem_of_stack].string = "";
        } else {
            vm_stack[top_elem_of_stack].string = second_topmost_element.string;
        }
    }
    // store topmost element to second topmost from temp storage
    vm_stack[top_elem_of_stack-1].type = temp_topmost_element.type;
    if(vm_stack[top_elem_of_stack-1].type == type_int){
        vm_stack[top_elem_of_stack-1].integer = temp_topmost_element.integer;
    }
    if(vm_stack[top_elem_of_stack-1].type == type_string){
        if (temp_topmost_element.string == NULL){
            vm_stack[top_elem_of_stack-1].string = "";
        } else {
            vm_stack[top_elem_of_stack-1].string = temp_topmost_element.string;
        }
    }
}
