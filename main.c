#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "instr_mem.h"
#include "instr.h"

int main (int argc, char *argv[]) {
   init_stack();
   init_instr_mem();

   // Initialize stack with input parameters from command line
   int elem_to_push = 0;
   char argv_copied[64];

   if(argc > 2){
      for(int i = 2; i <= argc-1; i++){
         elem_to_push = atoi(argv[i]);
         if(elem_to_push > 0){
            push_int(elem_to_push);
         } else {
            strcpy(argv_copied, argv[i]);
            push_string(argv_copied);
         }
      }
   }

   // If no address for code file was given, stop execution
   if(argv[1] == NULL){
      printf("No instructions found.");
      return 0;
   }

   // Read source code file and initialize the instruction memory
   char *filename = argv[1];
   FILE *file = fopen(filename, "r");
   int counter = 1;

   if (file != NULL) {
      char instruction[128];

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
   while (instruction_pointer <= 999) {
      struct InstrMemElement instruction = fetch_instruction(instruction_pointer);
      execute_instruction(instruction);
      instruction_pointer++;
   }

   return 0;
}
