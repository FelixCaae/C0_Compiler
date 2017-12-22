	j main
emptyfunc:
	subi $sp,$sp,40
	sw $s0,4($sp)
	sw $s1,8($sp)
	sw $s2,12($sp)
	sw $ra,36($sp)
emptyfunc_end:
	lw $s0,4($sp)
	lw $s1,8($sp)
	lw $s2,12($sp)
	lw $ra,36($sp)
	addi $sp,$sp,40
	jr $ra
emptyfunc2:
	subi $sp,$sp,40
	sw $s0,4($sp)
	sw $s1,8($sp)
	sw $s2,12($sp)
	sw $ra,36($sp)
emptyfunc2_end:
	lw $s0,4($sp)
	lw $s1,8($sp)
	lw $s2,12($sp)
	lw $ra,36($sp)
	addi $sp,$sp,40
	jr $ra
testchar:
	subi $sp,$sp,40
	sw $s0,4($sp)
	sw $s1,8($sp)
	sw $s2,12($sp)
	sw $ra,36($sp)
	li $v0,48
	j testchar_end
testchar_end:
	lw $s0,4($sp)
	lw $s1,8($sp)
	lw $s2,12($sp)
	lw $ra,36($sp)
	addi $sp,$sp,40
	jr $ra
fibonacci:
	subi $sp,$sp,68
	sw $s0,32($sp)
	sw $s1,36($sp)
	sw $s2,40($sp)
	sw $ra,64($sp)
	addi $s0,$sp,0
	sw $a0,0($s0)
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,1
	seq $v1,$t0,$t1
	beq $0,$v1,if_1
	li $v0,1
	j fibonacci_end
if_1:
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,2
	sne $v1,$t0,$t1
	beq $0,$v1,if_2
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,-1
	add $t0,$t0,$t1
	addi $t1,$sp,4
	sw $t0,0($t1)
	addi $a0,$sp,4
	lw $a0,0($a0)
	jal fibonacci
	addi $t0,$sp,8
	sw $v0,0($t0)
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,2
	sub $t0,$t0,$t1
	addi $t1,$sp,12
	sw $t0,0($t1)
	addi $a0,$sp,12
	lw $a0,0($a0)
	jal fibonacci
	addi $t0,$sp,16
	sw $v0,0($t0)
	addi $t0,$sp,8
	lw $t0,0($t0)
	addi $t1,$sp,16
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,20
	sw $t0,0($t1)
	addi $t0,$sp,20
	lw $t0,0($t0)
	li $t1,0
	add $t0,$t0,$t1
	addi $t1,$sp,24
	sw $t0,0($t1)
	addi $v0,$sp,24
	lw $v0,0($v0)
	j fibonacci_end
if_2:
	li $v0,1
	j fibonacci_end
fibonacci_end:
	lw $s0,32($sp)
	lw $s1,36($sp)
	lw $s2,40($sp)
	lw $ra,64($sp)
	addi $sp,$sp,68
	jr $ra
move:
	subi $sp,$sp,40
	sw $s0,4($sp)
	sw $s1,8($sp)
	sw $s2,12($sp)
	sw $ra,36($sp)
	addi $s0,$sp,0
	sb $a0,0($s0)
	addi $s0,$sp,1
	sb $a1,0($s0)
	li $v0,4
	la $a0,Str_0
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,0
	lb $a0,0($a0)
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $v0,4
	la $a0,Str_1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,1
	lb $a0,0($a0)
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $v0,4
	la $a0,Str_2
	syscall
	li $v0,11
	li $a0,10
	syscall
move_end:
	lw $s0,4($sp)
	lw $s1,8($sp)
	lw $s2,12($sp)
	lw $ra,36($sp)
	addi $sp,$sp,40
	jr $ra
