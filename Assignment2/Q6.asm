section .data
    string db "lorem ipsum", 0      ;null-terminated string
    char db 'e'                     ;character to search
    output db 0                     ;to store output: 1 if found, 2 if not found
    index db 0                      ;to store index of the character, if found

section .text
    ORG 0x100                       ;setting origin

_start:
    MOV SI, 0                       ;SI is used as the index, starting from 0
    MOV AL, [char]                  ;loading the character to search into AL
    MOV DI, string                  ;DI points to the start of the string

search_loop:
    MOV BL, [DI + SI]               ;loading the current character from the string
    CMP BL, 0                       ;checking if the end of the string (null-terminator) is reached
    JE not_found                    ;if yes, go to not_found
    CMP BL, AL                      ;comparing the current character with the given character
    JE found                        ;if yes, go to found
    INC SI                          ;incrementing index (moving to the next character)
    JMP search_loop                 ;repeating the search_loop

not_found:
    MOV byte [output], 2            ;storing 2 in output (character not found)
    JMP done

found:
    MOV byte [output], 1            ;storing 1 in output (character found)
    MOV byte [index], SI            ;storing the index of the found character

done:
    ;Exiting DOS environment
    MOV AH, 0x4C            ;DOS function: terminate program
    XOR AL, AL              ;Return code 0
    INT 0x21                ;Call DOS interrupt to exit