# Stack VM

Aapo Torkkeli 505868

Simple stack-based process virtual machine.

Run from the command-line, with the name of the source code file as the first parameter.
After that, optional parameters may be given. These parameters are pushed onto the stack before the source code is executed.

Instructions are composed from the OpCode and parameters.
Each instruction must be on its own line, begin with a valid OpCode and end with a ";"-sign. The OpCode and parameter must be separated with a space.

| OpCode     | Parameters    | Definition |
| ---------- | ------------- | ---------- |
| PUSH | Integer or String | Push the parameter onto the stack. |
| DROP | - | Remove the topmost element of stack. |
| DUP | - | Duplicate topmost element of stack. |
| ROT | - | Rotate the two topmost elements of stack. |
| PEEK | - | Print out value of topmost element of stack, without removing it from stack. |
| ADD | - | Add the two topmost elements of the stack together. Result on top of stack. |
| SUB | - | Subtract the topmost element of the stack from the second topmost. Result on top of stack. |
| MUL | - | Multiply the two topmost elements of the stack together. Result on top of stack. |
| DIV | - | Divide the topmost element of the stack by the second topmost. Result on top of stack. |
| JMP | Integer | Jump to instruction at parameter location. |
| IFEQ | Integer | If the value is equal to top of stack, execute next instruction. Otherwise skip instruction. |
| IFGT | Integer | If the value is greater than top of stack, execute next instruction. Otherwise skip instruction. |
| IFLT | Integer | If the value is lesser than top of stack, execute next instruction. Otherwise skip instruction. |
| PRINT | String | Print out parameter string. |
| HALT | - | End program. Stop execution. |

Example program:
```
PUSH 1;
PUSH 2;
ADD;
PEEK;
```
The above program pushes the numbers 1 and 2 onto the stack. Then it pops them both from the stack, and adds them together. The result is pushed back onto the stack. The result is then printed out to the standard output of the runtime environment.