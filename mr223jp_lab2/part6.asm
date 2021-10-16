


.include "m2560def.inc" 
 LDI R18,0 ;veriable for 'a'
 LDI R19,0 ;veriable for 'b'
 LDI R20,0 ;veriable for 'c'
 LDI R21,0 ;veriable for 'd'
 ADD R18,R19; ;(a+b)
 SUB R18,R20; ;(a+b) - c
 ADD R18,R21; ;(((a+b) - c) + d)
 LDI R22,0b00000001
 ADD R18,R22 ;(((a+b) - c) + d) + 1