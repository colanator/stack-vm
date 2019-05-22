#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instr_mem.h"

int main (int argc, char *argv[]) {
    init_instr_mem();

    add_instruction(1, "ADD 1");
    add_instruction(2, "SUB 2");
    add_instruction(3, "DIV 3");
    add_instruction(4, "PRINT testailustr");
    add_instruction(4, "PRINT asdgvds");
    struct InstrMemElement instr1 = fetch_instruction(1);
    struct InstrMemElement instr2 = fetch_instruction(2);
    struct InstrMemElement instr3 = fetch_instruction(3);
    struct InstrMemElement instr4 = fetch_instruction(4);

    printf("Instruction pointer %i\n", instruction_pointer);
    printf("No of instructions %i\n", get_no_of_instructions());

    printf("%s\n", instr1.opcode);
    printf("%i\n", instr1.param_type);
    printf("%i\n", instr1.param_integer);
    printf("%s\n", instr2.opcode);
    printf("%i\n", instr2.param_type);
    printf("%i\n", instr2.param_integer);
    printf("%s\n", instr3.opcode);
    printf("%i\n", instr3.param_type);
    printf("%i\n", instr3.param_integer);
    printf("%s\n", instr4.opcode);
    printf("%i\n", instr4.param_type);
    printf("%s\n", instr4.param_string);

    return 0;
}
