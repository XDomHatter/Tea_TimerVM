# ladd

|bytecode | asm symbol |
| ------ | ------- |
| 0x01    |	iadd       |
it's an operator to realize add operation in user code

### compiler performance

compiler should realize `+` with two long number to ladd

### vm performance

add two long number( 8 byte each ) in the stack and push the result into stack

#### example
| stack |
| :---:|
| 0x00000001 |
| 0x20000000 |
| 0x00000003 |
| 0x40000000 |
 
ladd's act: 
+ get 0x01, 0x02, and turn it into a long integer:  
`0x00000001>>64 + 0x20000000 => 0x0000000120000000`  
`0x00000003>>64 + 0x20000000 => 0x0000000340000000`
+ make two long num add
`0x0000000120000000 + 0x0000000340000000 = 0x0000000460000000`
+ strict it into 2 integer (4 byte each)
`0x0000000460000000 => 0x00000004>>64 + 0x60000000`
+ push it into stack:
| stack |
| :---: |
| 0x00000004 |
| 0x60000000 |