hanoi:
	subi $sp,$sp,52
	sw $s0,16($sp)
	sw $s1,20($sp)
	sw $s2,24($sp)
	sw $ra,48($sp)
	addi $s0,$sp,0
	sw $a0,0($s0)
	addi $s0,$sp,12
	sb $a1,0($s0)
	addi $s0,$sp,13
	sb $a2,0($s0)
	addi $s0,$sp,14
	sb $a3,0($s0)
	li $t0,2
	addi $t1,$sp,0
	lw $t1,0($t1)
	sgt $v1,$t0,$t1
	beq $0,$v1,if_3
	addi $a0,$sp,12
	lb $a0,0($a0)
	addi $a1,$sp,14
	lb $a1,0($a1)
	jal move
	j hanoi_end
	li $v0,4
	la $a0,Str_3
	syscall
	li $v0,11
	li $a0,10
	syscall
if_3:
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,4
	sw $t0,0($t1)
	addi $a0,$sp,4
	lw $a0,0($a0)
	addi $a1,$sp,12
	lb $a1,0($a1)
	addi $a2,$sp,14
	lb $a2,0($a2)
	addi $a3,$sp,13
	lb $a3,0($a3)
	jal hanoi
	addi $a0,$sp,12
	lb $a0,0($a0)
	addi $a1,$sp,14
	lb $a1,0($a1)
	jal move
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $a0,$sp,8
	lw $a0,0($a0)
	addi $a1,$sp,13
	lb $a1,0($a1)
	addi $a2,$sp,12
	lb $a2,0($a2)
	addi $a3,$sp,14
	lb $a3,0($a3)
	jal hanoi
hanoi_end:
	lw $s0,16($sp)
	lw $s1,20($sp)
	lw $s2,24($sp)
	lw $ra,48($sp)
	addi $sp,$sp,52
	jr $ra
getpower:
	subi $sp,$sp,76
	sw $s0,40($sp)
	sw $s1,44($sp)
	sw $s2,48($sp)
	sw $ra,72($sp)
	addi $s0,$sp,0
	sw $a0,0($s0)
	addi $s0,$sp,4
	sw $a1,0($s0)
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,2
	sge $v1,$t0,$t1
	beq $0,$v1,if_4
	addi $a0,$sp,0
	lw $a0,0($a0)
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,12
	sw $t0,0($t1)
	addi $a1,$sp,12
	lw $a1,0($a1)
	jal getpower
	addi $t0,$sp,16
	sw $v0,0($t0)
	addi $t0,$sp,16
	lw $t0,0($t0)
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,20
	sw $t0,0($t1)
	addi $t0,$sp,8
	lw $t0,0($t0)
	addi $t1,$sp,0
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,24
	sw $t0,0($t1)
	addi $t0,$sp,24
	lw $t0,0($t0)
	addi $t1,$sp,20
	lw $t1,0($t1)
	la $t2,a
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	addi $t0,$sp,0
	lw $t0,0($t0)
	addi $t1,$sp,8
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,28
	sw $t0,0($t1)
	addi $v0,$sp,28
	lw $v0,0($v0)
	j getpower_end
if_4:
	li $t0,1
	addi $t1,$sp,4
	lw $t1,0($t1)
	sle $v1,$t0,$t1
	beq $0,$v1,if_5
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,32
	sw $t0,0($t1)
	addi $t0,$sp,0
	lw $t0,0($t0)
	addi $t1,$sp,32
	lw $t1,0($t1)
	la $t2,a
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	addi $v0,$sp,0
	lw $v0,0($v0)
	j getpower_end
if_5:
getpower_end:
	lw $s0,40($sp)
	lw $s1,44($sp)
	lw $s2,48($sp)
	lw $ra,72($sp)
	addi $sp,$sp,76
	jr $ra
getsqr:
	subi $sp,$sp,84
	sw $s0,48($sp)
	sw $s1,52($sp)
	sw $s2,56($sp)
	sw $ra,80($sp)
	addi $s0,$sp,0
	sw $a0,0($s0)
	li $t0,1
	addi $t1,$sp,4
	sw $t0,0($t1)
