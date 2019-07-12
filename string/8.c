#include <stdio.h>
#include <stdlib.h>

int MyAtoi(char *str)
{
	const unsigned int max=~(unsigned int)0/2;
	if(NULL==str) return 0;//为空时不转
	while(*str==' ') ++str;//找到第一个非空白字符
	if(*str=='\0') return 0;//若没有非空白字符时，不转
	int flag=0;//标记为0时为正，为1时为负
	if(*str=='-'){
		flag=1;
		++str;
	}else if(*str=='+'){
		++str;
	}
	//int num=0;
	unsigned long num=0;
	while((*str!='\0')&&(*str>='0' && *str<='9')){
		num=num*10+(*str-'0');
		if(0==flag&&num>max){//判断整型数是否超出范围
			return max;
		}else if(1==flag&&num>max+1){
			return max+1;
		}
		++str;
	}
	if(1==flag) return -num;
	return num;
}

int main(int argc, const char *argv[])
{
	//printf("int max value=%d\n",~(unsigned int)0/2);
	
	//char str[]={""};
	//char str[]={"     "};
	//char str[]={" 1234"};
	//char str[]={" 1234 5678"};
	//char str[]={" hello 1234"};
	//char str[]={"1234world"};
	//char str[]={"1234"};
	//char str[]={"+1234"};
	//char str[]={"-1234"};
	char str[]={"2147483647"};
	//char str[]={"2147483648"};
	//char str[]={"-2147483647"};
	//char str[]={"-2147483648"};
	//char str[]={"-2147483649"};
	//char str[]={"-91283472332"};
	int num=MyAtoi(str);
	printf("num=%#0x,num=%d\n",num,num);
	return 0;
}

