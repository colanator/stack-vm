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
| ADD | - | Multiply the two topmost elements of the stack together. Result on top of stack. |
| DIV | - | Divide the topmost element of the stack by the second topmost. Result on top of stack. |
| PUSH | Integer | Push the parameter onto the stack. |
| POP | - | Pop the topmost element of stack. Print its value. |

Example program:
```
PUSH 1;
PUSH 2;
ADD;
POP;
```
The above program pushes the numbers 1 and 2 onto the stack. Then it pops them both from the stack, and adds them together. The result is pushed back onto the stack. The result is then popped and printed out to the standard output of the runtime environment.