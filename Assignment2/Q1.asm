section .data
    num1 DW 0x1234          ;first 16-bit number
    num2 DW 0xFEDC          ;second 16-bit number
    fin DW 0                ;to store the difference

section .text
    ORG 0x100               ;setting origin

_start:
    MOV AX, [num1]          ;loading num1 in AX register
    MOV BX, [num2]          ;loading num2 in BX register
    NOT BX                  ;inverting all bits
    ADD BX, 1               ;adding 1 to form two's complement
    ADD AX, BX              ;performing subtraction by two's complement method
    MOV [fin], AX           ;storing the result in memory
    
    ;Exiting DOS environment
    MOV AH, 0x4C            ;DOS function: terminate program
    XOR AL, AL              ;Return code 0
    INT 0x21                ;Call DOS interrupt to exit