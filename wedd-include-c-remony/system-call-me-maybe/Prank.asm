section .data

	text1 db "What is your name? "

	text2 db "Hello, "

	text3 db "This is a prank! "


section .bss

   	name resb 16


section .text

   	global _start

_start: call _printText1

        call _getName

        call _printText2

        call _printName
	
	call _printText3


        mov rax, 60

        mov rdi, 0

        syscall


_getName: mov rax, 0

        mov rdi, 0

        mov rsi, name

        mov rdx, 35

        syscall

        ret


_printText1: mov rax, 1

             mov rdi, 1

             mov rsi, text1

             mov rdx, 19

             syscall

             ret


_printText2: mov rax, 1

             mov rdi, 1

             mov rsi, text2

             mov rdx, 7

             syscall

             ret


_printName: mov rax, 1

            mov rdi, 1

            mov rsi, name

            mov rdx, 16

            syscall

            ret


_printText3: mov rax, 1

             mov rdi, 1

             mov rsi, text3

             mov rdx, 16

             syscall

             ret
