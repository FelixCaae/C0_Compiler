	const int cona = 1
	const int conb = 2
	const int conc = 3
	const int cong = 4
	const int conh = 5
	const int coni = 6
	const int conj = 7
	array int cona[10]
	var int c
	int emptyfunc()
	int emptyfunc2()
	int testchar()
	ret 48
	int fibonacci()
	para int n
	const int cona = -1
	var char testc
	n == 1
	BNZ if_1
	ret 1
if_1:
	n != 2
	BNZ if_2
	$tmp4 = n + -1
	push $tmp4
	call fibonacci
	$tmp5 = RET
	$tmp7 = n - 2
	push $tmp7
	call fibonacci
	$tmp8 = RET
	$tmp9 = $tmp5 + $tmp8
	$tmp11 = $tmp9 + 0
	ret $tmp11
if_2:
	ret 1
	int move()
	para char a
	para char b
	const int testcon1 = 1
	const char testcon2 = 49
	print "MOVE"
	print a
	print " TO "
	print b
	print " "
	int hanoi()
	para int hano
	para char l
	para char m
	para char r
	2 > hano
	BNZ if_3
	push l
	push r
	call move
	ret
	print "RETURN ERROR"
if_3:
	$tmp2 = hano - 1
	push $tmp2
	push l
	push r
	push m
	call hanoi
	push l
	push r
	call move
	$tmp4 = hano - 1
	push $tmp4
	push m
	push l
	push r
	call hanoi
	int getpower()
	para int n
	para int le
	var int move
	le >= 2
	BNZ if_4
	push n
	$tmp2 = le - 1
	push $tmp2
	call getpower
	$tmp3 = RET
	move = $tmp3 
	$tmp5 = le - 1
	$tmp6 = move * n
	a[$tmp5] = $tmp6
	$tmp7 = n * move
	ret $tmp7
if_4:
	1 <= le
	BNZ if_5
	$tmp10 = le - 1
	a[$tmp10] = n
	ret n
if_5:
	int getsqr()
	para int n
	var int _i
	_i = 1 
do_6:
	$tmp2 = _i + 1
	_i = $tmp2 
	$tmp3 = n / _i
	_i < $tmp3
	BZ do_6
	$tmp5 = 0 - n
	$tmp6 = _i * _i
	$tmp5 = $tmp5 + $tmp6
	$tmp9 = 0 - 1
	$tmp9 = $tmp9 + _i
	$tmp11 = _i - 1
	$tmp12 = $tmp9 * $tmp11
	$tmp13 = n - $tmp12
	$tmp5 < $tmp13
	BNZ if_7
	ret _i
if_7:
	$tmp15 = _i - 1
	ret $tmp15
	void main()
	const char cond = 65
	const char cone = 66
	const char conf = 67
	const char con1 = 43
	const char con2 = 45
	const char con3 = 42
	const char ccon3 = 47
	const int testcon = 100
	var int tmp
	var int c
	var int num
	var int i
	var int fib
	array int cona[10]
	var int sqr
	array int cona[100]
	var int a_
	var int a_a
	var int a0
	var int a00
	var int testai1
	var int testai2
	var int testai3
	var int testai4
	var int testai5
	var int testai6
	var char c1
	var char c2
	var char c3
	var char c4
	var char c5
	var char c6
	a_a = 123456789 
	a_ = 65 
	testai[0] = 5
	$tmp4 = testai[0]
	testai[$tmp4] = 1
	testai[43] = 2
	read c
	read num
	1 == c
	BNZ case_8_1
	push num
	push 10
	call getpower
	i = 0 
do_9:
	print "NO"
	$tmp11 = i + 1
	print $tmp11
	print ":"
	$tmp12 = a[i]
	print $tmp12
	print " "
	print ""
	$tmp14 = i + 1
	i = $tmp14 
	i < 10
	BZ do_9
	GOTO switch_8
case_8_1:
switch_8:
	2 == c
	BNZ case_10_1
	push num
	push 65
	push 66
	push 67
	call hanoi
	GOTO switch_10
case_10_1:
	3 == c
	BNZ case_10_2
	push num
	call fibonacci
	$tmp18 = RET
	fib = $tmp18 
	print fib
	GOTO switch_10
case_10_2:
switch_10:
	4 == c
	BNZ case_11_1
	push num
	call getsqr
	$tmp20 = RET
	sqr = $tmp20 
	print sqr
	GOTO switch_11
case_11_1:
	5 == c
	BNZ case_11_2
	call testchar
	$tmp22 = RET
	print $tmp22
	$tmp25 = 3 * 2
	$tmp27 = $tmp25 / 6
	$tmp29 = testai[0]
	$tmp30 = $tmp27 * $tmp29
	print $tmp30
	GOTO switch_11
case_11_2:
	6 == c
	BNZ case_11_3
	$tmp33 = testai[0]
	$tmp33 != 0
	BNZ if_12
	print "IFCORRECT"
if_12:
	tmp = 0 
do_13:
	$tmp37 = testai[0]
	print $tmp37
	$tmp40 = testai[0]
	$tmp42 = $tmp40 - 1
	testai[0] = $tmp42
	$tmp44 = tmp + 1
	tmp = $tmp44 
	$tmp46 = testai[0]
	$tmp46 != 0
	BZ do_13
	GOTO switch_11
case_11_3:
	-7 == c
	BNZ case_13_4
	read testai1
	read testai2
	read testai3
	read testai4
	read testai5
	read testai6
	print testai1
	print testai2
	print testai3
	print testai4
	print testai5
	print testai6
	GOTO switch_11
case_13_4:
	0 == c
	BNZ case_13_5
	read c1
	97 == c1
	BNZ case_14_1
	print 1
	GOTO switch_14
case_14_1:
	98 == c1
	BNZ case_14_2
	print 2
	GOTO switch_14
case_14_2:
switch_14:
	GOTO switch_11
case_13_5:
switch_11:
	ret
