			global	main
			extern	atoi
			extern	printf
			extern	puts

			section	.text
main:
			cmp	rdi, 3
			jne	incorrectArgumentCount
push 	r10
			push 	r10
			push 	r11
			push	r12			; The necessity of these will depend on implementation;
			push	r13			; this is mainly a reminder to preserve any callee-save
			push	r14			; registers that you might use.
					
			mov r12, rsi
			mov r11, rsi

			mov rdi, [r11+16]
			call atoi
			mov r13, rax

			mov rdi, [r12+8]
			call atoi
			mov r14, rax

			mov r10, rax
			sub r14, r13
			
			mov 	rdi, format
			mov 	rsi, r10
			mov 	rdx, r13
			mov 	rcx, r14
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

			section	.data
incorrectArgumentCountMessage:
			db	"Two arguments are needed in order to perform subtraction.", 0
format:			db	"%d - %d = %d", 10, 0
