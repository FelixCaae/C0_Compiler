	j main
printhelloworld:
	subi $sp,$sp,44
	sw $s0,8($sp)
	sw $s1,12($sp)
	sw $s2,16($sp)
	sw $ra,40($sp)
	li $t0,233
	addi $t1,$sp,0
	sw $t0,0($t1)
	li $v0,4
	la $a0,Str_0
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
	li $v0,4
	la $a0,Str_2
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $a0,43
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $a0,45
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $a0,42
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $a0,47
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $a0,95
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $a0,10
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $a0,$sp,0
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j printhelloworld_end
printhelloworld_end:
	lw $s0,8($sp)
	lw $s1,12($sp)
	lw $s2,16($sp)
	lw $ra,40($sp)
	addi $sp,$sp,44
	jr $ra
squaresum:
	subi $sp,$sp,88
	sw $s0,52($sp)
	sw $s1,56($sp)
	sw $s2,60($sp)
	sw $ra,84($sp)
	addi $s0,$sp,0
	sw $a0,0($s0)
	addi $s0,$sp,4
	sw $a1,0($s0)
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,-1
	mul $t0,$t0,$t1
	addi $t1,$sp,12
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,12
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,16
	sw $t0,0($t1)
	addi $t0,$sp,16
	lw $t0,0($t0)
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,0
	mul $t0,$t0,$t1
	addi $t1,$sp,20
	sw $t0,0($t1)
	addi $t0,$sp,20
	lw $t0,0($t0)
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $t0,$sp,0
	lw $t0,0($t0)
	li $t1,0
	mul $t0,$t0,$t1
	addi $t1,$sp,24
	sw $t0,0($t1)
	addi $t0,$sp,24
	lw $t0,0($t0)
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $t0,$sp,0
	lw $t0,0($t0)
	addi $t1,$sp,0
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,28
	sw $t0,0($t1)
	addi $t0,$sp,28
	lw $t0,0($t0)
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $t0,$sp,0
	lw $t0,0($t0)
	addi $t1,$sp,0
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,32
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,32
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,36
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,36
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,40
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	addi $t1,$sp,4
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,44
	sw $t0,0($t1)
	addi $t0,$sp,40
	lw $t0,0($t0)
	addi $t1,$sp,44
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,40
	sw $t0,0($t1)
	addi $t0,$sp,40
	lw $t0,0($t0)
	addi $t1,$sp,8
	sw $t0,0($t1)
	addi $v0,$sp,8
	lw $v0,0($v0)
	j squaresum_end
squaresum_end:
	lw $s0,52($sp)
	lw $s1,56($sp)
	lw $s2,60($sp)
	lw $ra,84($sp)
	addi $sp,$sp,88
	jr $ra
_mystop:
	subi $sp,$sp,40
	sw $s0,4($sp)
	sw $s1,8($sp)
	sw $s2,12($sp)
	sw $ra,36($sp)
	li $v0,4
	la $a0,Str_3
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $v0,12
	syscall
	addi $t0,$sp,0
	sb $v0,0($t0)
_mystop_end:
	lw $s0,4($sp)
	lw $s1,8($sp)
	lw $s2,12($sp)
	lw $ra,36($sp)
	addi $sp,$sp,40
	jr $ra
nsquaresum:
	subi $sp,$sp,104
	sw $s0,68($sp)
	sw $s1,72($sp)
	sw $s2,76($sp)
	sw $ra,100($sp)
	addi $s0,$sp,0
	sw $a0,0($s0)
	addi $s0,$sp,4
	sw $a1,0($s0)
	addi $t0,$sp,0
	lw $t0,0($t0)
	addi $t1,$sp,48
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	seq $v1,$t0,$t1
	beq $0,$v1,if_1
	addi $v0,$sp,0
	lw $v0,0($v0)
	j nsquaresum_end
if_1:
	addi $a0,$sp,0
	lw $a0,0($a0)
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,52
	sw $t0,0($t1)
	addi $a1,$sp,52
	lw $a1,0($a1)
	jal nsquaresum
	addi $t0,$sp,56
	sw $v0,0($t0)
	addi $t0,$sp,48
	lw $t0,0($t0)
	addi $t1,$sp,56
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,60
	sw $t0,0($t1)
	addi $t0,$sp,60
	lw $t0,0($t0)
	addi $t1,$sp,48
	sw $t0,0($t1)
	addi $v0,$sp,48
	lw $v0,0($v0)
	j nsquaresum_end
nsquaresum_end:
	lw $s0,68($sp)
	lw $s1,72($sp)
	lw $s2,76($sp)
	lw $ra,100($sp)
	addi $sp,$sp,104
	jr $ra
