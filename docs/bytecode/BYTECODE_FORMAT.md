 # Tea byte code file format
 
 An intact Tea byte code file looks like this:
 ```c++
 TeaCodeFile{
     u4 magic_num;  // AE 58 44 48
     u1 file_inf;   // 0b00000001 means FAST_METHOD mode that vm doesn't check result type
                    // 0b00000010 means NO_RES_TYPE mode that Method.result_type doesn't exists
                    // 0b00000100 means JIT_ON      mode
                    // 0b00001000 means AOT_ON      mode
                       
     u4 file_size;  // the code file's size ( in big endian )
     u2 constant_count; // constant's number in constant pool
     u2 cp_size;        // constant pool's size
     Constant cp[constant_count];
     u2 func_count;
     Function funcs[func_count];
     u2 class_count;    // class in the code file's number
     Class classes[class_count];
 };
 ```
 
 