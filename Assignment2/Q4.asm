section .data
    num1 dw 5           ;first number
    num2 dw 3           ;second number
    fin dw 0            ;to store the product

section .text
    ORG 0x100           ;setting origin

_start:
    MOV AX, [num1]      ;loading num1 into AX
    MOV CX, [num2]      ;loading num2 into CX
    XOR DX, DX          ;clearing DX to store the product

multiply_loop:          ;performing multiplication by repeated addition
    CMP CX, 0           ;checking if the counter has reached 0
    JE done             ;if CX is 0, go to done
    ADD DX, AX          ;add AX to DX 
    DEC CX              ;decreasing CX by 1
    JMP multiply_loop   ;repeating the loop

done:
    MOV [fin], DX       ;storing the final result in memory 'fin'

    ;Exiting DOS environment
    MOV AH, 0x4C            ;DOS function: terminate program
    XOR AL, AL              ;Return code 0
    INT 0x21                ;Call DOS interrupt to exit