do_6:
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $t0,$sp,8
	lw $t0,0($t0)
	addi $t1,$sp,4
	sw $t0,0($t1)
	addi $t0,$sp,0
	lw $t0,0($t0)
	addi $t1,$sp,4
	lw $t1,0($t1)
	div $t0,$t0,$t1
	addi $t1,$sp,12
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	addi $t1,$sp,12
	lw $t1,0($t1)
	slt $v1,$t0,$t1
	bne $0,$v1,do_6
	li $t0,0
	addi $t1,$sp,0
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,16
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	addi $t1,$sp,4
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,20
	sw $t0,0($t1)
	addi $t0,$sp,16
	lw $t0,0($t0)
	addi $t1,$sp,20
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,16
	sw $t0,0($t1)
	li $t0,0
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,24
	sw $t0,0($t1)
	addi $t0,$sp,24
	lw $t0,0($t0)
	addi $t1,$sp,4
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,24
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,28
	sw $t0,0($t1)
	addi $t0,$sp,24
	lw $t0,0($t0)
	addi $t1,$sp,28
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,32
	sw $t0,0($t1)
	addi $t0,$sp,0
	lw $t0,0($t0)
	addi $t1,$sp,32
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,36
	sw $t0,0($t1)
	addi $t0,$sp,16
	lw $t0,0($t0)
	addi $t1,$sp,36
	lw $t1,0($t1)
	slt $v1,$t0,$t1
	beq $0,$v1,if_7
	addi $v0,$sp,4
	lw $v0,0($v0)
	j getsqr_end
if_7:
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,40
	sw $t0,0($t1)
	addi $v0,$sp,40
	lw $v0,0($v0)
	j getsqr_end
getsqr_end:
	lw $s0,48($sp)
	lw $s1,52($sp)
	lw $s2,56($sp)
	lw $ra,80($sp)
	addi $sp,$sp,84
	jr $ra
main:
	subi $sp,$sp,612
	li $t0,123456789
	addi $t1,$sp,468
	sw $t0,0($t1)
	li $t0,65
	addi $t1,$sp,464
	sw $t0,0($t1)
	li $t0,5
	li $t1,0
	addi $t2,$sp,64
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t1,0
	addi $t0,$sp,64
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,504
	sw $t0,0($t1)
	li $t0,1
	addi $t1,$sp,504
	lw $t1,0($t1)
	addi $t2,$sp,64
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,2
	li $t1,43
	addi $t2,$sp,64
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $v0,5
	syscall
	addi $t0,$sp,4
	sw $v0,0($t0)
	li $v0,5
	syscall
	addi $t0,$sp,8
	sw $v0,0($t0)
	li $t0,1
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_8_1
	addi $a0,$sp,8
	lw $a0,0($a0)
	li $a1,10
	jal getpower
	li $t0,0
	addi $t1,$sp,12
	sw $t0,0($t1)
do_9:
	li $v0,4
	la $a0,Str_4
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $t0,$sp,12
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,508
	sw $t0,0($t1)
	addi $a0,$sp,508
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $v0,4
	la $a0,Str_5
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $t1,$sp,12
	lw $t1,0($t1)
	la $t0,a
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,512
	sw $t0,0($t1)
	addi $a0,$sp,512
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $v0,4
	la $a0,Str_2
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $v0,4
	la $a0,Str_6
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $t0,$sp,12
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,516
	sw $t0,0($t1)
	addi $t0,$sp,516
	lw $t0,0($t0)
	addi $t1,$sp,12
	sw $t0,0($t1)
	addi $t0,$sp,12
	lw $t0,0($t0)
	li $t1,10
	slt $v1,$t0,$t1
	bne $0,$v1,do_9
	j switch_8
case_8_1:
switch_8:
	li $t0,2
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_10_1
	addi $a0,$sp,8
	lw $a0,0($a0)
	li $a1,65
	li $a2,66
	li $a3,67
	jal hanoi
	j switch_10
