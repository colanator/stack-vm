void execute_add_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand + second_operand);
}

void execute_sub_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand - second_operand);
}

void execute_mul_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand * second_operand);
}

void execute_div_instruction(){
    int first_operand = pop();
    int second_operand = pop();
    push(first_operand / second_operand);
}

void execute_push_instruction(char *elem_to_be_pushed){
    int elem_to_be_pushed_casted = atoi(elem_to_be_pushed);
    push(elem_to_be_pushed_casted);
}

void execute_pop_instruction(){
    printf("%i\n", pop());
}

void execute_peek_instruction(){
    printf("%i\n", peek());
}

void execute_ifeq_instruction(char *condition){
    int condition_casted = atoi(condition);
    if(condition_casted == peek()){
        vm_instruction_memory.instruction_pointer++;
    }
}

void execute_jmp_instruction(char *jmp_target){
    int jmp_target_casted = atoi(jmp_target);
    vm_instruction_memory.instruction_pointer = jmp_target_casted;
}

void execute_instruction(char instruction[]) {

    //Split instruction into tokens, which determine different parts of instruction.
    char *instr_tokens[6];
    char *pch;
    int counter = 0;
    pch = strtok(instruction, " ;");
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
    } else if(strcmp(instr_tokens[0], "POP") == 0) {
        execute_pop_instruction();
    } else if(strcmp(instr_tokens[0], "PEEK") == 0) {
        execute_peek_instruction();
    } else if(strcmp(instr_tokens[0], "IFEQ") == 0) {
        execute_ifeq_instruction(instr_tokens[1]);
    } else if(strcmp(instr_tokens[0], "JMP") == 0) {
        execute_jmp_instruction(instr_tokens[1]);
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
