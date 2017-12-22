	const int cint1 = 10
	const int cint2 = -1
	const int cint3 = 0
	const int cmaxint = 2147483647
	const int cminint = -2147483647
	const char cchar0 = 95
	const char cchar1 = 97
	const char cchar2 = 65
	const char cchar3 = 43
	const char cchar4 = 42
	const char cchar5 = 48
	var int _
	var int _9
	var int __
	var int _a
	var int a1
	var char ___a
	var int a2
	array int cint1[10]
	array int cint1[1]
	var int a5
	array char cint1[1]
	array char cint1[20]
	var char aa4
	int printhelloworld()
	var int cint2
	cint2 = 233 
	print " !#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~"
	print ""
	print "helloworld!"
	print 43
	print 45
	print 42
	print 47
	print 95
	print 10
	print cint2
	ret
	int squaresum()
	para int _a
	para int b
	const int unuse = 0
	var int temp
	$tmp1 = _a * -1
	$tmp3 = 0 - $tmp1
	temp = $tmp3 
	$tmp5 = _a * 0
	temp = $tmp5 
	$tmp6 = _a * 0
	temp = $tmp6 
	$tmp7 = _a * _a
	temp = $tmp7 
	$tmp8 = _a * _a
	$tmp10 = 0 - $tmp8
	$tmp12 = 0 - $tmp10
	$tmp13 = b * b
	$tmp12 = $tmp12 + $tmp13
	temp = $tmp12 
	ret temp
	int _mystop()
	var char temp
	print "input a char and enter:"
	read temp
	int nsquaresum()
	para int temp
	para int times
	array int cint1[10]
	var int ttemp
	ttemp = temp 
	times == 1
	BNZ if_1
	ret temp
if_1:
	push temp
	$tmp2 = times - 1
	push $tmp2
	call nsquaresum
	$tmp3 = RET
	$tmp4 = ttemp * $tmp3
	ttemp = $tmp4 
	ret ttemp
	int nextalphabet()
	para char x
	$tmp1 = x + 1
	ret $tmp1
	void main()
	var int num
	var int temp1
	var int temp2
	array char cint1[3]
	array int cint1[1]
	var int i
	var int j
	var int k
	print "MaxInt"
	print 2147483647
	print "MinInt"
	print -2147483647
	call printhelloworld
	print "please input number counts:"
	read num
	i = 0 
	_a = 666 
	$tmp5 = 0 - 20
	intarray[0] = $tmp5
	$tmp7 = intarray[0]
	print $tmp7
	abc[0] = 97
	abc[1] = 98
	abc[2] = 99
	$tmp15 = abc[0]
	push $tmp15
	call nextalphabet
	$tmp16 = RET
	print $tmp16
	$tmp18 = intarray[0]
	_a > $tmp18
	BNZ if_2
	$tmp20 = intarray[0]
	$tmp22 = $tmp20 - 1
	_a = $tmp22 
if_2:
	print "_a is"
	print _a
	$tmp24 = intarray[0]
	_a < $tmp24
	BNZ if_3
	_a = 2 
if_3:
	print "_a is"
	print _a
	_a == 2
	BNZ if_4
	$tmp28 = intarray[0]
	$tmp30 = $tmp28 * 2
	_a = $tmp30 
if_4:
	print "_a is"
	print _a
	$tmp32 = intarray[0]
	_a != $tmp32
	BNZ if_5
	_a = 4 
if_5:
	print "_a is"
	print _a
	_a >= 4
	BNZ if_6
	$tmp37 = 0 - 0
	_a = $tmp37 
if_6:
	print "_a is"
	print _a
	_a <= 0
	BNZ if_7
	print "if ok....perhaps"
	print _a
	_a = 666 
if_7:
	print "_a is"
	print _a
	0 == num
	BNZ case_8_1
	print "result:0"
	GOTO switch_8
case_8_1:
	1 == num
	BNZ case_8_2
	read temp1
	print "result:"
	$tmp43 = temp1 + 10
	$tmp45 = $tmp43 - 10
	print $tmp45
	GOTO switch_8
case_8_2:
	2 == num
	BNZ case_8_3
	read temp1
	read temp2
	print "result:"
	$tmp48 = temp1 + 0
	push $tmp48
	$tmp50 = temp2 - 2
	$tmp52 = $tmp50 + 2
	push $tmp52
	call squaresum
	$tmp53 = RET
	print $tmp53
	GOTO switch_8
case_8_3:
switch_8:
	call _mystop
	push 1
	push 1
	call nsquaresum
	$tmp56 = RET
	i = $tmp56 
	print ""
	$tmp57 = temp1 + temp2
	k = $tmp57 
	$tmp58 = temp1 + temp2
	i = $tmp58 
	j = temp1 
	$tmp59 = j + temp2
	j = $tmp59 
	call _mystop
	ret
