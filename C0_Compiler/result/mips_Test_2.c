	j main
get:
	subi $sp,$sp,44
	sw $s0,8($sp)
	sw $s1,12($sp)
	sw $s2,16($sp)
	sw $ra,40($sp)
	addi $s0,$sp,0
	sw $a0,0($s0)
get_end:
	lw $s0,8($sp)
	lw $s1,12($sp)
	lw $s2,16($sp)
	lw $ra,40($sp)
	addi $sp,$sp,44
	jr $ra
main:
	subi $sp,$sp,1612
	li $t0,1
	li $t1,0
	addi $t2,$sp,1200
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,2
	li $t1,1
	addi $t2,$sp,1232
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,3
	li $t1,2
	addi $t2,$sp,1200
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,4
	li $t1,3
	addi $t2,$sp,1232
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,5
	li $t1,4
	addi $t2,$sp,1200
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,6
	li $t1,5
	addi $t2,$sp,1232
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,1
	li $t1,0
	addi $t2,$sp,0
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t0,299
	li $t1,299
	addi $t2,$sp,0
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t1,0
	addi $t0,$sp,0
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1276
	sw $t0,0($t1)
	addi $a0,$sp,1276
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t1,299
	addi $t0,$sp,0
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1280
	sw $t0,0($t1)
	addi $a0,$sp,1280
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t1,0
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1284
	sw $t0,0($t1)
	addi $t1,$sp,1284
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1288
	sw $t0,0($t1)
	addi $t1,$sp,1288
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1292
	sw $t0,0($t1)
	addi $t1,$sp,1292
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1296
	sw $t0,0($t1)
	addi $t1,$sp,1296
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1300
	sw $t0,0($t1)
	addi $t1,$sp,1300
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1304
	sw $t0,0($t1)
	li $t0,7
	addi $t1,$sp,1304
	lw $t1,0($t1)
	addi $t2,$sp,1200
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t1,6
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1308
	sw $t0,0($t1)
	addi $a0,$sp,1308
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t1,0
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1312
	sw $t0,0($t1)
	addi $t1,$sp,1312
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1316
	sw $t0,0($t1)
	addi $t1,$sp,1316
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1320
	sw $t0,0($t1)
	addi $t1,$sp,1320
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1324
	sw $t0,0($t1)
	addi $t1,$sp,1324
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1328
	sw $t0,0($t1)
	addi $t1,$sp,1328
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1332
	sw $t0,0($t1)
	addi $t1,$sp,1332
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1336
	sw $t0,0($t1)
	li $t1,0
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1340
	sw $t0,0($t1)
	addi $t1,$sp,1340
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1344
	sw $t0,0($t1)
	addi $t1,$sp,1344
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1348
	sw $t0,0($t1)
	addi $t1,$sp,1348
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1352
	sw $t0,0($t1)
	addi $t1,$sp,1352
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1356
	sw $t0,0($t1)
	addi $t1,$sp,1356
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1360
	sw $t0,0($t1)
	addi $t1,$sp,1360
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1364
	sw $t0,0($t1)
	li $t1,0
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1368
	sw $t0,0($t1)
	addi $t1,$sp,1368
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1372
	sw $t0,0($t1)
	addi $t1,$sp,1372
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1376
	sw $t0,0($t1)
	addi $t1,$sp,1376
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1380
	sw $t0,0($t1)
	addi $t1,$sp,1380
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1384
	sw $t0,0($t1)
	addi $t1,$sp,1384
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1388
	sw $t0,0($t1)
	addi $t0,$sp,1364
	lw $t0,0($t0)
	addi $t1,$sp,1388
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,1392
	sw $t0,0($t1)
	addi $t0,$sp,1392
	lw $t0,0($t0)
	addi $t1,$sp,1336
	lw $t1,0($t1)
	addi $t2,$sp,1232
	sll $t1,$t1,2
	add $t2,$t2,$t1
	sw $t0,0($t2)
	li $t1,7
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1396
	sw $t0,0($t1)
	addi $a0,$sp,1396
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	li $t0,0
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,1400
	sw $t0,0($t1)
	li $t1,0
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1404
	sw $t0,0($t1)
	addi $t0,$sp,1400
	lw $t0,0($t0)
	addi $t1,$sp,1404
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,1400
	sw $t0,0($t1)
	addi $t0,$sp,1400
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,1400
	sw $t0,0($t1)
	addi $t1,$sp,1400
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1408
	sw $t0,0($t1)
	li $t0,5
	addi $t1,$sp,1408
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,1412
	sw $t0,0($t1)
	addi $t0,$sp,1412
	lw $t0,0($t0)
	li $t1,5
	sub $t0,$t0,$t1
	addi $t1,$sp,1416
	sw $t0,0($t1)
	addi $t1,$sp,1416
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1420
	sw $t0,0($t1)
	li $t0,6
	addi $t1,$sp,1420
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,1424
	sw $t0,0($t1)
	addi $t0,$sp,1424
	lw $t0,0($t0)
	li $t1,2
	div $t0,$t0,$t1
	addi $t1,$sp,1428
	sw $t0,0($t1)
	addi $t0,$sp,1428
	lw $t0,0($t0)
	li $t1,3
	div $t0,$t0,$t1
	addi $t1,$sp,1432
	sw $t0,0($t1)
	addi $t0,$sp,1432
	lw $t0,0($t0)
	addi $t1,$sp,1264
	sw $t0,0($t1)
	li $t0,1
	addi $t1,$sp,1272
	sw $t0,0($t1)
	addi $t0,$sp,1264
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,1436
	sw $t0,0($t1)
	addi $t0,$sp,1436
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,1440
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,1440
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1444
	sw $t0,0($t1)
	li $t0,0
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,1448
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,1448
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1452
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,1452
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1456
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,1456
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1460
	sw $t0,0($t1)
	addi $t0,$sp,1444
	lw $t0,0($t0)
	addi $t1,$sp,1460
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,1464
	sw $t0,0($t1)
	addi $t0,$sp,1272
	lw $t0,0($t0)
	li $t1,2
	mul $t0,$t0,$t1
	addi $t1,$sp,1468
	sw $t0,0($t1)
	addi $t0,$sp,1464
	lw $t0,0($t0)
	addi $t1,$sp,1468
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,1472
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,1272
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1476
	sw $t0,0($t1)
	addi $t0,$sp,1476
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,1476
	sw $t0,0($t1)
	addi $t0,$sp,1476
	lw $t0,0($t0)
	li $t1,1999
	mul $t0,$t0,$t1
	addi $t1,$sp,1480
	sw $t0,0($t1)
	addi $t0,$sp,1472
	lw $t0,0($t0)
	addi $t1,$sp,1480
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,1484
	sw $t0,0($t1)
	addi $t0,$sp,1484
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,1488
	sw $t0,0($t1)
	addi $t0,$sp,1488
	lw $t0,0($t0)
	li $t1,1
	add $t0,$t0,$t1
	addi $t1,$sp,1492
	sw $t0,0($t1)
	addi $t0,$sp,1492
	lw $t0,0($t0)
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,1496
	sw $t0,0($t1)
	li $t0,0
	li $t1,1
	sub $t0,$t0,$t1
	addi $t1,$sp,1500
	sw $t0,0($t1)
	addi $t0,$sp,1500
	lw $t0,0($t0)
	li $t1,-1
	mul $t0,$t0,$t1
	addi $t1,$sp,1504
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,1504
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1508
	sw $t0,0($t1)
	addi $t0,$sp,1508
	lw $t0,0($t0)
	li $t1,2
	add $t0,$t0,$t1
	addi $t1,$sp,1508
	sw $t0,0($t1)
	addi $t0,$sp,1496
	lw $t0,0($t0)
	addi $t1,$sp,1508
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,1512
	sw $t0,0($t1)
	addi $t0,$sp,1264
	lw $t0,0($t0)
	addi $t1,$sp,1512
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,1516
	sw $t0,0($t1)
	li $t0,0
	addi $t1,$sp,1516
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1520
	sw $t0,0($t1)
	addi $t0,$sp,1520
	lw $t0,0($t0)
	addi $t1,$sp,1268
	sw $t0,0($t1)
	li $t0,1
	addi $t1,$sp,1268
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1524
	sw $t0,0($t1)
	li $t1,0
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1528
	sw $t0,0($t1)
	addi $t1,$sp,1264
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1532
	sw $t0,0($t1)
	addi $t0,$sp,1528
	lw $t0,0($t0)
	addi $t1,$sp,1532
	lw $t1,0($t1)
	mul $t0,$t0,$t1
	addi $t1,$sp,1536
	sw $t0,0($t1)
	addi $t1,$sp,1536
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1540
	sw $t0,0($t1)
	addi $t0,$sp,1524
	lw $t0,0($t0)
	addi $t1,$sp,1540
	lw $t1,0($t1)
	add $t0,$t0,$t1
	addi $t1,$sp,1544
	sw $t0,0($t1)
	li $t1,2
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1548
	sw $t0,0($t1)
	addi $t1,$sp,1548
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1552
	sw $t0,0($t1)
	addi $t0,$sp,1544
	lw $t0,0($t0)
	addi $t1,$sp,1552
	lw $t1,0($t1)
	sub $t0,$t0,$t1
	addi $t1,$sp,1556
	sw $t0,0($t1)
	addi $t1,$sp,1556
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1560
	sw $t0,0($t1)
	addi $t1,$sp,1560
	lw $t1,0($t1)
	addi $t0,$sp,1200
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1564
	sw $t0,0($t1)
	addi $t1,$sp,1564
	lw $t1,0($t1)
	addi $t0,$sp,1232
	sll $t1,$t1,2
	add $t0,$t0,$t1
	lw $t0,0($t0)
	addi $t1,$sp,1568
	sw $t0,0($t1)
	addi $a0,$sp,1568
	lw $a0,0($a0)
	li $v0,1
	syscall
	li $v0,11
	li $a0,10
	syscall
	j main_end
main_end:
	addi $sp,$sp,1612
	.data
