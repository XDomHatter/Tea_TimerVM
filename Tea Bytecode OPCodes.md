# Tea Bytecode OPCodes

## Constant -> 25

iconst_m1 iconst_0 iconst_1 iconst_2 iconst_3 iconst_4 iconst_5
lconst_0 lconst_1 lconst_2 lconst_3 lconst_4 lconst_5
dconst_1 dconst_2 dconst_3 dconst_4
fconst_1 fconst_2 fconst_3 fconst_4
push1 push2 push4 push8

## Load -> 12

load_0 load_1 load_2 load_3
load2_0 load2_1 load2_2 load2_3
load load_w load2 load2_w

## Store -> 12

store_0 store_1 store_2 store_3
store2_0 store2_1 store2_2 store2_3
store store_w store2 store2_w

## bitwise -> 16

and and2
or or2
xor xor2
not not2
shl shl_local
shr shr_local
shl2 shl2_local
shr2 shr2_local

## Math -> 64

iadd ladd dadd fadd uiadd uladd
iadd_local ladd_local dadd_local fadd_local uiadd_local uladd_local

isub lsub dsub fsub uisub ulsub
isub_local lsub_local dsub_local fsub_local uisub_local ulsub_local

imul lmul dmul fmul uimul ulmul
imul_local lmul_local dmul_local fmul_local uimul_local ulmul_local

idiv ldiv ddiv fdiv uidiv uldiv
idiv_local ldiv_local ddiv_local fdiv_local uidiv_local uldiv_local

inc_1 inc_2 inc_3
inc2_1 inc2_2 inc2_3

dec_1 dec_2 dec_3
dec2_1 dec2_2 dec2_3

inc inc2 dec dec2

## OOP -> 10

call ret

new newarray

load_field store_field

push_func_obj call_func_obj

load_element store_element

## Logic -> 72

ieq leq deq feq uieq uleq
igt lgt dgt fgt uigt ulgt
ilt llt dlt flt uilt ullt

ineq lneq dneq fneq uineq ulneq
ige lge dge fge uige ulge
ile lle dle fle uile ulle

ieq_local leq_local deq_local feq_local uieq_local uleq_local
igt_local lgt_local dgt_local fgt_local uigt_local ulgt_local
ilt_local llt_local dlt_local flt_local uilt_local ullt_local

ineq_local lneq_local dneq_local fneq_local uineq_local ulneq_local
ige_local lge_local dge_local fge_local uige_local ulge_local
ile_local lle_local dle_local fle_local uile_local ulle_local

## Branch -> 4
iftrue ifflase
jmp jmp_w

## Stack -> 7

dup dup2
pop pop2
exch exch2
clear

## Total -> 222
