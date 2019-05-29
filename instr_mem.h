typedef enum { string_param, int_param } PARAM_TYPE;

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
    char *instr_copied = malloc(128*sizeof(char));
    strcpy(instr_copied, instruction);

    //Split instruction into tokens, which determine different parts of instruction.
    const char ch_space = ' ';
    const char ch_end = ';';
    const char *end_of_opcode = strchr(instr_copied, ch_space);
    if(end_of_opcode == NULL){
        end_of_opcode = strchr(instr_copied, ch_end);
    }
    const char *end_of_parameter = strrchr(instr_copied, ch_end);
    const int sizeof_opcode = end_of_opcode - instr_copied;
    const int sizeof_parameter = end_of_parameter - end_of_opcode;

    char *opcode = calloc(32, sizeof(char));
    if(sizeof_opcode >= 0 && sizeof_opcode < 256 && end_of_opcode != NULL){
        strncpy(opcode, instr_copied, sizeof_opcode);
    }

    char *parameter = calloc(128, sizeof(char));
    if(sizeof_parameter >= 0 && sizeof_parameter < 256 && end_of_parameter != NULL){
        strncpy(parameter, end_of_opcode, sizeof_parameter);
    }
    free(instr_copied);

    no_of_instructions++;

    vm_instruction_memory[address].opcode = strdup(opcode);
    free(opcode);

    int num_parameter = atoi(parameter);

    if(num_parameter != 0){
        vm_instruction_memory[address].param_type = int_param;
        vm_instruction_memory[address].param_integer = num_parameter;
    } else {
        vm_instruction_memory[address].param_type = string_param;
        vm_instruction_memory[address].param_string = strdup(parameter);
    }
    free(parameter);
}

// Fetch instruction at "address"
struct InstrMemElement fetch_instruction(int address) {
    struct InstrMemElement fetchedInstruction;
    fetchedInstruction.opcode = strdup(vm_instruction_memory[address].opcode);
    fetchedInstruction.param_type = vm_instruction_memory[address].param_type;
    if(fetchedInstruction.param_type == int_param){
        fetchedInstruction.param_integer = vm_instruction_memory[address].param_integer;
    }
    if(fetchedInstruction.param_type == string_param){
        fetchedInstruction.param_string = strdup(vm_instruction_memory[address].param_string);
    }
    return fetchedInstruction;
}

// Get the number of instructions in instruction memory
int get_no_of_instructions() {
    return no_of_instructions;
}
