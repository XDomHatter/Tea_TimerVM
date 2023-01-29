```c++
TeaCodeFile{
  u4 magic_num; // AE 58 44 48
  u2 endian_num; // ' 12 34 ' written in file in big endian.
                 // when host is little indian it's read to ' 34 12 '
                 // it lets vm to decide endian in program
  u4 file_size;  // the code file's size ( in big endian )
  u2 constant_count; // constant's number in constant pool
  u2 cp_size;        // constant pool's size
  Constant cp[constant_count];
  u2 class_count;    // class in the code file's number
  Class classes[class_count];
};

Constant{
  u1 type;
  /*
   * 00000011 = number, store big number which big than Integer
   * 00001100 = float number, like 0.123412839102379821369816......
   * 00110000 = utf-8, store UTF-8 string
   * 11000000 = ?
   */
  u2 size;
  u1 constant[size];
};

Class{
  u2 name; // string index in constant pool
  u2 field_count;
  u2 field_size;
  Field fields[field_count];
  u2 method_count;
  u2 method_size;  
  Method methods[method_count];
};

Field{
  u2 type_and_name; // string index in constant pool
                    // type is "I" means integer
                    //         "C" means character
                    //         "F" means float number
                    //         "S" means utf-8
                    // and Class use "L" + class' name like:
                    //  "Lstd_Number" means std.Number
                    // ( _ -> .  __ -> _ )
  u1 value[?]; // when "I" 4 byte
               // when "C" 2 byte
               // when "F" 4+2=6 byte
               // when "S", the first byte
};
```