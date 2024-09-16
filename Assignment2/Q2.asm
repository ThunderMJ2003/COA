section .data
    numbers dw 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150  ;15 consecutive numbers
    count dw 15             ;number/count of elements (15)
    sum dw 0                ;to store the sum of the numbers
    average dw 0            ;to store the average

section .text
    ORG 0x100               ;setting origin

_start:
    MOV CX, [count]         ;loading count of numbers (15) into CX
    LEA SI, [numbers]       ;loading address of the first number in numbers into SI (Source Index)
    XOR AX, AX              ;clearing AX to store the sum
    XOR DX, DX              ;clearing DX for division

sum_loop:
    MOV BX, [SI]            ;load number from memory (numbers[SI]) into BX
    ADD AX, BX              ;adding BX (new number) to AX (sum)
    ADD SI, 2               ;moving to the next number (each number is 2 bytes)
    LOOP sum_loop           ;looping until CX (count) becomes 0
    
    MOV [sum], AX           ;moving the total sum into [sum]
    MOV CX, [count]         ;loading count (15) into CX to use as divisor
    XOR DX, DX              ;clearing DX for division
    div CX                  ;AX = AX / CX
    MOV [average], AX       ;storing the average in [average]

    ;Exiting DOS environment
    MOV AH, 0x4C            ;DOS function: terminate program
    XOR AL, AL              ;Return code 0
    INT 0x21                ;Call DOS interrupt to exit