			global	main
			extern	atoi
			extern	printf
			extern	puts

			section	.text
main:
			cmp	rdi, 4
			jne	incorrectArgumentCount
			push 	r10
			push 	r11
			push	r12			; The necessity of these will depend on implementation;
			push	r13			; this is mainly a reminder to preserve any callee-save
			push	r14			; registers that you might use.
					
			mov r12, rsi
			mov r11, rsi
			mov r10, rsi

			mov rdi, [r10+24]
			call atoi
			mov r14, rax                      ;3rd argument

			mov rdi, [r12+8]
			call atoi
			mov r13, rax			; 1st argument

			mov rdi, [r11+16]
			cmp rdi, plusOperator           ; 2nd argument
			jne subtration
			
			mov r10, rax
			add r13, r14

			mov 	rdi, format_add
			mov 	rsi, r10
			mov 	rdx, r14
			mov 	rcx, r13
			xor	rax, rax
			call	printf

			pop	r14
			pop	r13
			pop	r12
			pop 	r11
			pop 	r10
			ret

subtraction:
			cmp rdi, minusOperator
			jne incorrectOperatorMessage 
			mov r10, rax
			sub r13, r14	
				
			mov 	rdi, format_sub
			mov 	rsi, r10
			mov 	rdx, r14
			mov 	rcx, r13
			xor	rax, rax
			call	printf

			pop	r14
			pop	r13
			pop	r12
			pop 	r11
			pop 	r10
			ret

incorrectArgumentCount:
			mov	rdi, incorrectArgumentCountMessage
			call	puts
			ret
incorrectOperator:
			mov	rdi, incorrectOperatorMessage
			call	puts
			jmp	finished

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
