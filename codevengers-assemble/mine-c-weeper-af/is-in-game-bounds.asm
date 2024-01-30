			global	is_in_game_bounds

			section	.text
is_in_game_bounds:
			jmp	false

true:
			mov	rax, 1
			ret

false:
			xor	rax, rax
			ret
