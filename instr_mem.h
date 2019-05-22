struct Instruction_memory {
    char instruction_memory[256][32];
    int no_of_instructions;
    int instruction_pointer;
};
typedef struct Instruction_memory INSTRUCTION_MEMORY;
INSTRUCTION_MEMORY vm_instruction_memory = {.instruction_memory = {{""}}, .no_of_instructions = 0, .instruction_pointer = 1};

// Add "instruction" to intsruction memory to "address"
void add_instruction(int address, char instruction[]) {
    strcpy(vm_instruction_memory.instruction_memory[address], instruction);
    vm_instruction_memory.no_of_instructions++;
}

// Fetch pointer to instruction at "address"
char* fetch_instruction(int address) {
    char* str = strdup(vm_instruction_memory.instruction_memory[address]);
    return str;
}

// Get the number of instructions in instruction memory
int no_of_instructions() {
    return vm_instruction_memory.no_of_instructions;
}

//int add_label(char instruction[], int instruction_pointer) {
//    return vm_instruction_memory.no_of_instructions;
//}