nextalphabet:
	subi $sp,$sp,44
	sw $s0,8($sp)
	sw $s1,12($sp)
	sw $s2,16($sp)
	sw $ra,40($sp)
	addi $s0,$sp,4
	sb $a0,0($s0)
	addi $t0,$sp,4
	lb $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,0
	sw $t0,0($t1)
	addi $v0,$sp,0
	lw $v0,0($v0)
	j nextalphabet_end
nextalphabet_end:
	lw $s0,8($sp)
	lw $s1,12($sp)
	lw $s2,16($sp)
	lw $ra,40($sp)
	addi $sp,$sp,44
	jr $ra
main:
	subi $sp,$sp,152
	li $v0,4
	la $a0,Str_4
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $a0,2147483647
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
	li $a0,-2147483647
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	jal printhelloworld
	li $v0,4
	la $a0,Str_6
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $v0,5
	syscall
	addi $t0,$sp,0
	sw $v0,0($t0)
	li $t0,0
	addi $t1,$sp,16
	sw $t0,0($t1)
	li $t0,666
	la $t1,_a
	sw $t0,0($t1)
	li $t0,0
	li $t1,20
	sub $t0,$t0,$t1
	addi $t1,$sp,28
	sw $t0,0($t1)
	addi $t0,$sp,28
	lw $t0,0($t0)
	li $t1,0
	addi $t2,$sp,12
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t1,0
	addi $t0,$sp,12
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,32
	sw $t0,0($t1)
	addi $a0,$sp,32
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t0,97
	li $t1,0
	addi $t2,$sp,108
	sll $t1,$t1,0
	add $t2,$t2,$t1
	sb $t0,0($t2)
	li $t0,98
	li $t1,1
	addi $t2,$sp,108
	sll $t1,$t1,0
	add $t2,$t2,$t1
	sb $t0,0($t2)
	li $t0,99
	li $t1,2
	addi $t2,$sp,108
	sll $t1,$t1,0
	add $t2,$t2,$t1
	sb $t0,0($t2)
	li $t1,0
	addi $t0,$sp,108
	sll $t1,$t1,0
	add $t0,$t0,$t1
	lb $t0,0($t0)
	addi $t1,$sp,111
	sb $t0,0($t1)
	addi $a0,$sp,111
	lb $a0,0($a0)
	jal nextalphabet
	addi $t0,$sp,112
	sb $v0,0($t0)
	addi $a0,$sp,112
	lb $a0,0($a0)
	li $v0,11
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t1,0
	addi $t0,$sp,12
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,36
	sw $t0,0($t1)
	la $t0,_a
	lw $t0,0($t0)
	addi $t1,$sp,36
	lw $t1,0($t1)
	sgt $v1,$t0,$t1
	beq $0,$v1,if_2
	li $t1,0
	addi $t0,$sp,12
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,40
	sw $t0,0($t1)
	addi $t0,$sp,40
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,44
	sw $t0,0($t1)
	addi $t0,$sp,44
	lw $t0,0($t0)
	la $t1,_a
	sw $t0,0($t1)
if_2:
	li $v0,4
	la $a0,Str_7
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $a0,_a
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t1,0
	addi $t0,$sp,12
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,48
	sw $t0,0($t1)
	la $t0,_a
	lw $t0,0($t0)
	addi $t1,$sp,48
	lw $t1,0($t1)
	slt $v1,$t0,$t1
	beq $0,$v1,if_3
	li $t0,2
	la $t1,_a
	sw $t0,0($t1)
if_3:
	li $v0,4
	la $a0,Str_7
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $a0,_a
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $t0,_a
	lw $t0,0($t0)
	li $t1,2
	seq $v1,$t0,$t1
	beq $0,$v1,if_4
	li $t1,0
	addi $t0,$sp,12
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,52
	sw $t0,0($t1)
	addi $t0,$sp,52
	lw $t0,0($t0)
	li $t1,2
	mul $t0,$t0,$t1
	addi $t1,$sp,56
	sw $t0,0($t1)
	addi $t0,$sp,56
	lw $t0,0($t0)
	la $t1,_a
	sw $t0,0($t1)
if_4:
	li $v0,4
	la $a0,Str_7
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $a0,_a
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t1,0
	addi $t0,$sp,12
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,60
	sw $t0,0($t1)
	la $t0,_a
	lw $t0,0($t0)
	addi $t1,$sp,60
	lw $t1,0($t1)
	sne $v1,$t0,$t1
	beq $0,$v1,if_5
	li $t0,4
	la $t1,_a
	sw $t0,0($t1)
if_5:
	li $v0,4
	la $a0,Str_7
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $a0,_a
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $t0,_a
	lw $t0,0($t0)
	li $t1,4
	sge $v1,$t0,$t1
	beq $0,$v1,if_6
	li $t0,0
	li $t1,0
	sub $t0,$t0,$t1
	addi $t1,$sp,64
	sw $t0,0($t1)
	addi $t0,$sp,64
	lw $t0,0($t0)
	la $t1,_a
	sw $t0,0($t1)
