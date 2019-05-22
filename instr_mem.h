typedef enum {type_string, type_int} PARAM_TYPE;

struct InstrMemElement {
    char    *opcode;
    PARAM_TYPE param_type;
    union {
        char    *param_string;
        int     param_integer;
    };
};

int no_of_instructions;
int instruction_pointer;
struct InstrMemElement *vm_instruction_memory;

void init_instr_mem() {
    no_of_instructions = 0;
    instruction_pointer = 1;
    vm_instruction_memory = malloc(sizeof(struct InstrMemElement) * 1024);
}

// Parse "instruction" and add it to instruction memory to "address"
void add_instruction(int address, char instruction[]) {
    //Copy instruction string to temporary variable to avoid side effects.
    char instr_copied[128];
    strcpy(instr_copied, instruction);

    //Split instruction into tokens, which determine different parts of instruction.
    char *instr_tokens[24];
    char *pch;
    int counter = 0;
    pch = strtok(instr_copied, " ;");
    while(pch != NULL) {
        instr_tokens[counter] = pch;
        counter++;
        pch = strtok(NULL, " ;");
    }
    vm_instruction_memory[address].opcode = strdup(instr_tokens[0]);

    int num_parameter = atoi(instr_tokens[1]);

    if(num_parameter != 0){
        vm_instruction_memory[address].param_type = type_int;
        vm_instruction_memory[address].param_integer = num_parameter;
    } else {
        vm_instruction_memory[address].param_type = type_string;
        vm_instruction_memory[address].param_string = instr_tokens[1];
    }

    no_of_instructions++;
}

// Fetch instruction at "address"
struct InstrMemElement fetch_instruction(int address) {
    struct InstrMemElement fetchedInstruction;
    fetchedInstruction.opcode = strdup(vm_instruction_memory[address].opcode);
    fetchedInstruction.param_type = vm_instruction_memory[address].param_type;
    if(fetchedInstruction.param_type == type_int){
        fetchedInstruction.param_integer = vm_instruction_memory[address].param_integer;
    }
    if(fetchedInstruction.param_type == type_string){
        fetchedInstruction.param_string = strdup(vm_instruction_memory[address].param_string);
    }
    return fetchedInstruction;
}

// Get the number of instructions in instruction memory
int no_of_instructions() {
    return vm_instruction_memory.no_of_instructions;
}
