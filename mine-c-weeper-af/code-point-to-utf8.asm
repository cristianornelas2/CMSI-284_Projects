			global	main
			extern	puts
			extern	sscanf
			extern	printf
			extern	emit_utf_8

			section	.text
main:
			push	rdi
			push	rsi
			sub 	rsp, 8
			
			mov	rdi, [rsi]
			
			mov	rsi, codePointFormat
			mov 	rdx, codePoint
			call	sscanf
			cmp 	rax, 1
			jz	emit
						
			cmp 	rdi, 2
			jl	argumentsError
			push 	rsi

emit:
			mov 	rdi, [codePoint]
			call	emit_utf_8
		
			add 	rsp, 8
			pop	rsi
			pop 	rdi

			add 	rsi, 8
			dec 	rdi
			jnz	main
		
			ret			

argumentsError:		mov	rdi, argumentsRequiredMessage
			call	puts

			mov	rdi, argumentDescription
			call	puts

			xor	rax, rax
			inc	rax
			ret

			section	.data
							; The following definitions are here to get you started and to standardize
							; error messages but of course, feel free to define more as needed.
argumentsRequiredMessage:
			db	"This program requires one or more command line arguments,", 0
argumentDescription:	db	"one for each code point to encode as UTF-8.", 0
incorrectFormat:	db	"(%s incorrect format)", 0
codePointFormat:	db	"U+%6X", 0

			section	.bss
codePoint:		resb	8			; The code point from sscanf should go here.
