# Stack VM

Aapo Torkkeli 505868

Simple stack-based process virtual machine.

Run from the command-line, with the name of the source code file as the first parameter.
After that, optional parameters may be given. These parameters are pushed onto the stack before the source code is executed.

Instructions are composed from the OpCode and parameters.

| OpCode     | Parameters    | Definition |
| ---------- | ------------- | ---------- |
| ADD | - | Add the two topmost elements of the stack together. Result on top of stack. |
| SUB | - | Subtract the topmost element of the stack from the second topmost. Result on top of stack. |
| MUL | - | Multiply the two topmost elements of the stack together. Result on top of stack. |
| DIV | - | Divide the topmost element of the stack by the second topmost. Result on top of stack. |
| PUSH | Integer | Push the parameter onto the stack. |
| POP | - | Pop the topmost element of stack. Print its value. |
| PEEK | - | Print the topmost element of stack, don't pop. |
| JMP | Integer | Jump to instruction at parameter location. |
| IFEQ | Integer | If the value is equal to top of stack, execute next instruction. Otherwise skip instruction. |
| IFGT | Integer | If the value is greater than top of stack, execute next instruction. Otherwise skip instruction. |
| IFLT | Integer | If the value is lesser than top of stack, execute next instruction. Otherwise skip instruction. |
| HALT | - | End program. Stop execution. |

Example program:
```
PUSH 1;
PUSH 2;
ADD;
POP;
```
The above program pushes the numbers 1 and 2 onto the stack. Then it pops them both from the stack, and adds them together. The result is pushed back onto the stack. The result is then popped and printed out to the standard output of the runtime environment.