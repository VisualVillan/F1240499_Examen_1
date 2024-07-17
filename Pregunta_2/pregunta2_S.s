	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"pregunta2.c"
	.text
	.global	__aeabi_idivmod
	.section	.rodata
	.align	2
.LC0:
	.ascii	"%i - Deficiente\012\000"
	.align	2
.LC1:
	.ascii	"%i - Perfecto\012\000"
	.align	2
.LC2:
	.ascii	"%i - Abundante\012\000"
	.text
	.align	2
	.global	analiza_num
	.arch armv4t
	.syntax unified
	.arm
	.fpu softvfp
	.type	analiza_num, %function
analiza_num:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #24
	str	r0, [fp, #-24]
	mov	r3, #0
	str	r3, [fp, #-8]
	mov	r3, #1
	str	r3, [fp, #-12]
	b	.L2
.L4:
	ldr	r3, [fp, #-24]
	ldr	r1, [fp, #-12]
	mov	r0, r3
	bl	__aeabi_idivmod
	mov	r3, r1
	cmp	r3, #0
	bne	.L3
	ldr	r3, [fp, #-12]
	str	r3, [fp, #-16]
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-16]
	add	r3, r2, r3
	str	r3, [fp, #-8]
.L3:
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L2:
	ldr	r2, [fp, #-12]
	ldr	r3, [fp, #-24]
	cmp	r2, r3
	blt	.L4
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-24]
	cmp	r2, r3
	bge	.L5
	ldr	r1, [fp, #-24]
	ldr	r0, .L9
	bl	printf
	b	.L8
.L5:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-24]
	cmp	r2, r3
	bne	.L7
	ldr	r1, [fp, #-24]
	ldr	r0, .L9+4
	bl	printf
	b	.L8
.L7:
	ldr	r1, [fp, #-24]
	ldr	r0, .L9+8
	bl	printf
.L8:
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	bx	lr
.L10:
	.align	2
.L9:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.size	analiza_num, .-analiza_num
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ Function supports interworking.
	@ args = 0, pretend = 0, frame = 16
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, fp, lr}
	add	fp, sp, #8
	sub	sp, sp, #20
	mov	r3, sp
	mov	r4, r3
	mov	r0, #0
	bl	time
	mov	r2, r0
	mov	r3, r1
	mov	r3, r2
	mov	r0, r3
	bl	srand
	mov	r3, #15
	str	r3, [fp, #-20]
	ldr	ip, [fp, #-20]
	sub	r3, ip, #1
	str	r3, [fp, #-24]
	mov	r3, ip
	mov	r0, r3
	mov	r1, #0
	mov	r2, #0
	mov	r3, #0
	lsl	r3, r1, #5
	orr	r3, r3, r0, lsr #27
	lsl	r2, r0, #5
	mov	r3, ip
	mov	r0, r3
	mov	r1, #0
	mov	r2, #0
	mov	r3, #0
	lsl	r3, r1, #5
	orr	r3, r3, r0, lsr #27
	lsl	r2, r0, #5
	mov	r3, ip
	lsl	r3, r3, #2
	add	r3, r3, #7
	lsr	r3, r3, #3
	lsl	r3, r3, #3
	sub	sp, sp, r3
	mov	r3, sp
	add	r3, r3, #3
	lsr	r3, r3, #2
	lsl	r3, r3, #2
	str	r3, [fp, #-28]
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L12
.L13:
	bl	rand
	mov	r1, r0
	ldr	r3, .L15
	smull	r2, r3, r1, r3
	asr	r2, r3, #5
	asr	r3, r1, #31
	sub	r2, r2, r3
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r2, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #2
	sub	r2, r1, r3
	ldr	r3, [fp, #-28]
	ldr	r1, [fp, #-16]
	str	r2, [r3, r1, lsl #2]
	ldr	r3, [fp, #-28]
	ldr	r2, [fp, #-16]
	ldr	r3, [r3, r2, lsl #2]
	mov	r0, r3
	bl	analiza_num
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L12:
	ldr	r2, [fp, #-16]
	ldr	r3, [fp, #-20]
	cmp	r2, r3
	blt	.L13
	mov	r3, #0
	mov	sp, r4
	mov	r0, r3
	sub	sp, fp, #8
	@ sp needed
	pop	{r4, fp, lr}
	bx	lr
.L16:
	.align	2
.L15:
	.word	1374389535
	.size	main, .-main
	.ident	"GCC: (15:9-2019-q4-0ubuntu1) 9.2.1 20191025 (release) [ARM/arm-9-branch revision 277599]"
