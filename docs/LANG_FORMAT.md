user code format: 't.t'
```
import lib_name1 // import a lib file name 'lib_name.tl' or 'lib_name.ta' or 'lib_name.tc'
__import__("lib_name2.tl") // import a lib file name 'lib_name'
//comment
/*
 * comment style like C/C++ lang.
 */


var varible   // any type init and can change at any time
varible = "HI"; varible = 12334567; // ';' is optional

// inbuilt types
bool v0  // true or false 
char v1  // 2bytes -> utf-8 char
short v2 // 2bytes
int v3   // 4bytes -> integer
long v4  // 8bytes, no 'long long' type

v4 = 4234567890

v4 ++
v4 += 1 //now v4 is 4234567892

v2 = 0x1234 //HEX
v2 = 0b1000100011110000

def func_with_any_result_type(){
  do_sth()
}

def func_return_int( a, b:int ) -> int {
  return 1234;
}

def some_func( a = 100/* default value */){}

class OneClass{ //PascalFormat
  var field //any type
  int f1
  def _init(){ //initializer
    this.field = 0x1234; // short type
  }
  def method(){
    this.f1 = 100
  }
  def method(a, b);
}

def OneClass::method(a, b){
  do_sth()
}

class TwoClass extends OneClass{
  // nothing
}


OneClass obj = new OneClass();
OneClass obj2 = new TwoClass();
obj.method()
obj2.method()
OneClass[] arr = {} // multi-size array
arr[0] = obj;
arr[1] = obj2;

if v1 == v2{}
elif{}
else{}

for(int i=0;i<=10;i++){
  for(int j=0;j<=10;j++) -> lable{
    for(int z=0;j<=10;j++){
      if(z=1){
        break lable;
      }elif(z=2){
        continue lable;
      } 
    }
  }
}
foreach(OneClass o in arr){}
while(v1 == 123456){}
while(true){}


```
after precompile: 't.to'
```
__import__("lib_name1.tl");
__import__("lib_name2.tl");

class $T{
  class OneClass{
    var field;
    int f1;
    def _init();
    def method();
    def method(a, b);
  }
  class TwoClass extends $T::OneClass{}

  // Globle varibles
  var varible;
  bool v0;  
  char v1; 
  short v2; 
  int v3;   
  long v4; 
  utf_8 v5;

  OneClass obj;
  TwoClass obj2;
  OneClass[] arr;
  def $main(argc, argv);

  def func_with_any_result_type();

  def func_return_int( a, b:int ) -> int;
  def some_func( a = 100 );
}

def $T::$main(argc, argv){
  this.varible = "HI"; 
  this.varible = 12334567; 
  this.v4 = 4234567890;
  this.v4 ++;
  this.v4 += 1; 
  this.v2 = 0x1234; 
  this.v2 = 0b1000100011110000;
  this.v5 = "String Test";
  this.obj = new $T_Globle::OneClass();
  this.obj2 = new $T_Globle::TwoClass();
  this.obj.method();
  this.obj2.method();
  this.arr = {};
  this.arr[0] = this.obj;
  this.arr[1] = this.obj2;
  if(this.v1 == this.v2){}
  elif{}
  else{}
  for(int i=0;i<=10;i++){
    for(int j=0;j<=10;j++) -> lable{
      for(int z=0;j<=10;j++){
        if(z=1){
          break lable;
        }elif(z=2){
          continue lable;
        } 
      }
    }
  }
  foreach($T_Globle::OneClass o in this.arr){}
  while(this.v1 == 123456){}
  while(true){}
}
def $T::func_with_any_result_type(){
  do_sth();
}
def $T::func_return_int( a, b:int ) -> int {
  return 1234;
}
def $T::some_func( a = 100 ){}
def $T::OneClass::_init(){
  this.field = 0x1234;
}
def $T::method(){
  this.f1 = 100
}
def $T::OneClass::method(a, b){
  do_sth()
}
```

tip: if there's a class which name is as same as file name
      than precompiler will let it be the Globle class and
      other function/class is disabled(show compiler errow)