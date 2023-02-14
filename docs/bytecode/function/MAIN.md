### Function
its structure in byte code:
```c++
Function{
  u2 name;
  u2 lv_count;
  Varible vars[lv_count];
  u2 op_size;
  u1 op[op_size];
}
```
##### name
it is an index in constant pool of a `METHOD_FUNCTION_CONSTANT`
##### lv_count
local vars' number
##### vars
local varibles in the method
##### op_size
size of the operator instructions, NOT COUNT BUT SIZE
##### op
operand codes