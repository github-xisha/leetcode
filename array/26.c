#include <stdio.h>

int RemoveDuplicate(int *nums,int numsSize)
{
	//if(NULL==nums) return 0;
	if(0==numsSize) return 0;//数组为空时
	int i=0,j=1;
	for(;j<numsSize;++j){
		if(nums[i]!=nums[j]){
			++i;
			nums[i]=nums[j];
		}
	}
	return i+1;
}

int main(int argc, const char *argv[])
{
	int nums[]={0,0,1,1,1,2,2,3,4,4,4,4,5,6};
	//int nums[]={0};
	//int nums[]={0,0};
	//int nums[]={0,0,1};
	//int nums[]={};
	int len=RemoveDuplicate(nums,sizeof(nums)/sizeof(int));
	for(int i=0;i<len;++i){
		printf("%d ",nums[i]);
	}
	printf("\n");
	return 0;
}
