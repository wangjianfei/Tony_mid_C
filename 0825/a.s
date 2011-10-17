	.file	"test.c"
.globl num
	.section	.rodata
	.type	num, @object
	.size	num, 1
num:
	.byte	6
.globl init
	.data
	.align 4
	.type	init, @object
	.size	init, 4
init:
	.long	7
	.comm	uninit,4,4
	.section	.rodata
.LC0:
	.string	"%d\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$48, %esp
	movl	12(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%gs:20, %eax
	movl	%eax, 44(%esp)
	xorl	%eax, %eax
	leal	34(%esp), %eax
	movl	%eax, (%esp)
	call	gets
	movl	$.LC0, %eax
	movl	$100, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	leal	34(%esp), %eax
	movl	%eax, (%esp)
	call	puts
	movl	$0, %eax
	movl	44(%esp), %edx
	xorl	%gs:20, %edx
	je	.L3
	call	__stack_chk_fail
.L3:
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
