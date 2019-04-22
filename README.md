# Stack VM

Aapo Torkkeli 505868

Simple stack-based process virtual machine.

Run from the command-line, with the name of the source code file as the first parameter.
After that, optional parameters may be given. These parameters are pushed onto the stack before the source code is executed.

Instructions are composed from the OpCode and parameters.

| OpCode     | Parameters    | Definition |
| ---------- | ------------- | ---------- |
| ADD | - | Add the two topmost elements of the stack together. Result on top of stack. |