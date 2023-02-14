### Constant
 The Constant looks like
 ```c++
 Constant{
     u1 type;
     CONSTANT_STRUCT value;
 };
 ```
+ when the byte `type` is 0, the `CONSTANT_STRUCT` is `UTF8_CONSTANT` which looks like this:
 ```c++
 UTF8_CONSTANT{
     u2 size; // count of character * 2 ( one char use two byte )
     u1 value[size];
 };
 ```
 + when it is 1, the `CONSTANT_STRUCT` is `METHOD_CONSTANT`
 ```c++
 METHOD_CONSTANT{
     u2 result_type_index;
     u2 name_index;
     u2 param_type_index;
 };
 ```
 the three fields are all index of constant in constant_pool
 
 + when it is 2, the `CONSTANT_STRUCT` is `CLASS_CONSTANT`
 ```c++
 CLASS_CONSTANT{
     u2 name_idx;
 };
 ```
 `name_idx` is an index of UTF8_CONSTANT for class name
 + when it is 3, the `CONSTANT_STRUCT` is `MERGE_UTF8_CONSTANT`
 ```c++
 MERGE_UTF8_CONSTANT{
     u2 member_count;
     u2 indexes[member_count];
 };
 ```
 this constant type is for merge two or more utf-8 constant
 + when it is 4, the `CONSTANT_STRUCT` is `TYPE_AND_NAME_CONSTANT`
 ```c++
 TYPE_AND_NAME_CONSTANT{
     u2 name;
     u2 type;
 };
 ``` 
 `name` and `type` is an index of an `UTF8_CONSTANT` in constant pool  
 value of `type` is like this:
 - type is `I` means integer
 - `D` means long number
 - `C` means character
 - `F` means float number
 - ~~\`S` means utf-8~~ (unsupport cuz utf-8 isn't built-in type)
 - and Class use `L` + `class name` + `;` like:  
 `Lstd_Number;` means `std.Number`  
 ( `_` means a dot `.` and `__` means a real underline `_` )
 - `[` after a type means array like `I[` means `int[]`