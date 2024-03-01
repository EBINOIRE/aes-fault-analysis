	.file	"main.c"
	.option nopic
	.attribute arch, "rv32i2p1_m2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.globl	a
	.section	.sdata.a,"aw"
	.align	2
	.type	a, @object
	.size	a, 4
a:
	.word	200
	.globl	b
	.section	.sdata.b,"aw"
	.align	2
	.type	b, @object
	.size	b, 4
b:
	.word	6
	.globl	c
	.section	.sbss.c,"aw",@nobits
	.align	2
	.type	c, @object
	.size	c, 4
c:
	.zero	4
	.globl	i
	.section	.sbss.i,"aw",@nobits
	.align	2
	.type	i, @object
	.size	i, 4
i:
	.zero	4
	.globl	malware_ptr
	.section	.sbss.malware_ptr,"aw",@nobits
	.align	2
	.type	malware_ptr, @object
	.size	malware_ptr, 4
malware_ptr:
	.zero	4
	.globl	long_ptr
	.section	.sbss.long_ptr,"aw",@nobits
	.align	2
	.type	long_ptr, @object
	.size	long_ptr, 4
long_ptr:
	.zero	4
	.section	.text.malware,"ax",@progbits
	.align	2
	.globl	malware
	.type	malware, @function
malware:
	addi	sp,sp,-16
	sw	s0,12(sp)
	addi	s0,sp,16
	lui	a5,%hi(a)
	lw	a4,%lo(a)(a5)
	lui	a5,%hi(b)
	lw	a5,%lo(b)(a5)
	add	a5,a4,a5
	addi	a4,a5,2
	lui	a5,%hi(c)
	sw	a4,%lo(c)(a5)
	nop
	lw	s0,12(sp)
	addi	sp,sp,16
	jr	ra
	.size	malware, .-malware
	.section	.text.victim_function,"ax",@progbits
	.align	2
	.globl	victim_function
	.type	victim_function, @function
victim_function:
	addi	sp,sp,-16
	sw	s0,12(sp)
	addi	s0,sp,16
	lui	a5,%hi(a)
	lw	a4,%lo(a)(a5)
	lui	a5,%hi(b)
	lw	a5,%lo(b)(a5)
	add	a4,a4,a5
	lui	a5,%hi(c)
	sw	a4,%lo(c)(a5)
	nop
	lw	s0,12(sp)
	addi	sp,sp,16
	jr	ra
	.size	victim_function, .-victim_function
	.section	.text.main,"ax",@progbits
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-80
	sw	ra,76(sp)
	sw	s0,72(sp)
	addi	s0,sp,80
	sw	a0,-68(s0)
	sw	a1,-72(s0)
	lui	a5,%hi(long_ptr)
	addi	a4,s0,-64
	sw	a4,%lo(long_ptr)(a5)
	lui	a5,%hi(malware_ptr)
	lui	a4,%hi(malware)
	addi	a4,a4,%lo(malware)
	sw	a4,%lo(malware_ptr)(a5)
	call	victim_function
	lui	a5,%hi(i)
	sw	zero,%lo(i)(a5)
	j	.L4
.L5:
	lui	a5,%hi(malware_ptr)
	lw	a3,%lo(malware_ptr)(a5)
	lui	a5,%hi(long_ptr)
	lw	a4,%lo(long_ptr)(a5)
	lui	a5,%hi(i)
	lw	a5,%lo(i)(a5)
	slli	a5,a5,2
	add	a5,a4,a5
	mv	a4,a3
	sw	a4,0(a5)
	lui	a5,%hi(i)
	lw	a5,%lo(i)(a5)
	addi	a4,a5,1
	lui	a5,%hi(i)
	sw	a4,%lo(i)(a5)
.L4:
	lui	a5,%hi(i)
	lw	a4,%lo(i)(a5)
	li	a5,15
	ble	a4,a5,.L5
	lui	a5,%hi(i)
	lw	a5,%lo(i)(a5)
	addi	a4,a5,5
	lui	a5,%hi(i)
	sw	a4,%lo(i)(a5)
	li	a5,0
	mv	a0,a5
	lw	ra,76(sp)
	lw	s0,72(sp)
	addi	sp,sp,80
	jr	ra
	.size	main, .-main
	.ident	"GCC: (g2ee5e430018) 12.2.0"
