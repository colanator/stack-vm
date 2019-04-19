#include <stdio.h>

void execute_instruction( char instruction[] ){
   printf("Executing instruction: s%c\n", instruction );
}

int main (int argc, char *argv[]) {
   
   char *filename = argv[1];
   FILE *file = fopen(filename, "r");

   if (file != NULL) {
      char line[128];
      while(fgets(line, sizeof line, file) != NULL) {
         fputs(line, stdout);
         execute_instruction(line);
      }
      fclose(file);
   }
   else {
      perror(filename);
   }
   return 0;
}