case_10_1:
	li $t0,3
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_10_2
	addi $a0,$sp,8
	lw $a0,0($a0)
	jal fibonacci
	addi $t0,$sp,520
	sw $v0,0($t0)
	addi $t0,$sp,520
	lw $t0,0($t0)
	addi $t1,$sp,16
	sw $t0,0($t1)
	addi $a0,$sp,16
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_10
case_10_2:
switch_10:
	li $t0,4
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_11_1
	addi $a0,$sp,8
	lw $a0,0($a0)
	jal getsqr
	addi $t0,$sp,524
	sw $v0,0($t0)
	addi $t0,$sp,524
	lw $t0,0($t0)
	addi $t1,$sp,60
	sw $t0,0($t1)
	addi $a0,$sp,60
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_11
case_11_1:
	li $t0,5
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_11_2
	jal testchar
	addi $t0,$sp,574
	sb $v0,0($t0)
	addi $a0,$sp,574
	lb $a0,0($a0)
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t0,3
	li $t1,2
	mul $t0,$t0,$t1
	addi $t1,$sp,528
	sw $t0,0($t1)
	addi $t0,$sp,528
	lw $t0,0($t0)
	li $t1,6
	div $t0,$t0,$t1
	addi $t1,$sp,532
	sw $t0,0($t1)
	li $t1,0
	addi $t0,$sp,64
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,536
	sw $t0,0($t1)
	addi $t0,$sp,532
	lw $t0,0($t0)
	addi $t1,$sp,536
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,540
	sw $t0,0($t1)
	addi $a0,$sp,540
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_11
case_11_2:
	li $t0,6
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_11_3
	li $t1,0
	addi $t0,$sp,64
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,544
	sw $t0,0($t1)
	addi $t0,$sp,544
	lw $t0,0($t0)
	li $t1,0
	sne $v1,$t0,$t1
	beq $0,$v1,if_12
	li $v0,4
	la $a0,Str_7
	syscall
	li $v0,11
	li $a0,10
	syscall
if_12:
	li $t0,0
	addi $t1,$sp,0
	sw $t0,0($t1)
do_13:
	li $t1,0
	addi $t0,$sp,64
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,548
	sw $t0,0($t1)
	addi $a0,$sp,548
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t1,0
	addi $t0,$sp,64
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,552
	sw $t0,0($t1)
	addi $t0,$sp,552
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,556
	sw $t0,0($t1)
	addi $t0,$sp,556
	lw $t0,0($t0)
	li $t1,0
	addi $t2,$sp,64
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,560
	sw $t0,0($t1)
	addi $t0,$sp,560
	lw $t0,0($t0)
	addi $t1,$sp,0
	sw $t0,0($t1)
	li $t1,0
	addi $t0,$sp,64
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,564
	sw $t0,0($t1)
	addi $t0,$sp,564
	lw $t0,0($t0)
	li $t1,0
	sne $v1,$t0,$t1
	bne $0,$v1,do_13
	j switch_11
case_11_3:
	li $t0,-7
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_13_4
	li $v0,5
	syscall
	addi $t0,$sp,480
	sw $v0,0($t0)
	li $v0,5
	syscall
	addi $t0,$sp,484
	sw $v0,0($t0)
	li $v0,5
	syscall
	addi $t0,$sp,488
	sw $v0,0($t0)
	li $v0,5
	syscall
	addi $t0,$sp,492
	sw $v0,0($t0)
	li $v0,5
	syscall
	addi $t0,$sp,496
	sw $v0,0($t0)
	li $v0,5
	syscall
	addi $t0,$sp,500
	sw $v0,0($t0)
	addi $a0,$sp,480
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,484
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,488
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,492
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,496
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,500
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_11
case_13_4:
	li $t0,0
	addi $t1,$sp,4
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_13_5
	li $v0,12
	syscall
	addi $t0,$sp,568
	sb $v0,0($t0)
	li $t0,97
	addi $t1,$sp,568
	lb $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_14_1
	li $a0,1
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_14
case_14_1:
	li $t0,98
	addi $t1,$sp,568
	lb $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_14_2
	li $a0,2
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_14
case_14_2:
switch_14:
	j switch_11
case_13_5:
switch_11:
	j main_end
main_end:
	addi $sp,$sp,612
	.data
	a :.space 40
	c :.word 0
	Str_0 :.asciiz "MOVE"
	Str_1 :.asciiz " TO "
	Str_2 :.asciiz " "
	Str_3 :.asciiz "RETURN ERROR"
	Str_4 :.asciiz "NO"
	Str_5 :.asciiz ":"
	Str_6 :.asciiz ""
	Str_7 :.asciiz "IFCORRECT"
