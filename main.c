#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "instr_mem.h"
#include "instr.h"

int main (int argc, char *argv[]) {

   int instruction_pointer = 0;

   // Initialize stack with input parameters from command line
   if(argc > 2){
      for(int i = 2; i <= argc-1; i++){
         push(atoi(argv[i]));
      }
   }

   // Read source code file and initialize the instruction memory
   char *filename = argv[1];
   FILE *file = fopen(filename, "r");
   int counter = 1;

   if (file != NULL) {
      char instruction[32];

      while(fgets(instruction, sizeof(instruction), file) != NULL) {
         add_instruction(counter, instruction);
         counter++;
      }

      fclose(file);
   }
   else {
      perror(filename);
   }

   // Execute instructions from the instruction memory, incrementing the instruction pointer
   // If instruction pointer is 999 or more the program is considered executed
   while (vm_instruction_memory.instruction_pointer <= 999) {
      execute_instruction(fetch_instruction(vm_instruction_memory.instruction_pointer));
      vm_instruction_memory.instruction_pointer++;
   }

   return 0;
}
