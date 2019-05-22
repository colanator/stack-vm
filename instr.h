// ADD - instruction
// Parameters are added together, result pushed to stack
void execute_add_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand + second_operand);
}

// SUB - instruction
// Second parameter is subtracted from the first, result pushed to stack
void execute_sub_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand - second_operand);
}

// MUL - instruction
// Parameters are multiplied together, result pushed to stack
void execute_mul_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand * second_operand);
}

// DIV - instruction
// First parameter is divided by the first, result pushed to stack
void execute_div_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand / second_operand);
}

// PUSH - instruction
// Parameter is pushed to stack
void execute_push_instruction(char *elem_to_be_pushed){
    int elem_to_be_pushed_casted = atoi(elem_to_be_pushed);
    push(elem_to_be_pushed_casted);
}

// DROP - instruction
// Top element of stack is popped (removed)
void execute_drop_instruction(){
    drop();
}

// PRINT - instruction
// Top element of stack is printed out without popping
void execute_print_instruction(){
    printf("%i\n", peek());
}

// JMP - instruction
// Instruction pointer it set to parameter value
void execute_jmp_instruction(char *jmp_target){
    int jmp_target_casted = atoi(jmp_target);
    vm_instruction_memory.instruction_pointer = jmp_target_casted - 1;
}

// IFEQ - instruction
// If condition matches top element of stack, the next insruction is executed, otherwise instruction pointer is incremented to skip it
void execute_ifeq_instruction(char *condition){
    int condition_casted = atoi(condition);
    if(condition_casted != peek()){
        vm_instruction_memory.instruction_pointer++;
    }
}

// IFLT - instruction
// If condition lesser than element of stack, the next insruction is executed, otherwise instruction pointer is incremented to skip it
void execute_iflt_instruction(char *condition){
    int condition_casted = atoi(condition);
    if(condition_casted < peek()){
        vm_instruction_memory.instruction_pointer++;
    }
}

// IFGT - instruction
// If condition greater than element of stack, the next insruction is executed, otherwise instruction pointer is incremented to skip it
void execute_ifgt_instruction(char *condition){
    int condition_casted = atoi(condition);
    if(condition_casted > peek()){
        vm_instruction_memory.instruction_pointer++;
    }
}

// HALT - instruction
// Instruction pointer it set to 1000, which halts program execution
void execute_halt_instruction(){
    vm_instruction_memory.instruction_pointer = 1000;
}

// This function is given a single "instruction" to be executed
// The function is split into the opcode and the parameters
void execute_instruction(char instruction[]) {

    //Copy instruction string to temporary variable to avoid side effects.
    char instr_copied[32];
    strcpy(instr_copied, instruction);

    //Split instruction into tokens, which determine different parts of instruction.
    char *instr_tokens[6];
    char *pch;
    int counter = 0;
    pch = strtok(instr_copied, " ;");
    while(pch != NULL) {
        instr_tokens[counter] = pch;
        counter++;
        pch = strtok(NULL, " ;");
    }

    //Read first token of instruction to determine the operation. Call the relevant instruction command.
    if(strcmp(instr_tokens[0], "ADD") == 0) {
        execute_add_instruction();
    } else if(strcmp(instr_tokens[0], "SUB") == 0) {
        execute_sub_instruction();
    } else if(strcmp(instr_tokens[0], "MUL") == 0) {
        execute_mul_instruction();
    } else if(strcmp(instr_tokens[0], "DIV") == 0) {
        execute_div_instruction();
    } else if(strcmp(instr_tokens[0], "PUSH") == 0) {
        execute_push_instruction(instr_tokens[1]);
    } else if(strcmp(instr_tokens[0], "DROP") == 0) {
        execute_drop_instruction();
    } else if(strcmp(instr_tokens[0], "PRINT") == 0) {
        execute_print_instruction();
    } else if(strcmp(instr_tokens[0], "JMP") == 0) {
        execute_jmp_instruction(instr_tokens[1]);
    } else if(strcmp(instr_tokens[0], "IFEQ") == 0) {
        execute_ifeq_instruction(instr_tokens[1]);
    } else if(strcmp(instr_tokens[0], "IFGT") == 0) {
        execute_ifeq_instruction(instr_tokens[1]);
    } else if(strcmp(instr_tokens[0], "IFLT") == 0) {
        execute_iflt_instruction(instr_tokens[1]);
    } else if(strcmp(instr_tokens[0], "HALT") == 0) {
        execute_halt_instruction();
    } else {
        printf("Invalid instruction! Check your syntax.\n");
    }
}

//returns true if instruction, false if label
//int interpret_instruction(char instruction[]){
//    char inspected_instruction[32];
//    strcpy(inspected_instruction, instruction);
//
//    char test[6] = "label";
//    
//    //printf("inspected_instruction: %s :end", inspected_instruction);
//    //printf("test: %s :end", test);
//
//    if(strstr(inspected_instruction, test) != NULL) {
//        //printf("Invalid instruction! Check your syntax.%s", instruction);
//        return 1;
//    }
//
//    return 0;
//}
