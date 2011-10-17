	.file	"test1.c"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$5, -4(%ebp)
	jmp	.L2
.L3:
	subl	$1, -4(%ebp)
.L2:
	cmpl	$0, -4(%ebp)
	jne	.L3
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
