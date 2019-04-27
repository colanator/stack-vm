struct Instruction_memory {
    char instruction_memory[256][32];
    int no_of_instructions;
};
typedef struct Instruction_memory INSTRUCTION_MEMORY;
INSTRUCTION_MEMORY vm_instruction_memory = {.instruction_memory = {{""}}, .no_of_instructions = 0};

void add_instruction(int address, char instruction[]) {
    strcpy(vm_instruction_memory.instruction_memory[address], instruction);
    vm_instruction_memory.no_of_instructions++;
}

char* fetch_instruction(int address) {
    return &vm_instruction_memory.instruction_memory[address];
}

int no_of_instructions() {
    return vm_instruction_memory.no_of_instructions;
}