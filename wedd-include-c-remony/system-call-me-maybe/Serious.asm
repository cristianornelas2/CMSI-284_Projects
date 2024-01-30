	  global  _start


 
	  section .text

_start:   mov  		rax, 95		; system call for umask

  	  mov   	rdi, 0q22	; set umask (octal)
	
  	 syscall			; invoke the operating system


  	mov   		rax, 83		; system call for mkdir

  	mov   		rdi, pathname	; pathname for directory

  	mov   		rsi, 0q777	; set mkdir mode (octal)

  	syscall				; invoke operating system


  	mov   		rax, 60		; system call for exit
		
  	mov   		rdi, 0		; exit code 0

  	syscall				; invoke operating system


  	section .data

pathname: db      "directory_created_from_assembly_code"
