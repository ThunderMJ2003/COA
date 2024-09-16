section .data
    num1 dw 12          ;first number
    num2 dw 18          ;second number
    fin dw 0            ;To store the LCM

section .bss
    temp resw 1         ;temporary variable to store GCD

section .text
    global _start

_start:
    MOV AX, [num1]      ;loading num1 into AX
    MOV BX, [num2]      ;loading num2 into BX

gcd_loop:               ;using Euclidean algorithm to find GCD
    CMP BX, 0           ;comparing BX with 0
    JE gcd_found        ;if BX is 0, go to gcd_found
    XOR DX, DX          ;clearing DX for division
    DIV BX              ;AX / BX with quotient in AX and remainder in DX
    MOV AX, BX          ;moving BX into AX
    MOV BX, DX          ;moving remainder to BX
    JMP gcd_loop        ;repeating until remainder is 0

gcd_found:
    MOV [temp], AX      ;storing GCD in memory at 'temp'
    MOV AX, [num1]      ;reloading num1 into AX
    XOR DX, DX          ;clearing DX for multiplication
    MUL word [num2]     ;AX = num1 * num2 (fin goes into DX:AX)
    MOV BX, [temp]      ;loading GCD from memory 'temp' into BX
    DIV BX              ;dividing (DX:AX) by GCD (BX), and result being stored in AX
    MOV [fin], AX       ;storing LCM in 'fin'

    ;Exiting DOS environment
    MOV AH, 0x4C            ;DOS function: terminate program
    XOR AL, AL              ;Return code 0
    INT 0x21                ;Call DOS interrupt to exit