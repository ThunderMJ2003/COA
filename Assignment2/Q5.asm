section .data
    numbers dw 10, 20, 30, 40, 50, 60, 70, 80, 90, 100      ; Sorted list of 10 numbers
    X dw 40                     ;given number to search
    output dw 0                 ;to store output: 1 if found, 2 if not found
    iterations dw 0             ;to store number of iterations if found
    index dw 0                  ;to store index if found

section .text
    global _start

_start:
    MOV SI, 0                   ;SI is used as the index, starting from index 0
    MOV CX, 10                  ;CX is used as the loop counter (10 elements in the list)
    MOV AX, [X]                 ;loading the given number into AX
    MOV DI, numbers             ;DI points to the list of numbers
    XOR BX, BX                  ;BX will store the number of iterations

search_loop:
    MOV DX, [DI + SI*2]         ;loading the current number from 'numbers' list
    INC BX                      ;incrementing the iteration counter
    CMP DX, AX                  ;comparing the current number with the given number
    JE found                    ;if equal, go to found
    INC SI                      ;incrementing index (moving to the next element)
    LOOP search_loop            ;looping until CX reaches 0

not_found:
    MOV word [output], 2        ;storing 2 in output (number not found)
    JMP done

found:
    MOV word [output], 1        ;storing 1 in output (number found)
    MOV word [iterations], BX   ;storing the number of iterations
    MOV word [index], SI        ;storing the index of the found element

done:
    ;Exiting DOS environment
    MOV AH, 0x4C            ;DOS function: terminate program
    XOR AL, AL              ;Return code 0
    INT 0x21                ;Call DOS interrupt to exit