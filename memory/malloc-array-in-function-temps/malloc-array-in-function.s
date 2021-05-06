	.file	"malloc-array-in-function.c"
	.text
	.globl	create_array_pointer
	.type	create_array_pointer, @function
create_array_pointer:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	create_array_pointer, .-create_array_pointer
	.section	.rodata
.LC0:
	.string	"Created a %d int index array"
	.text
	.globl	fill_array
	.type	fill_array, @function
fill_array:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L4
.L5:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	-4(%rbp), %edx
	addl	$1, %edx
	movl	%edx, (%rax)
	addl	$1, -4(%rbp)
.L4:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L5
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	fill_array, .-fill_array
	.section	.rodata
	.align 8
.LC1:
	.string	"The elements of the array are: "
.LC2:
	.string	"%d, "
	.text
	.globl	print_array
	.type	print_array, @function
print_array:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -4(%rbp)
	jmp	.L7
.L8:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L8
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	print_array, .-print_array
	.section	.rodata
.LC9:
	.string	"Size allocated: %.2f MB\n"
.LC10:
	.string	"Size allocated: %.2f KB\n"
.LC11:
	.string	"Size allocated: %lu B\n"
	.text
	.globl	print_memory_used
	.type	print_memory_used, @function
print_memory_used:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	cvtsi2sdq	-24(%rbp), %xmm1
	movsd	.LC3(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	.LC4(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -12(%rbp)
	movss	-12(%rbp), %xmm0
	movss	.LC5(%rip), %xmm1
	comiss	%xmm1, %xmm0
	jb	.L17
	cvtsi2sdq	-24(%rbp), %xmm1
	movsd	.LC6(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movsd	.LC7(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	movsd	%xmm0, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	movsd	.LC8(%rip), %xmm1
	comisd	%xmm1, %xmm0
	jb	.L18
	movq	-8(%rbp), %rax
	movq	%rax, %xmm0
	leaq	.LC9(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	jmp	.L19
.L18:
	cvtss2sd	-12(%rbp), %xmm0
	leaq	.LC10(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	jmp	.L19
.L17:
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L19:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	print_memory_used, .-print_memory_used
	.section	.rodata
.LC12:
	.string	""
.LC13:
	.string	"End of the program"
	.text
	.globl	main
	.type	main, @function
main:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	$1000000000, -24(%rbp)
	movq	-24(%rbp), %rax
	salq	$2, %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movl	%eax, %edi
	call	create_array_pointer
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L21
	movl	$0, %edi
	call	exit@PLT
.L21:
	movq	-24(%rbp), %rax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	fill_array
	leaq	.LC12(%rip), %rdi
	call	puts@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	print_memory_used
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	leaq	.LC13(%rip), %rdi
	call	puts@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC3:
	.long	1889785610
	.long	1076070973
	.align 8
.LC4:
	.long	3944497965
	.long	1058682594
	.align 4
.LC5:
	.long	1065353216
	.align 8
.LC6:
	.long	2851858285
	.long	1076040433
	.align 8
.LC7:
	.long	2596056904
	.long	1048238066
	.align 8
.LC8:
	.long	0
	.long	1072693248
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
