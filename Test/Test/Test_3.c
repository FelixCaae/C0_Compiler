const int cInt1=+10,cInt2=-1;
const int cInt3=0;
const int cMaxInt=2147483647,cMinInt=-2147483648;
const char cChar0='_',cChar1='a',cChar2='A',cChar3='+',cChar4='*';
const char cChar5='0';
int _,_9,__,_a;
int a1;
char ___A;
int a2,a3[10],a4[1],a5;
char AA2[1],AA3[20],AA4;
void PrintHelloWorld(){
    int cInt2;
    cInt2=233;
    printf(" !#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    printf("");
    printf("helloworld!");
	printf('+');
	printf('-');
    printf('*');
	printf('/');
    printf(cChar0);
    printf(cInt1);
    printf(cInt2);
    return;
}
int SquareSum(int _a,int b){
    const int unuse=0;
    int temp;
    temp=-_a*-1;
    temp=+_a*0;
    temp=_a*unuse;
    temp=_a*_a;
    temp=-(-_a*_a)+(b*b);
    return (temp);
}
void _myStop(){
    char temp;
    printf("input a char and enter:");
    scanf(temp);
}
int NsquareSum(int temp,int times){
    int noneUse[10];
    int TTemp;
    TTemp=temp;
    if(times==1)
        return (temp);
    TTemp=TTemp*NsquareSum(temp,times-1);
    return (((TTemp)));
}
char NextAlphabet(char x){
    return (x+1);
}
void main(){
    int num;
    int temp1,temp2;
    char abc[3];
    int intArray[1];
    int i,j,k;
	printf("MaxInt", cMaxInt);
	printf("MinInt", cMinInt);
    PrintHelloWorld();
    printf("please input number counts:");
    scanf(num);
    i=0;
    _a=666;
    intArray[0]=-20;
    printf(intArray[0]);
    abc[0]='a';
    abc[1]='b';
    abc[2]='c';
    printf(NextAlphabet(abc[0]));
    if(_a>intArray[0]){
        _a=intArray[0]-1;
    }
    printf("_a is",_a);
    if(_a<intArray[0]){
        _a=2;
    }
    printf("_a is",_a);
    if(_a==2){
        _a=intArray[0]*2;
    }
    printf("_a is",_a);
    if(_a!=intArray[0]){
        _a=4;
    }
    printf("_a is",_a);
    if(_a>=+4){
        _a=-0;
    }
    printf("_a is",_a);
    if(_a<=+0){
        printf("if ok....perhaps",_a);
        _a=666;
    }
    printf("_a is",_a);
    switch(num){
        case 0:printf("result:0");
        case +1:{scanf(temp1);printf("result:",temp1+10-10);}
        case +2:{scanf(temp1,temp2);printf("result:",SquareSum(temp1+0,temp2-2+2));}
    }
    _myStop();
    i=(NsquareSum(1,1));
    printf("");
    k=temp1+temp2;
    i=temp1+temp2;
    j=temp1;
    j=j+temp2;
    _myStop();
    return;
}
