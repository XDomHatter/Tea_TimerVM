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