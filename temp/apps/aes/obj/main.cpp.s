	.file	"main.cpp"
	.option nopic
	.attribute arch, "rv32i2p1_m2p0_zicsr2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.section	.text._ZL20__gthread_key_deletei,"ax",@progbits
	.align	2
	.type	_ZL20__gthread_key_deletei, @function
_ZL20__gthread_key_deletei:
.LFB180:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	s0,28(sp)
	.cfi_offset 8, -4
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	sw	a0,-20(s0)
	li	a5,0
	mv	a0,a5
	lw	s0,28(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE180:
	.size	_ZL20__gthread_key_deletei, .-_ZL20__gthread_key_deletei
	.section	.sbss._ZStL8__ioinit,"aw",@nobits
	.align	2
	.type	_ZStL8__ioinit, @object
	.size	_ZStL8__ioinit, 1
_ZStL8__ioinit:
	.zero	1
	.globl	s
	.section	.data.s,"aw"
	.align	2
	.type	s, @object
	.size	s, 256
s:
	.string	"c|w{\362ko\3050\001g+\376\327\253v\312\202\311}\372YG\360\255\324\242\257\234\244r\300\267\375\223&6?\367\3144\245\345\361q\3301\025\004\307#\303\030\226\005\232\007\022\200\342\353'\262u\t\203,\032\033nZ\240R;\326\263)\343/\204S\321"
	.ascii	"\355 \374\261[j\313\2769JLX\317\320\357\252\373CM3\205E\371\002"
	.ascii	"\177P<\237\250Q\243@\217\222\2358\365\274\266\332!\020\377\363"
	.ascii	"\322\315\f\023\354_\227D\027\304\247~=d]\031s`\201O\334\"*\220"
	.ascii	"\210F\356\270\024\336^\013\333\3402:\nI\006$\\\302\323\254b\221"
	.ascii	"\225\344y\347\3107m\215\325N\251lV\364\352ez\256\b\272x%.\034"
	.ascii	"\246\264\306\350\335t\037K\275\213\212p>\265fH\003\366\016a5"
	.ascii	"W\271\206\301\035\236\341\370\230\021i\331\216\224\233\036\207"
	.ascii	"\351\316U(\337\214\241\211\r\277\346BhA\231-\017\260T\273\026"
	.globl	inv_s
	.section	.data.inv_s,"aw"
	.align	2
	.type	inv_s, @object
	.size	inv_s, 256
inv_s:
	.string	"R\tj\32506\2458\277@\243\236\201\363\327\373|\3439\202\233/\377\2074\216CD\304\336\351\313T{\2242\246\302#=\356L\225\013B\372\303N\b.\241f(\331$\262v[\242Im\213\321%r\370\366d\206h\230\026\324\244\\\314]e\266\222lpHP\375\355\271\332^\025FW\247\215\235\204\220\330\253"
	.ascii	"\214\274\323\n\367\344X\005\270\263E\006\320,\036\217\312?\017"
	.ascii	"\002\301\257\275\003\001\023\212k:\221\021AOg\334\352\227\362"
	.ascii	"\317\316\360\264\346s\226\254t\"\347\2555\205\342\3717\350\034"
	.ascii	"u\337nG\361\032q\035)\305\211o\267b\016\252\030\276\033\374V"
	.ascii	">K\306\322y \232\333\300\376x\315Z\364\037\335\2503\210\007\307"
	.ascii	"1\261\022\020Y'\200\354_`Q\177\251\031\265J\r-\345z\237\223\311"
	.ascii	"\234\357\240\340;M\256*\365\260\310\353\273<\203S\231a\027+\004"
	.ascii	"~\272w\326&\341i\024cU!\f}"
	.section	.text._Z4gmulhh,"ax",@progbits
	.align	2
	.globl	_Z4gmulhh
	.type	_Z4gmulhh, @function
_Z4gmulhh:
.LFB1728:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	s0,44(sp)
	.cfi_offset 8, -4
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	mv	a5,a0
	mv	a4,a1
	sb	a5,-33(s0)
	mv	a5,a4
	sb	a5,-34(s0)
	sb	zero,-17(s0)
	j	.L4
.L9:
	lbu	a5,-34(s0)
	andi	a5,a5,1
	beq	a5,zero,.L5
	lbu	a5,-17(s0)
	mv	a4,a5
	lbu	a5,-33(s0)
	xor	a5,a4,a5
	sb	a5,-17(s0)
.L5:
	lb	a5,-33(s0)
	bge	a5,zero,.L6
	lbu	a5,-33(s0)
	slli	a5,a5,1
	slli	a5,a5,24
	srai	a5,a5,24
	xori	a5,a5,27
	slli	a5,a5,24
	srai	a5,a5,24
	sb	a5,-33(s0)
	j	.L7
.L6:
	lbu	a5,-33(s0)
	slli	a5,a5,1
	sb	a5,-33(s0)
.L7:
	lbu	a5,-34(s0)
	srli	a5,a5,1
	sb	a5,-34(s0)
.L4:
	lbu	a5,-33(s0)
	beq	a5,zero,.L8
	lbu	a5,-34(s0)
	bne	a5,zero,.L9
.L8:
	lbu	a5,-17(s0)
	mv	a0,a5
	lw	s0,44(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1728:
	.size	_Z4gmulhh, .-_Z4gmulhh
	.section	.text._Z5frconh,"ax",@progbits
	.align	2
	.globl	_Z5frconh
	.type	_Z5frconh, @function
_Z5frconh:
.LFB1729:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	ra,44(sp)
	sw	s0,40(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	mv	a5,a0
	sb	a5,-33(s0)
	lbu	a5,-33(s0)
	bne	a5,zero,.L12
	li	a5,141
	j	.L13
.L12:
	li	a5,1
	sb	a5,-17(s0)
	li	a5,1
	sb	a5,-18(s0)
	j	.L14
.L15:
	lbu	a5,-17(s0)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	sb	a5,-17(s0)
	lbu	a5,-18(s0)
	addi	a5,a5,1
	sb	a5,-18(s0)
.L14:
	lbu	a4,-18(s0)
	lbu	a5,-33(s0)
	bltu	a4,a5,.L15
	lbu	a5,-17(s0)
.L13:
	mv	a0,a5
	lw	ra,44(sp)
	.cfi_restore 1
	lw	s0,40(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1729:
	.size	_Z5frconh, .-_Z5frconh
	.section	.text._Z17SubWordRotWordXORPhh,"ax",@progbits
	.align	2
	.globl	_Z17SubWordRotWordXORPhh
	.type	_Z17SubWordRotWordXORPhh, @function
_Z17SubWordRotWordXORPhh:
.LFB1730:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	ra,44(sp)
	sw	s0,40(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	sw	a0,-36(s0)
	mv	a5,a1
	sb	a5,-37(s0)
	lw	a5,-36(s0)
	lbu	a5,0(a5)
	sb	a5,-17(s0)
	lw	a5,-36(s0)
	lbu	a4,1(a5)
	lw	a5,-36(s0)
	sb	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,1
	lw	a4,-36(s0)
	lbu	a4,2(a4)
	sb	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,2
	lw	a4,-36(s0)
	lbu	a4,3(a4)
	sb	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,3
	lbu	a4,-17(s0)
	sb	a4,0(a5)
	lw	a5,-36(s0)
	lbu	a5,0(a5)
	mv	a4,a5
	lui	a5,%hi(s)
	addi	a5,a5,%lo(s)
	add	a5,a5,a4
	lbu	a4,0(a5)
	lw	a5,-36(s0)
	sb	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	mv	a3,a5
	lw	a5,-36(s0)
	addi	a5,a5,1
	lui	a4,%hi(s)
	addi	a4,a4,%lo(s)
	add	a4,a4,a3
	lbu	a4,0(a4)
	sb	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	mv	a3,a5
	lw	a5,-36(s0)
	addi	a5,a5,2
	lui	a4,%hi(s)
	addi	a4,a4,%lo(s)
	add	a4,a4,a3
	lbu	a4,0(a4)
	sb	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	mv	a3,a5
	lw	a5,-36(s0)
	addi	a5,a5,3
	lui	a4,%hi(s)
	addi	a4,a4,%lo(s)
	add	a4,a4,a3
	lbu	a4,0(a4)
	sb	a4,0(a5)
	lbu	a5,-37(s0)
	mv	a0,a5
	call	_Z5frconh
	mv	a5,a0
	mv	a4,a5
	lw	a5,-36(s0)
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-36(s0)
	sb	a4,0(a5)
	nop
	lw	ra,44(sp)
	.cfi_restore 1
	lw	s0,40(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1730:
	.size	_Z17SubWordRotWordXORPhh, .-_Z17SubWordRotWordXORPhh
	.section	.text._Z9ExpandKeyPhRS_,"ax",@progbits
	.align	2
	.globl	_Z9ExpandKeyPhRS_
	.type	_Z9ExpandKeyPhRS_, @function
_Z9ExpandKeyPhRS_:
.LFB1731:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sw	ra,60(sp)
	sw	s0,56(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,64
	.cfi_def_cfa 8, 0
	sw	a0,-52(s0)
	sw	a1,-56(s0)
	sw	zero,-20(s0)
	j	.L18
.L19:
	lw	a5,-20(s0)
	lw	a4,-52(s0)
	add	a4,a4,a5
	lw	a5,-56(s0)
	lw	a3,0(a5)
	lw	a5,-20(s0)
	add	a5,a3,a5
	lbu	a4,0(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L18:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L19
	li	a5,16
	sw	a5,-24(s0)
	li	a5,1
	sw	a5,-28(s0)
	j	.L20
.L26:
	sw	zero,-32(s0)
	j	.L21
.L22:
	lw	a5,-56(s0)
	lw	a4,0(a5)
	lw	a3,-32(s0)
	lw	a5,-24(s0)
	add	a5,a3,a5
	addi	a5,a5,-4
	add	a5,a4,a5
	lbu	a4,0(a5)
	lw	a5,-32(s0)
	addi	a5,a5,-16
	add	a5,a5,s0
	sb	a4,-24(a5)
	lw	a5,-32(s0)
	addi	a5,a5,1
	sw	a5,-32(s0)
.L21:
	lw	a4,-32(s0)
	li	a5,3
	ble	a4,a5,.L22
	lw	a5,-24(s0)
	andi	a5,a5,15
	bne	a5,zero,.L23
	lw	a5,-28(s0)
	addi	a4,a5,1
	sw	a4,-28(s0)
	andi	a4,a5,0xff
	addi	a5,s0,-40
	mv	a1,a4
	mv	a0,a5
	call	_Z17SubWordRotWordXORPhh
.L23:
	sb	zero,-33(s0)
	j	.L24
.L25:
	lw	a5,-56(s0)
	lw	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,-16
	add	a5,a4,a5
	lbu	a3,0(a5)
	lbu	a5,-33(s0)
	addi	a5,a5,-16
	add	a5,a5,s0
	lbu	a4,-24(a5)
	lw	a5,-56(s0)
	lw	a2,0(a5)
	lw	a5,-24(s0)
	add	a5,a2,a5
	xor	a4,a3,a4
	andi	a4,a4,0xff
	sb	a4,0(a5)
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
	lbu	a5,-33(s0)
	addi	a5,a5,1
	sb	a5,-33(s0)
.L24:
	lbu	a4,-33(s0)
	li	a5,3
	bleu	a4,a5,.L25
.L20:
	lw	a4,-24(s0)
	li	a5,175
	ble	a4,a5,.L26
	nop
	nop
	lw	ra,60(sp)
	.cfi_restore 1
	lw	s0,56(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 64
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1731:
	.size	_Z9ExpandKeyPhRS_, .-_Z9ExpandKeyPhRS_
	.section	.text._Z14AddSubRoundKeyPhS_,"ax",@progbits
	.align	2
	.globl	_Z14AddSubRoundKeyPhS_
	.type	_Z14AddSubRoundKeyPhS_, @function
_Z14AddSubRoundKeyPhS_:
.LFB1732:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	s0,44(sp)
	.cfi_offset 8, -4
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	sw	a0,-36(s0)
	sw	a1,-40(s0)
	sw	zero,-20(s0)
	j	.L28
.L29:
	lw	a5,-20(s0)
	lw	a4,-36(s0)
	add	a5,a4,a5
	lbu	a3,0(a5)
	lw	a5,-20(s0)
	lw	a4,-40(s0)
	add	a5,a4,a5
	lbu	a4,0(a5)
	lw	a5,-20(s0)
	lw	a2,-36(s0)
	add	a5,a2,a5
	xor	a4,a3,a4
	andi	a4,a4,0xff
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L28:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L29
	nop
	nop
	lw	s0,44(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1732:
	.size	_Z14AddSubRoundKeyPhS_, .-_Z14AddSubRoundKeyPhS_
	.section	.text._Z11EncSubBytesPh,"ax",@progbits
	.align	2
	.globl	_Z11EncSubBytesPh
	.type	_Z11EncSubBytesPh, @function
_Z11EncSubBytesPh:
.LFB1733:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	s0,44(sp)
	.cfi_offset 8, -4
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	sw	a0,-36(s0)
	sw	zero,-20(s0)
	j	.L31
.L32:
	lw	a5,-20(s0)
	lw	a4,-36(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	mv	a3,a5
	lw	a5,-20(s0)
	lw	a4,-36(s0)
	add	a5,a4,a5
	lui	a4,%hi(s)
	addi	a4,a4,%lo(s)
	add	a4,a4,a3
	lbu	a4,0(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L31:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L32
	nop
	nop
	lw	s0,44(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1733:
	.size	_Z11EncSubBytesPh, .-_Z11EncSubBytesPh
	.section	.text._Z13LeftShiftRowsPh,"ax",@progbits
	.align	2
	.globl	_Z13LeftShiftRowsPh
	.type	_Z13LeftShiftRowsPh, @function
_Z13LeftShiftRowsPh:
.LFB1734:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sw	s0,60(sp)
	.cfi_offset 8, -4
	addi	s0,sp,64
	.cfi_def_cfa 8, 0
	sw	a0,-52(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	sb	a5,-36(s0)
	lw	a5,-52(s0)
	lbu	a5,5(a5)
	sb	a5,-35(s0)
	lw	a5,-52(s0)
	lbu	a5,10(a5)
	sb	a5,-34(s0)
	lw	a5,-52(s0)
	lbu	a5,15(a5)
	sb	a5,-33(s0)
	lw	a5,-52(s0)
	lbu	a5,4(a5)
	sb	a5,-32(s0)
	lw	a5,-52(s0)
	lbu	a5,9(a5)
	sb	a5,-31(s0)
	lw	a5,-52(s0)
	lbu	a5,14(a5)
	sb	a5,-30(s0)
	lw	a5,-52(s0)
	lbu	a5,3(a5)
	sb	a5,-29(s0)
	lw	a5,-52(s0)
	lbu	a5,8(a5)
	sb	a5,-28(s0)
	lw	a5,-52(s0)
	lbu	a5,13(a5)
	sb	a5,-27(s0)
	lw	a5,-52(s0)
	lbu	a5,2(a5)
	sb	a5,-26(s0)
	lw	a5,-52(s0)
	lbu	a5,7(a5)
	sb	a5,-25(s0)
	lw	a5,-52(s0)
	lbu	a5,12(a5)
	sb	a5,-24(s0)
	lw	a5,-52(s0)
	lbu	a5,1(a5)
	sb	a5,-23(s0)
	lw	a5,-52(s0)
	lbu	a5,6(a5)
	sb	a5,-22(s0)
	lw	a5,-52(s0)
	lbu	a5,11(a5)
	sb	a5,-21(s0)
	sw	zero,-20(s0)
	j	.L34
.L35:
	lw	a5,-20(s0)
	lw	a4,-52(s0)
	add	a5,a4,a5
	lw	a4,-20(s0)
	addi	a4,a4,-16
	add	a4,a4,s0
	lbu	a4,-20(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L34:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L35
	nop
	nop
	lw	s0,60(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 64
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1734:
	.size	_Z13LeftShiftRowsPh, .-_Z13LeftShiftRowsPh
	.section	.text._Z10MixColumnsPh,"ax",@progbits
	.align	2
	.globl	_Z10MixColumnsPh
	.type	_Z10MixColumnsPh, @function
_Z10MixColumnsPh:
.LFB1735:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sw	ra,60(sp)
	sw	s0,56(sp)
	sw	s1,52(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	.cfi_offset 9, -12
	addi	s0,sp,64
	.cfi_def_cfa 8, 0
	sw	a0,-52(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-36(s0)
	lw	a5,-52(s0)
	lbu	s1,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-35(s0)
	lw	a5,-52(s0)
	lbu	a4,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-34(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	a4,a5
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-33(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-32(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	s1,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-31(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	a4,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-30(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	a4,a5
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-29(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-28(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	s1,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-27(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	a4,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-26(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	a4,a5
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-25(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-24(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	s1,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a5,a5,0xff
	sb	a5,-23(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	a4,0(a5)
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-22(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	a5,0(a5)
	li	a1,3
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	a4,a5
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	xor	a5,a4,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	li	a1,2
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-21(s0)
	sw	zero,-20(s0)
	j	.L37
.L38:
	lw	a5,-20(s0)
	lw	a4,-52(s0)
	add	a5,a4,a5
	lw	a4,-20(s0)
	addi	a4,a4,-16
	add	a4,a4,s0
	lbu	a4,-20(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L37:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L38
	nop
	nop
	lw	ra,60(sp)
	.cfi_restore 1
	lw	s0,56(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 64
	lw	s1,52(sp)
	.cfi_restore 9
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1735:
	.size	_Z10MixColumnsPh, .-_Z10MixColumnsPh
	.section	.text._Z7EncryptPhS_RS_,"ax",@progbits
	.align	2
	.globl	_Z7EncryptPhS_RS_
	.type	_Z7EncryptPhS_RS_, @function
_Z7EncryptPhS_RS_:
.LFB1736:
	.cfi_startproc
	addi	sp,sp,-80
	.cfi_def_cfa_offset 80
	sw	ra,76(sp)
	sw	s0,72(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,80
	.cfi_def_cfa 8, 0
	sw	a0,-68(s0)
	sw	a1,-72(s0)
	sw	a2,-76(s0)
	sw	zero,-20(s0)
	j	.L40
.L41:
	lw	a5,-20(s0)
	lw	a4,-68(s0)
	add	a5,a4,a5
	lbu	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,-16
	add	a5,a5,s0
	sb	a4,-28(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L40:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L41
	addi	a5,s0,-44
	lw	a1,-72(s0)
	mv	a0,a5
	call	_Z14AddSubRoundKeyPhS_
	li	a5,1
	sw	a5,-24(s0)
	j	.L42
.L43:
	addi	a5,s0,-44
	mv	a0,a5
	call	_Z11EncSubBytesPh
	addi	a5,s0,-44
	mv	a0,a5
	call	_Z13LeftShiftRowsPh
	addi	a5,s0,-44
	mv	a0,a5
	call	_Z10MixColumnsPh
	lw	a5,-24(s0)
	slli	a5,a5,4
	mv	a4,a5
	lw	a5,-72(s0)
	add	a4,a5,a4
	addi	a5,s0,-44
	mv	a1,a4
	mv	a0,a5
	call	_Z14AddSubRoundKeyPhS_
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
.L42:
	lw	a4,-24(s0)
	li	a5,9
	ble	a4,a5,.L43
	addi	a5,s0,-44
	mv	a0,a5
	call	_Z11EncSubBytesPh
	addi	a5,s0,-44
	mv	a0,a5
	call	_Z13LeftShiftRowsPh
	lw	a5,-72(s0)
	addi	a4,a5,160
	addi	a5,s0,-44
	mv	a1,a4
	mv	a0,a5
	call	_Z14AddSubRoundKeyPhS_
	sw	zero,-28(s0)
	j	.L44
.L45:
	lw	a5,-76(s0)
	lw	a4,0(a5)
	lw	a5,-28(s0)
	add	a5,a4,a5
	lw	a4,-28(s0)
	addi	a4,a4,-16
	add	a4,a4,s0
	lbu	a4,-28(a4)
	sb	a4,0(a5)
	lw	a5,-28(s0)
	addi	a5,a5,1
	sw	a5,-28(s0)
.L44:
	lw	a4,-28(s0)
	li	a5,15
	ble	a4,a5,.L45
	nop
	nop
	lw	ra,76(sp)
	.cfi_restore 1
	lw	s0,72(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 80
	addi	sp,sp,80
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1736:
	.size	_Z7EncryptPhS_RS_, .-_Z7EncryptPhS_RS_
	.section	.text._Z17InverseMixColumnsPh,"ax",@progbits
	.align	2
	.globl	_Z17InverseMixColumnsPh
	.type	_Z17InverseMixColumnsPh, @function
_Z17InverseMixColumnsPh:
.LFB1737:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sw	ra,60(sp)
	sw	s0,56(sp)
	sw	s1,52(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	.cfi_offset 9, -12
	addi	s0,sp,64
	.cfi_def_cfa 8, 0
	sw	a0,-52(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-36(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-35(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-34(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,1
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,2
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,3
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-33(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-32(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-31(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-30(s0)
	lw	a5,-52(s0)
	addi	a5,a5,4
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,5
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,6
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,7
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-29(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-28(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-27(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-26(s0)
	lw	a5,-52(s0)
	addi	a5,a5,8
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,9
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,10
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,11
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-25(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-24(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-23(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-22(s0)
	lw	a5,-52(s0)
	addi	a5,a5,12
	lbu	a5,0(a5)
	li	a1,11
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	mv	s1,a5
	lw	a5,-52(s0)
	addi	a5,a5,13
	lbu	a5,0(a5)
	li	a1,13
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,14
	lbu	a5,0(a5)
	li	a1,9
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	s1,a5,0xff
	lw	a5,-52(s0)
	addi	a5,a5,15
	lbu	a5,0(a5)
	li	a1,14
	mv	a0,a5
	call	_Z4gmulhh
	mv	a5,a0
	xor	a5,s1,a5
	andi	a5,a5,0xff
	sb	a5,-21(s0)
	sw	zero,-20(s0)
	j	.L47
.L48:
	lw	a5,-20(s0)
	lw	a4,-52(s0)
	add	a5,a4,a5
	lw	a4,-20(s0)
	addi	a4,a4,-16
	add	a4,a4,s0
	lbu	a4,-20(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L47:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L48
	nop
	nop
	lw	ra,60(sp)
	.cfi_restore 1
	lw	s0,56(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 64
	lw	s1,52(sp)
	.cfi_restore 9
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1737:
	.size	_Z17InverseMixColumnsPh, .-_Z17InverseMixColumnsPh
	.section	.text._Z14RightShiftRowsPh,"ax",@progbits
	.align	2
	.globl	_Z14RightShiftRowsPh
	.type	_Z14RightShiftRowsPh, @function
_Z14RightShiftRowsPh:
.LFB1738:
	.cfi_startproc
	addi	sp,sp,-64
	.cfi_def_cfa_offset 64
	sw	s0,60(sp)
	.cfi_offset 8, -4
	addi	s0,sp,64
	.cfi_def_cfa 8, 0
	sw	a0,-52(s0)
	lw	a5,-52(s0)
	lbu	a5,0(a5)
	sb	a5,-36(s0)
	lw	a5,-52(s0)
	lbu	a5,13(a5)
	sb	a5,-35(s0)
	lw	a5,-52(s0)
	lbu	a5,10(a5)
	sb	a5,-34(s0)
	lw	a5,-52(s0)
	lbu	a5,7(a5)
	sb	a5,-33(s0)
	lw	a5,-52(s0)
	lbu	a5,4(a5)
	sb	a5,-32(s0)
	lw	a5,-52(s0)
	lbu	a5,1(a5)
	sb	a5,-31(s0)
	lw	a5,-52(s0)
	lbu	a5,14(a5)
	sb	a5,-30(s0)
	lw	a5,-52(s0)
	lbu	a5,11(a5)
	sb	a5,-29(s0)
	lw	a5,-52(s0)
	lbu	a5,8(a5)
	sb	a5,-28(s0)
	lw	a5,-52(s0)
	lbu	a5,5(a5)
	sb	a5,-27(s0)
	lw	a5,-52(s0)
	lbu	a5,2(a5)
	sb	a5,-26(s0)
	lw	a5,-52(s0)
	lbu	a5,15(a5)
	sb	a5,-25(s0)
	lw	a5,-52(s0)
	lbu	a5,12(a5)
	sb	a5,-24(s0)
	lw	a5,-52(s0)
	lbu	a5,9(a5)
	sb	a5,-23(s0)
	lw	a5,-52(s0)
	lbu	a5,6(a5)
	sb	a5,-22(s0)
	lw	a5,-52(s0)
	lbu	a5,3(a5)
	sb	a5,-21(s0)
	sw	zero,-20(s0)
	j	.L50
.L51:
	lw	a5,-20(s0)
	lw	a4,-52(s0)
	add	a5,a4,a5
	lw	a4,-20(s0)
	addi	a4,a4,-16
	add	a4,a4,s0
	lbu	a4,-20(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L50:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L51
	nop
	nop
	lw	s0,60(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 64
	addi	sp,sp,64
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1738:
	.size	_Z14RightShiftRowsPh, .-_Z14RightShiftRowsPh
	.section	.text._Z11DecSubBytesPh,"ax",@progbits
	.align	2
	.globl	_Z11DecSubBytesPh
	.type	_Z11DecSubBytesPh, @function
_Z11DecSubBytesPh:
.LFB1739:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	s0,44(sp)
	.cfi_offset 8, -4
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	sw	a0,-36(s0)
	sw	zero,-20(s0)
	j	.L53
.L54:
	lw	a5,-20(s0)
	lw	a4,-36(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	mv	a3,a5
	lw	a5,-20(s0)
	lw	a4,-36(s0)
	add	a5,a4,a5
	lui	a4,%hi(inv_s)
	addi	a4,a4,%lo(inv_s)
	add	a4,a4,a3
	lbu	a4,0(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L53:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L54
	nop
	nop
	lw	s0,44(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1739:
	.size	_Z11DecSubBytesPh, .-_Z11DecSubBytesPh
	.section	.text._Z7DecryptPhS_RS_,"ax",@progbits
	.align	2
	.globl	_Z7DecryptPhS_RS_
	.type	_Z7DecryptPhS_RS_, @function
_Z7DecryptPhS_RS_:
.LFB1740:
	.cfi_startproc
	addi	sp,sp,-80
	.cfi_def_cfa_offset 80
	sw	ra,76(sp)
	sw	s0,72(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,80
	.cfi_def_cfa 8, 0
	sw	a0,-68(s0)
	sw	a1,-72(s0)
	sw	a2,-76(s0)
	lw	a5,-76(s0)
	addi	a4,s0,-64
	sw	a4,0(a5)
	sw	zero,-20(s0)
	j	.L56
.L57:
	lw	a5,-20(s0)
	lw	a4,-68(s0)
	add	a5,a4,a5
	lbu	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,-16
	add	a5,a5,s0
	sb	a4,-32(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L56:
	lw	a4,-20(s0)
	li	a5,15
	ble	a4,a5,.L57
	lw	a5,-72(s0)
	addi	a4,a5,160
	addi	a5,s0,-48
	mv	a1,a4
	mv	a0,a5
	call	_Z14AddSubRoundKeyPhS_
	addi	a5,s0,-48
	mv	a0,a5
	call	_Z14RightShiftRowsPh
	addi	a5,s0,-48
	mv	a0,a5
	call	_Z11DecSubBytesPh
	li	a5,9
	sw	a5,-32(s0)
	li	a5,9
	sw	a5,-24(s0)
	j	.L58
.L59:
	lw	a5,-24(s0)
	slli	a5,a5,4
	mv	a4,a5
	lw	a5,-72(s0)
	add	a4,a5,a4
	addi	a5,s0,-48
	mv	a1,a4
	mv	a0,a5
	call	_Z14AddSubRoundKeyPhS_
	addi	a5,s0,-48
	mv	a0,a5
	call	_Z17InverseMixColumnsPh
	addi	a5,s0,-48
	mv	a0,a5
	call	_Z14RightShiftRowsPh
	addi	a5,s0,-48
	mv	a0,a5
	call	_Z11DecSubBytesPh
	lw	a5,-24(s0)
	addi	a5,a5,-1
	sw	a5,-24(s0)
.L58:
	lw	a5,-24(s0)
	bgt	a5,zero,.L59
	addi	a5,s0,-48
	lw	a1,-72(s0)
	mv	a0,a5
	call	_Z14AddSubRoundKeyPhS_
	sw	zero,-28(s0)
	j	.L60
.L61:
	lw	a5,-76(s0)
	lw	a4,0(a5)
	lw	a5,-28(s0)
	add	a5,a4,a5
	lw	a4,-28(s0)
	addi	a4,a4,-16
	add	a4,a4,s0
	lbu	a4,-32(a4)
	sb	a4,0(a5)
	lw	a5,-28(s0)
	addi	a5,a5,1
	sw	a5,-28(s0)
.L60:
	lw	a4,-28(s0)
	li	a5,15
	ble	a4,a5,.L61
	nop
	nop
	lw	ra,76(sp)
	.cfi_restore 1
	lw	s0,72(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 80
	addi	sp,sp,80
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1740:
	.size	_Z7DecryptPhS_RS_, .-_Z7DecryptPhS_RS_
	.section	.text._Z10string2hexPci,"ax",@progbits
	.align	2
	.globl	_Z10string2hexPci
	.type	_Z10string2hexPci, @function
_Z10string2hexPci:
.LFB1741:
	.cfi_startproc
	addi	sp,sp,-176
	.cfi_def_cfa_offset 176
	sw	s0,172(sp)
	.cfi_offset 8, -4
	addi	s0,sp,176
	.cfi_def_cfa 8, 0
	sw	a0,-164(s0)
	sw	a1,-168(s0)
	mv	a1,sp
	mv	t3,a1
	sw	zero,-20(s0)
	j	.L63
.L64:
	lw	a1,-20(s0)
	addi	a1,a1,48
	lw	a0,-20(s0)
	andi	a0,a0,0xff
	addi	a1,a1,-16
	add	a1,a1,s0
	sb	a0,-136(a1)
	lw	a1,-20(s0)
	addi	a1,a1,1
	sw	a1,-20(s0)
.L63:
	lw	a0,-20(s0)
	li	a1,9
	ble	a0,a1,.L64
	sw	zero,-24(s0)
	j	.L65
.L66:
	lw	a1,-24(s0)
	andi	a0,a1,0xff
	lw	a1,-24(s0)
	addi	a1,a1,97
	addi	a0,a0,10
	andi	a0,a0,0xff
	addi	a1,a1,-16
	add	a1,a1,s0
	sb	a0,-136(a1)
	lw	a1,-24(s0)
	addi	a1,a1,1
	sw	a1,-24(s0)
.L65:
	lw	a0,-24(s0)
	li	a1,5
	ble	a0,a1,.L66
	lw	a1,-168(s0)
	srli	a0,a1,31
	add	a1,a0,a1
	srai	a1,a1,1
	addi	a0,a1,-1
	sw	a0,-32(s0)
	mv	a0,a1
	mv	t1,a0
	li	t2,0
	srli	a0,t1,29
	slli	a3,t2,3
	or	a3,a0,a3
	slli	a2,t1,3
	mv	a3,a1
	mv	a6,a3
	li	a7,0
	srli	a3,a6,29
	slli	a5,a7,3
	or	a5,a3,a5
	slli	a4,a6,3
	mv	a5,a1
	addi	a5,a5,15
	srli	a5,a5,4
	slli	a5,a5,4
	sub	sp,sp,a5
	mv	a5,sp
	addi	a5,a5,0
	sw	a5,-36(s0)
	sw	zero,-28(s0)
	j	.L67
.L68:
	lw	a5,-28(s0)
	slli	a5,a5,1
	mv	a4,a5
	lw	a5,-164(s0)
	add	a5,a5,a4
	lbu	a5,0(a5)
	sb	a5,-41(s0)
	lw	a5,-28(s0)
	slli	a5,a5,1
	addi	a5,a5,1
	lw	a4,-164(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	sb	a5,-42(s0)
	lbu	a5,-41(s0)
	addi	a5,a5,-16
	add	a5,a5,s0
	lbu	a5,-136(a5)
	sw	a5,-48(s0)
	lbu	a5,-42(s0)
	addi	a5,a5,-16
	add	a5,a5,s0
	lbu	a5,-136(a5)
	sw	a5,-52(s0)
	lw	a5,-48(s0)
	andi	a5,a5,0xff
	slli	a5,a5,4
	andi	a4,a5,0xff
	lw	a5,-52(s0)
	andi	a5,a5,0xff
	add	a5,a4,a5
	andi	a4,a5,0xff
	lw	a3,-36(s0)
	lw	a5,-28(s0)
	add	a5,a3,a5
	sb	a4,0(a5)
	lw	a5,-28(s0)
	addi	a5,a5,1
	sw	a5,-28(s0)
.L67:
	lw	a5,-168(s0)
	srli	a4,a5,31
	add	a5,a4,a5
	srai	a5,a5,1
	mv	a4,a5
	lw	a5,-28(s0)
	blt	a5,a4,.L68
	lw	a5,-36(s0)
	sw	a5,-40(s0)
	lw	a5,-40(s0)
	mv	sp,t3
	mv	a0,a5
	addi	sp,s0,-176
	.cfi_def_cfa 2, 176
	lw	s0,172(sp)
	.cfi_restore 8
	addi	sp,sp,176
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1741:
	.size	_Z10string2hexPci, .-_Z10string2hexPci
	.section	.text._Z10hex2stringB5cxx11Phi,"ax",@progbits
	.align	2
	.globl	_Z10hex2stringB5cxx11Phi
	.type	_Z10hex2stringB5cxx11Phi, @function
_Z10hex2stringB5cxx11Phi:
.LFB1742:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1742
	addi	sp,sp,-240
	.cfi_def_cfa_offset 240
	sw	ra,236(sp)
	sw	s0,232(sp)
	sw	s1,228(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	.cfi_offset 9, -12
	addi	s0,sp,240
	.cfi_def_cfa 8, 0
	sw	a0,-228(s0)
	sw	a1,-232(s0)
	sw	a2,-236(s0)
	sw	zero,-20(s0)
	j	.L71
.L72:
	lw	a5,-20(s0)
	andi	a5,a5,0xff
	addi	a5,a5,48
	andi	a4,a5,0xff
	lw	a5,-20(s0)
	addi	a5,a5,-16
	add	a5,a5,s0
	sb	a4,-204(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L71:
	lw	a4,-20(s0)
	li	a5,9
	ble	a4,a5,.L72
	sw	zero,-24(s0)
	j	.L73
.L74:
	lw	a5,-24(s0)
	andi	a4,a5,0xff
	lw	a5,-24(s0)
	addi	a5,a5,10
	addi	a4,a4,97
	andi	a4,a4,0xff
	addi	a5,a5,-16
	add	a5,a5,s0
	sb	a4,-204(a5)
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
.L73:
	lw	a4,-24(s0)
	li	a5,5
	ble	a4,a5,.L74
	lw	a0,-228(s0)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
	sw	zero,-28(s0)
	j	.L75
.L76:
	lw	a5,-28(s0)
	lw	a4,-232(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	sw	a5,-32(s0)
	lw	a5,-32(s0)
	srai	a4,a5,31
	andi	a4,a4,15
	add	a5,a4,a5
	srai	a5,a5,4
	addi	a5,a5,-16
	add	a5,a5,s0
	lbu	a5,-204(a5)
	sw	a5,-36(s0)
	lw	a4,-32(s0)
	srai	a5,a4,31
	srli	a5,a5,28
	add	a4,a4,a5
	andi	a4,a4,15
	sub	a5,a4,a5
	addi	a5,a5,-16
	add	a5,a5,s0
	lbu	a5,-204(a5)
	sw	a5,-40(s0)
	lw	a5,-36(s0)
	andi	s1,a5,0xff
	addi	a5,s0,-72
	mv	a0,a5
	call	_ZNSaIcEC1Ev
	addi	a4,s0,-72
	addi	a5,s0,-96
	mv	a3,a4
	mv	a2,s1
	li	a1,1
	mv	a0,a5
.LEHB0:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEjcRKS3_
.LEHE0:
	lw	a5,-40(s0)
	andi	s1,a5,0xff
	addi	a5,s0,-44
	mv	a0,a5
	call	_ZNSaIcEC1Ev
	addi	a4,s0,-44
	addi	a5,s0,-68
	mv	a3,a4
	mv	a2,s1
	li	a1,1
	mv	a0,a5
.LEHB1:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEjcRKS3_
.LEHE1:
	addi	a5,s0,-120
	addi	a3,s0,-68
	addi	a4,s0,-96
	mv	a2,a3
	mv	a1,a4
	mv	a0,a5
.LEHB2:
	call	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_
.LEHE2:
	addi	a5,s0,-120
	mv	a1,a5
	lw	a0,-228(s0)
.LEHB3:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEpLERKS4_
.LEHE3:
	addi	a5,s0,-120
	mv	a0,a5
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	addi	a5,s0,-68
	mv	a0,a5
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	addi	a5,s0,-44
	mv	a0,a5
	call	_ZNSaIcED1Ev
	addi	a5,s0,-96
	mv	a0,a5
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	addi	a5,s0,-72
	mv	a0,a5
	call	_ZNSaIcED1Ev
	lw	a5,-28(s0)
	addi	a5,a5,1
	sw	a5,-28(s0)
.L75:
	lw	a4,-28(s0)
	lw	a5,-236(s0)
	blt	a4,a5,.L76
	j	.L86
.L85:
	mv	s1,a0
	addi	a5,s0,-120
	mv	a0,a5
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	j	.L79
.L84:
	mv	s1,a0
.L79:
	addi	a5,s0,-68
	mv	a0,a5
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	j	.L80
.L83:
	mv	s1,a0
.L80:
	addi	a5,s0,-44
	mv	a0,a5
	call	_ZNSaIcED1Ev
	addi	a5,s0,-96
	mv	a0,a5
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	j	.L81
.L82:
	mv	s1,a0
.L81:
	addi	a5,s0,-72
	mv	a0,a5
	call	_ZNSaIcED1Ev
	lw	a0,-228(s0)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	mv	a5,s1
	mv	a0,a5
.LEHB4:
	call	_Unwind_Resume
.LEHE4:
.L86:
	lw	a0,-228(s0)
	lw	ra,236(sp)
	.cfi_restore 1
	lw	s0,232(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 240
	lw	s1,228(sp)
	.cfi_restore 9
	addi	sp,sp,240
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1742:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._Z10hex2stringB5cxx11Phi,"aw",@progbits
.LLSDA1742:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x41
	.4byte	.LEHB0-.LFB1742
	.4byte	.LEHE0-.LEHB0
	.4byte	.L82-.LFB1742
	.byte	0
	.4byte	.LEHB1-.LFB1742
	.4byte	.LEHE1-.LEHB1
	.4byte	.L83-.LFB1742
	.byte	0
	.4byte	.LEHB2-.LFB1742
	.4byte	.LEHE2-.LEHB2
	.4byte	.L84-.LFB1742
	.byte	0
	.4byte	.LEHB3-.LFB1742
	.4byte	.LEHE3-.LEHB3
	.4byte	.L85-.LFB1742
	.byte	0
	.4byte	.LEHB4-.LFB1742
	.4byte	.LEHE4-.LEHB4
	.4byte	0
	.byte	0
	.section	.text._Z10hex2stringB5cxx11Phi
	.size	_Z10hex2stringB5cxx11Phi, .-_Z10hex2stringB5cxx11Phi
	.section	.text._Z6substrPKciiRPc,"ax",@progbits
	.align	2
	.globl	_Z6substrPKciiRPc
	.type	_Z6substrPKciiRPc, @function
_Z6substrPKciiRPc:
.LFB1744:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	s0,44(sp)
	.cfi_offset 8, -4
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	sw	a0,-36(s0)
	sw	a1,-40(s0)
	sw	a2,-44(s0)
	sw	a3,-48(s0)
	lw	a4,-44(s0)
	lw	a5,-40(s0)
	sub	a5,a4,a5
	sw	a5,-24(s0)
	lw	a5,-40(s0)
	sw	a5,-20(s0)
	j	.L88
.L90:
	lw	a5,-20(s0)
	lw	a4,-36(s0)
	add	a4,a4,a5
	lw	a5,-48(s0)
	lw	a5,0(a5)
	lw	a2,-20(s0)
	lw	a3,-40(s0)
	sub	a3,a2,a3
	add	a5,a5,a3
	lbu	a4,0(a4)
	sb	a4,0(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L88:
	lw	a4,-20(s0)
	lw	a5,-44(s0)
	bge	a4,a5,.L89
	lw	a5,-20(s0)
	lw	a4,-36(s0)
	add	a5,a4,a5
	lbu	a5,0(a5)
	bne	a5,zero,.L90
.L89:
	lw	a5,-48(s0)
	lw	a5,0(a5)
	lw	a3,-20(s0)
	lw	a4,-40(s0)
	sub	a4,a3,a4
	add	a5,a5,a4
	sb	zero,0(a5)
	nop
	lw	s0,44(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1744:
	.size	_Z6substrPKciiRPc, .-_Z6substrPKciiRPc
	.section	.rodata
	.align	2
.LC0:
	.string	"6aadbb608e5f57f983dc50a72019311d"
	.align	2
.LC1:
	.string	"cf74578ab8532901cf74578ab8532901"
	.section	.text.main,"ax",@progbits
	.align	2
	.globl	main
	.type	main, @function
main:
.LFB1745:
	.cfi_startproc
	addi	sp,sp,-80
	.cfi_def_cfa_offset 80
	sw	ra,76(sp)
	sw	s0,72(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,80
	.cfi_def_cfa 8, 0
	lui	a5,%hi(.LC0)
	addi	a5,a5,%lo(.LC0)
	sw	a5,-28(s0)
	lui	a5,%hi(.LC1)
	addi	a5,a5,%lo(.LC1)
	sw	a5,-32(s0)
	li	a1,32
	lw	a0,-32(s0)
	call	_Z10string2hexPci
	sw	a0,-36(s0)
	addi	a5,s0,-52
	mv	a1,a5
	lw	a0,-36(s0)
	call	_Z9ExpandKeyPhRS_
	li	a5,32
	sw	a5,-56(s0)
	sw	zero,-20(s0)
	j	.L92
.L96:
	lw	a5,-20(s0)
	addi	a5,a5,1
	slli	a5,a5,5
	sw	a5,-48(s0)
	addi	a4,s0,-48
	addi	a5,s0,-56
	mv	a1,a4
	mv	a0,a5
	call	_ZSt3minIiERKT_S2_S2_
	mv	a5,a0
	lw	a5,0(a5)
	sw	a5,-40(s0)
	lw	a5,-20(s0)
	slli	a1,a5,5
	lw	a5,-20(s0)
	slli	a4,a5,5
	lw	a5,-40(s0)
	add	a5,a4,a5
	addi	a4,s0,-60
	mv	a3,a4
	mv	a2,a5
	lw	a0,-28(s0)
	call	_Z6substrPKciiRPc
	sw	zero,-24(s0)
	j	.L93
.L95:
	lw	a5,-60(s0)
	addi	a5,a5,48
	sw	a5,-60(s0)
	lw	a5,-24(s0)
	addi	a5,a5,1
	sw	a5,-24(s0)
.L93:
	lw	a5,-40(s0)
	andi	a5,a5,31
	beq	a5,zero,.L94
	lw	a4,-40(s0)
	srai	a5,a4,31
	srli	a5,a5,27
	add	a4,a4,a5
	andi	a4,a4,31
	sub	a5,a4,a5
	mv	a4,a5
	li	a5,32
	sub	a5,a5,a4
	lw	a4,-24(s0)
	blt	a4,a5,.L95
.L94:
	lw	a5,-60(s0)
	li	a1,32
	mv	a0,a5
	call	_Z10string2hexPci
	sw	a0,-44(s0)
	lw	a5,-52(s0)
	addi	a4,s0,-64
	mv	a2,a4
	mv	a1,a5
	lw	a0,-44(s0)
	call	_Z7EncryptPhS_RS_
	lw	a5,-64(s0)
	lw	a4,-52(s0)
	addi	a3,s0,-68
	mv	a2,a3
	mv	a1,a4
	mv	a0,a5
	call	_Z7DecryptPhS_RS_
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L92:
	lw	a5,-56(s0)
	addi	a5,a5,31
	srai	a4,a5,31
	andi	a4,a4,31
	add	a5,a4,a5
	srai	a5,a5,5
	mv	a4,a5
	lw	a5,-20(s0)
	blt	a5,a4,.L96
	li	a5,0
	mv	a0,a5
	lw	ra,76(sp)
	.cfi_restore 1
	lw	s0,72(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 80
	addi	sp,sp,80
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1745:
	.size	main, .-main
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD5Ev,comdat
	.align	2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev:
.LFB1855:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	ra,28(sp)
	sw	s0,24(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	sw	a0,-20(s0)
	lw	a0,-20(s0)
	call	_ZNSaIcED2Ev
	nop
	lw	ra,28(sp)
	.cfi_restore 1
	lw	s0,24(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1855:
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD2Ev
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5IS3_EEjcRKS3_,comdat
	.align	2
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_
	.type	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_, @function
_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_:
.LFB1857:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1857
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	ra,28(sp)
	sw	s0,24(sp)
	sw	s1,20(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	.cfi_offset 9, -12
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	sw	a0,-20(s0)
	sw	a1,-24(s0)
	mv	a5,a2
	sw	a3,-32(s0)
	sb	a5,-25(s0)
	lw	s1,-20(s0)
	lw	a0,-20(s0)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE13_M_local_dataEv
	mv	a5,a0
	lw	a2,-32(s0)
	mv	a1,a5
	mv	a0,s1
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderC1EPcRKS3_
	lbu	a5,-25(s0)
	mv	a2,a5
	lw	a1,-24(s0)
	lw	a0,-20(s0)
.LEHB5:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_M_constructEjc
.LEHE5:
	j	.L102
.L101:
	mv	s1,a0
	lw	a5,-20(s0)
	mv	a0,a5
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderD1Ev
	mv	a5,s1
	mv	a0,a5
.LEHB6:
	call	_Unwind_Resume
.LEHE6:
.L102:
	lw	ra,28(sp)
	.cfi_restore 1
	lw	s0,24(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	lw	s1,20(sp)
	.cfi_restore 9
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE1857:
	.section	.gcc_except_table._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_,"awG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5IS3_EEjcRKS3_,comdat
.LLSDA1857:
	.byte	0xff
	.byte	0xff
	.byte	0x3
	.byte	0x1a
	.4byte	.LEHB5-.LFB1857
	.4byte	.LEHE5-.LEHB5
	.4byte	.L101-.LFB1857
	.byte	0
	.4byte	.LEHB6-.LFB1857
	.4byte	.LEHE6-.LEHB6
	.4byte	0
	.byte	0
	.section	.text._ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_,"axG",@progbits,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC5IS3_EEjcRKS3_,comdat
	.size	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_, .-_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_
	.weak	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEjcRKS3_
	.set	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1IS3_EEjcRKS3_,_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2IS3_EEjcRKS3_
	.section	.text._ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_,"axG",@progbits,_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_,comdat
	.align	2
	.weak	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_
	.type	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_, @function
_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_:
.LFB2005:
	.cfi_startproc
	addi	sp,sp,-48
	.cfi_def_cfa_offset 48
	sw	ra,44(sp)
	sw	s0,40(sp)
	sw	s1,36(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	.cfi_offset 9, -12
	addi	s0,sp,48
	.cfi_def_cfa 8, 0
	sw	a0,-36(s0)
	sw	a1,-40(s0)
	sw	a2,-44(s0)
	sb	zero,-17(s0)
	li	a5,1
	sb	a5,-17(s0)
	lbu	a5,-17(s0)
	beq	a5,zero,.L104
	lw	a0,-40(s0)
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	mv	s1,a0
	lw	a0,-44(s0)
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE4sizeEv
	mv	a5,a0
	add	a5,s1,a5
	sw	a5,-24(s0)
	lw	a0,-40(s0)
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv
	mv	a4,a0
	lw	a5,-24(s0)
	bleu	a5,a4,.L105
	lw	a0,-44(s0)
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE8capacityEv
	mv	a4,a0
	lw	a5,-24(s0)
	bgtu	a5,a4,.L105
	li	a5,1
	j	.L106
.L105:
	li	a5,0
.L106:
	beq	a5,zero,.L104
	lw	a2,-40(s0)
	li	a1,0
	lw	a0,-44(s0)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6insertEjRKS4_
	mv	a5,a0
	mv	a0,a5
	call	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	mv	a5,a0
	mv	a1,a5
	lw	a0,-36(s0)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_
	j	.L107
.L104:
	lw	a1,-44(s0)
	lw	a0,-40(s0)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE6appendERKS4_
	mv	a5,a0
	mv	a0,a5
	call	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	mv	a5,a0
	mv	a1,a5
	lw	a0,-36(s0)
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EOS4_
.L107:
	lw	a0,-36(s0)
	lw	ra,44(sp)
	.cfi_restore 1
	lw	s0,40(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 48
	lw	s1,36(sp)
	.cfi_restore 9
	addi	sp,sp,48
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE2005:
	.size	_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_, .-_ZStplIcSt11char_traitsIcESaIcEENSt7__cxx1112basic_stringIT_T0_T1_EEOS8_S9_
	.section	.text._ZSt3minIiERKT_S2_S2_,"axG",@progbits,_ZSt3minIiERKT_S2_S2_,comdat
	.align	2
	.weak	_ZSt3minIiERKT_S2_S2_
	.type	_ZSt3minIiERKT_S2_S2_, @function
_ZSt3minIiERKT_S2_S2_:
.LFB2013:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	s0,28(sp)
	.cfi_offset 8, -4
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	sw	a0,-20(s0)
	sw	a1,-24(s0)
	lw	a5,-24(s0)
	lw	a4,0(a5)
	lw	a5,-20(s0)
	lw	a5,0(a5)
	bge	a4,a5,.L109
	lw	a5,-24(s0)
	j	.L110
.L109:
	lw	a5,-20(s0)
.L110:
	mv	a0,a5
	lw	s0,28(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE2013:
	.size	_ZSt3minIiERKT_S2_S2_, .-_ZSt3minIiERKT_S2_S2_
	.section	.text._ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_,"axG",@progbits,_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_,comdat
	.align	2
	.weak	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	.type	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_, @function
_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_:
.LFB2115:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	s0,28(sp)
	.cfi_offset 8, -4
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	sw	a0,-20(s0)
	lw	a5,-20(s0)
	mv	a0,a5
	lw	s0,28(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE2115:
	.size	_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_, .-_ZSt4moveIRNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEEONSt16remove_referenceIT_E4typeEOS8_
	.section	.text._Z41__static_initialization_and_destruction_0ii,"ax",@progbits
	.align	2
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2274:
	.cfi_startproc
	addi	sp,sp,-32
	.cfi_def_cfa_offset 32
	sw	ra,28(sp)
	sw	s0,24(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,32
	.cfi_def_cfa 8, 0
	sw	a0,-20(s0)
	sw	a1,-24(s0)
	lw	a4,-20(s0)
	li	a5,1
	bne	a4,a5,.L115
	lw	a4,-24(s0)
	li	a5,65536
	addi	a5,a5,-1
	bne	a4,a5,.L115
	lui	a5,%hi(_ZStL8__ioinit)
	addi	a0,a5,%lo(_ZStL8__ioinit)
	call	_ZNSt8ios_base4InitC1Ev
	lui	a5,%hi(__dso_handle)
	addi	a2,a5,%lo(__dso_handle)
	lui	a5,%hi(_ZStL8__ioinit)
	addi	a1,a5,%lo(_ZStL8__ioinit)
	lui	a5,%hi(_ZNSt8ios_base4InitD1Ev)
	addi	a0,a5,%lo(_ZNSt8ios_base4InitD1Ev)
	call	__cxa_atexit
.L115:
	nop
	lw	ra,28(sp)
	.cfi_restore 1
	lw	s0,24(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 32
	addi	sp,sp,32
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE2274:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.section	.text._GLOBAL__sub_I_s,"ax",@progbits
	.align	2
	.type	_GLOBAL__sub_I_s, @function
_GLOBAL__sub_I_s:
.LFB2275:
	.cfi_startproc
	addi	sp,sp,-16
	.cfi_def_cfa_offset 16
	sw	ra,12(sp)
	sw	s0,8(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,16
	.cfi_def_cfa 8, 0
	li	a5,65536
	addi	a1,a5,-1
	li	a0,1
	call	_Z41__static_initialization_and_destruction_0ii
	lw	ra,12(sp)
	.cfi_restore 1
	lw	s0,8(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 16
	addi	sp,sp,16
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE2275:
	.size	_GLOBAL__sub_I_s, .-_GLOBAL__sub_I_s
	.section	.init_array,"aw"
	.align	2
	.word	_GLOBAL__sub_I_s
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.sdata.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align	2
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 4
DW.ref.__gxx_personality_v0:
	.word	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (g2ee5e430018) 12.2.0"
