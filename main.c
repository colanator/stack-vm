#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "instr.h"

int main (int argc, char *argv[]) {

   char *filename = argv[1];
   FILE *file = fopen(filename, "r");

   if (file != NULL) {
      char instruction[32];

      while(fgets(instruction, sizeof(instruction), file) != NULL) {
         execute_instruction(instruction);
      }

      fclose(file);
   }
   else {
      perror(filename);
   }
   return 0;
}
