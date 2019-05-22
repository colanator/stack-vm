#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "instr_mem.h"

int main (int argc, char *argv[]) {
    init_instr_mem();

    add_instruction(1, "ADD 1")
    add_instruction(2, "ADD 2")
    add_instruction(3, "ADD 3")
    InstrMemElement instr1 = fetch_instruction(1);
    InstrMemElement instr2 = fetch_instruction(2);
    InstrMemElement instr3 = fetch_instruction(3);

    printf("Instruction pointer %s\n", no_of_instructions);
    printf("no_of_instructions \n", instruction_pointer);

    printf("%i\n", instr1.opcode);
    printf("%i\n", instr2.opcode);
    printf("%i\n", instr3.opcode);

    return 0;
}