if_6:
	li $v0,4
	la $a0,Str_7
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $a0,_a
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $t0,_a
	lw $t0,0($t0)
	li $t1,0
	sle $v1,$t0,$t1
	beq $0,$v1,if_7
	li $v0,4
	la $a0,Str_8
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $a0,_a
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t0,666
	la $t1,_a
	sw $t0,0($t1)
if_7:
	li $v0,4
	la $a0,Str_7
	syscall
	li $v0,11
	li $a0,10
	syscall
	la $a0,_a
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t0,0
	addi $t1,$sp,0
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_8_1
	li $v0,4
	la $a0,Str_9
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_8
case_8_1:
	li $t0,1
	addi $t1,$sp,0
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_8_2
	li $v0,5
	syscall
	addi $t0,$sp,4
	sw $v0,0($t0)
	li $v0,4
	la $a0,Str_10
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,10
	add $t0,$t0,$t1
	addi $t1,$sp,68
	sw $t0,0($t1)
	addi $t0,$sp,68
	lw $t0,0($t0)
	li $t1,10
	sub $t0,$t0,$t1
	addi $t1,$sp,72
	sw $t0,0($t1)
	addi $a0,$sp,72
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_8
case_8_2:
	li $t0,2
	addi $t1,$sp,0
	lw $t1,0($t1)
	seq $v1,$t0,$t1
	beq $0,$v1,case_8_3
	li $v0,5
	syscall
	addi $t0,$sp,4
	sw $v0,0($t0)
	li $v0,5
	syscall
	addi $t0,$sp,8
	sw $v0,0($t0)
	li $v0,4
	la $a0,Str_10
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $t0,$sp,4
	lw $t0,0($t0)
	li $t1,0
	add $t0,$t0,$t1
	addi $t1,$sp,76
	sw $t0,0($t1)
	addi $a0,$sp,76
	lw $a0,0($a0)
	addi $t0,$sp,8
	lw $t0,0($t0)
	li $t1,2
	sub $t0,$t0,$t1
	addi $t1,$sp,80
	sw $t0,0($t1)
	addi $t0,$sp,80
	lw $t0,0($t0)
	li $t1,2
	add $t0,$t0,$t1
	addi $t1,$sp,84
	sw $t0,0($t1)
	addi $a1,$sp,84
	lw $a1,0($a1)
	jal squaresum
	addi $t0,$sp,88
	sw $v0,0($t0)
	addi $a0,$sp,88
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j switch_8
case_8_3:
switch_8:
	jal _mystop
	li $a0,1
	li $a1,1
	jal nsquaresum
	addi $t0,$sp,92
	sw $v0,0($t0)
	addi $t0,$sp,92
	lw $t0,0($t0)
	addi $t1,$sp,16
	sw $t0,0($t1)
	li $v0,4
	la $a0,Str_1
	syscall
	li $v0,11
	li $a0,10
	syscall
	addi $t0,$sp,4
	lw $t0,0($t0)
	addi $t1,$sp,8
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,96
	sw $t0,0($t1)
	addi $t0,$sp,96
	lw $t0,0($t0)
	addi $t1,$sp,24
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	addi $t1,$sp,8
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,100
	sw $t0,0($t1)
	addi $t0,$sp,100
	lw $t0,0($t0)
	addi $t1,$sp,16
	sw $t0,0($t1)
	addi $t0,$sp,4
	lw $t0,0($t0)
	addi $t1,$sp,20
	sw $t0,0($t1)
	addi $t0,$sp,20
	lw $t0,0($t0)
	addi $t1,$sp,8
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,104
	sw $t0,0($t1)
	addi $t0,$sp,104
	lw $t0,0($t0)
	addi $t1,$sp,20
	sw $t0,0($t1)
	jal _mystop
	j main_end
main_end:
	addi $sp,$sp,152
	.data
	_ :.word 0
	_9 :.word 0
	__ :.word 0
	_a :.word 0
	a1 :.word 0
	a2 :.word 0
	a3 :.space 40
	a4 :.space 4
	a5 :.word 0
	___a :.byte 0
	aa2 :.space 1
	aa3 :.space 20
	aa4 :.byte 0
	Str_0 :.asciiz " !#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
	Str_1 :.asciiz ""
	Str_2 :.asciiz "helloworld!"
	Str_3 :.asciiz "input a char and enter:"
	Str_4 :.asciiz "MaxInt"
	Str_5 :.asciiz "MinInt"
	Str_6 :.asciiz "please input number counts:"
	Str_7 :.asciiz "_a is"
	Str_8 :.asciiz "if ok....perhaps"
	Str_9 :.asciiz "result:0"
	Str_10 :.asciiz "result:"
