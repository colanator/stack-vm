// ADD - instruction
// Parameters are added together, result pushed to stack
void execute_add_instruction(){
    struct StackElement first_element = pop();
    int first_operand = first_element.integer;
    struct StackElement second_element = pop();
    int second_operand = second_element.integer;
    push_int(first_operand + second_operand);
}

// SUB - instruction
// Second parameter is subtracted from the first, result pushed to stack
void execute_sub_instruction(){
    struct StackElement first_element = pop();
    int first_operand = first_element.integer;
    struct StackElement second_element = pop();
    int second_operand = second_element.integer;
    push_int(first_operand - second_operand);
}

// MUL - instruction
// Parameters are multiplied together, result pushed to stack
void execute_mul_instruction(){
    struct StackElement first_element = pop();
    int first_operand = first_element.integer;
    struct StackElement second_element = pop();
    int second_operand = second_element.integer;
    push_int(first_operand * second_operand);
}

// DIV - instruction
// First parameter is divided by the first, result pushed to stack
void execute_div_instruction(){
    struct StackElement first_element = pop();
    int first_operand = first_element.integer;
    struct StackElement second_element = pop();
    int second_operand = second_element.integer;
    push_int(first_operand / second_operand);
}

// PUSH - instruction (string)
// Parameter is pushed to stack
void execute_push_instruction_string(char *elem_to_be_pushed){
    push_string(elem_to_be_pushed);
}
// PUSH - instruction (int)
// Parameter is pushed to stack
void execute_push_instruction_int(int elem_to_be_pushed){
    push_int(elem_to_be_pushed);
}

// DROP - instruction
// Top element of stack is popped (removed)
void execute_drop_instruction(){
    drop();
}

// PRINT - instruction (string)
// Parameter is printed out
void execute_print_instruction_string(char *elem_to_be_printed){
    printf("%s\n", elem_to_be_printed);
}
// PRINT - instruction (int)
// Parameter is printed out
void execute_print_instruction_int(int elem_to_be_printed){
    printf("%i\n", elem_to_be_printed);
}

// PEEK - instruction 
// Top element of stack is printed out without popping
void execute_peek_instruction(){
    struct StackElement element_to_print = peek();
    if (element_to_print.type == type_string){
        printf("%s\n", element_to_print.string);
    }
    if (element_to_print.type == type_int){
        printf("%i\n", element_to_print.integer);
    }
}

// JMP - instruction
// Instruction pointer it set to parameter value
void execute_jmp_instruction(int jmp_target){
    instruction_pointer = jmp_target - 1;
}

// IFEQ - instruction
// If condition matches top element of stack, the next insruction is executed, otherwise instruction pointer is incremented to skip it
void execute_ifeq_instruction(int condition){
    struct StackElement element_to_compare = peek();
    if(condition != element_to_compare.integer){
        instruction_pointer++;
    }
}

// IFLT - instruction
// If condition lesser than element of stack, the next insruction is executed, otherwise instruction pointer is incremented to skip it
void execute_iflt_instruction(int condition){
    struct StackElement element_to_compare = peek();
    if(condition < element_to_compare.integer){
        instruction_pointer++;
    }
}

// IFGT - instruction
// If condition greater than element of stack, the next insruction is executed, otherwise instruction pointer is incremented to skip it
void execute_ifgt_instruction(int condition){
    struct StackElement element_to_compare = peek();
    if(condition > element_to_compare.integer){
        instruction_pointer++;
    }
}

// HALT - instruction
// Instruction pointer it set to 1000, which halts program execution
void execute_halt_instruction(){
    instruction_pointer = 1000;
}

// This function is given a single "instruction" to be executed
void execute_instruction(struct InstrMemElement instruction_to_execute) {

    struct InstrMemElement instruction;

    instruction.opcode = instruction_to_execute.opcode;
    if (instruction_to_execute.param_type == string_param){
        instruction.param_type = string_param;
        instruction.param_string = strdup(instruction_to_execute.param_string);
    }
    if (instruction_to_execute.param_type == int_param){
        instruction.param_type = int_param;
        instruction.param_integer = instruction_to_execute.param_integer;
    }
    
    //Read first token of instruction to determine the operation. Call the relevant instruction command.
    if(strcmp(instruction.opcode, "ADD") == 0) {
        execute_add_instruction();
    } else if(strcmp(instruction.opcode, "SUB") == 0) {
        execute_sub_instruction();
    } else if(strcmp(instruction.opcode, "MUL") == 0) {
        execute_mul_instruction();
    } else if(strcmp(instruction.opcode, "DIV") == 0) {
        execute_div_instruction();
    } else if(strcmp(instruction.opcode, "PUSH") == 0) {
        if (instruction.param_type == string_param){
            execute_push_instruction_string(instruction.param_string);
        }
        if (instruction.param_type == int_param){
            execute_push_instruction_int(instruction.param_integer);
        }
    } else if(strcmp(instruction.opcode, "DROP") == 0) {
        execute_drop_instruction();
    } else if(strcmp(instruction.opcode, "PRINT") == 0) {
        if (instruction.param_type == string_param){
            execute_print_instruction_string(instruction.param_string);
        }
        if (instruction.param_type == int_param){
            execute_print_instruction_int(instruction.param_integer);
        }
    } else if(strcmp(instruction.opcode, "PEEK") == 0) {
        execute_peek_instruction();
    } else if(strcmp(instruction.opcode, "JMP") == 0) {
        execute_jmp_instruction(instruction.param_integer);
    } else if(strcmp(instruction.opcode, "IFEQ") == 0) {
        execute_ifeq_instruction(instruction.param_integer);
    } else if(strcmp(instruction.opcode, "IFGT") == 0) {
        execute_ifeq_instruction(instruction.param_integer);
    } else if(strcmp(instruction.opcode, "IFLT") == 0) {
        execute_iflt_instruction(instruction.param_integer);
    } else if(strcmp(instruction.opcode, "HALT") == 0) {
        execute_halt_instruction();
    } else {
        printf("Invalid instruction: %s! Check your syntax.\n", instruction.opcode);
    }
}
