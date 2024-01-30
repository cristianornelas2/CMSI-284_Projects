			global	main
			extern  strncmp
			extern  strlen
			extern	atoi
			extern	printf
			extern	puts

			section	.text
main:
			cmp	rdi, 4
			jne	incorrectArgumentCount
			push 	r9			
			push 	r10
			push 	r11
			push	r12			; The necessity of these will depend on implementation;
			push	r13			; this is mainly a reminder to preserve any callee-save
			push	r14			; registers that you might use.
					
			mov r12, rsi

			mov 	rdi, [r12+8]
			call 	atoi
			mov 	r11, rax			

			mov 	rdi, [r12+24]
			call 	atoi
			mov 	r13, rax

			mov 	rdi, [r12+16]
			call 	strlen
			mov 	rdx, rax
			mov 	rsi, plusOperator

			call	strncmp
			jz 	add

			mov 	rsi, minusOperator
			jz 	sub

			jmp incorrectOperator

add:
			mov 	r10, r11
			add 	r11, r13
			jmp	printf

sub:
			mov 	r10, r11
			add 	r11, r13
			jmp 	print

print: 
			mov rdi, resultFormat
			mov rsi, r11
			mov rdx, r13
			mov rcx, r14

finished:
			pop	r14
			pop	r13
			pop	r12
			pop 	r11
			pop 	r10
			pop 	r9
			

incorrectArgumentCount:
			mov	rdi, incorrectArgumentCountMessage
			call	puts
			ret
incorrectOperator:
			mov	rdi, incorrectOperatorMessage
			call	puts

			section	.data

format_add:		db	"%d + %d = %d", 10, 0
format_sub:		db	"%d - %d = %d", 10, 0
plusOperator:		db	"+", 0
minusOperator:		db	"-", 0
resultFormat:		db	"%d %s %d = %d", 10, 0

incorrectArgumentCountMessage:
			db	"To use this program, either enter <number> + <number> or <number> - <number>.", 0

incorrectOperatorMessage:
			db	"This program only recognizes + or -.", 0
