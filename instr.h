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
    } else {
        printf("Invalid instruction! Check your syntax.\n");
    }
}
