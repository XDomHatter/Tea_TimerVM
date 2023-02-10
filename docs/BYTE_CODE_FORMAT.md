# Tea byte code file format

An intact Tea byte code file looks like this:
```c++
TeaCodeFile{
    u4 magic_num;  // AE 58 44 48
    u2 endian_num; // ' 12 34 ' written in file in big endian.
                 // when host is little indian it's read to ' 34 12 '
                 // it lets vm to decide endian in program
    u1 file_inf;   // 0b00000001 means FAST_METHOD mode that vm doesn't check result type
                 // 0b00000010 means NO_RES_TYPE mode that Method.result_type doesn't exists
                 // 0b00000100 means JIT_ON      mode
                 // 0b00001000 means AOT_ON      mode
                
                      
    u4 file_size;  // the code file's size ( in big endian )
    u2 constant_count; // constant's number in constant pool
    u2 cp_size;        // constant pool's size
    Constant cp[constant_count];
    u2 class_count;    // class in the code file's number
    Class classes[class_count];
};
```
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
- ~~\`S` means utf-8~~ (unsupport cuz utf-8 isnt built-in type)
- and Class use `L` + `class name` + `;` like:  
`Lstd_Number;` means `std.Number`  
( `_` means a dot `.` and `__` means a real underline `_` )
- `[` after a type means array like `I[` means `int[]`
### Class
its structure looks like this:
```
Class{
  u2 name; 
  u2 parent;
  u1 modifier;    
  u2 field_count;
  Field fields[field_count];
  u2 methods_count;
  Method methods[method_count];
};
```
##### name  
index of`CLASS_CONSTANT` in constant pool
##### parent  
index of `CLASS_CONSTANT` in constant pool of class' parent class (it usually is `STD_Object` if user didin't appoint)
##### modifier:   
`00000001` means CLASSFLAG_PUBLIC  
`00000010` means CLASSFLAG_PRIVATE  
`00000100` means 'user class' which is user wrote it but not precompiler  
`00001000` means 'file class' which is precompiler creates it but not user  

##### `field` and `varible`
`field` is the same structure of `Varible` but extra a byte `modifier`
```c++
Field : Varible{
    u2 type_and_name;
    u1 value[?];
    u1 modifier; 
}; 

Varible{
  u2 type_and_name; 
  u1 value[?]; 
};
```
`type_and_name` is an index of `TYPE_AND_NAME_CONSTANT` in constant pool
the size of `value`  
- when `I` 4 byte
- when `D` 8 byte
- when `C` 2 byte
- when `F` 4+4=8 byte
- when `S`, it's a index of a `UTF8_CONSTANT` in 2 bytes
- when it is an array(`x[`) or an object(`Lxxxx;`), it will be a index in 4 bytes of an Object in heap
##### modifire
`00000001` means public  
`00000010` means private  
`00000100` means protect  
`00001000` means static  
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
byte codes