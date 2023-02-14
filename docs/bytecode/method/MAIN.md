### method
its structure in byte code
```c++
Method{
  u2 name;
  u1 modifier;
  u2 lv_count;
  Varible vars[lv_count];
  u2 op_size;
  u1 op[op_size];
}
```
##### name
it is an index in constant pool of a `METHOD_CONSTANT`
##### modifire
the same as `Field`'s `modifier`
##### lv_count
local vars' number
##### vars
local varibles in the method
##### op_size
size of the operator instructions, NOT COUNT BUT SIZE
##### op
operand codes

| opcode | symbol |
| :----: | ------ |
| 0x00   | nop    |