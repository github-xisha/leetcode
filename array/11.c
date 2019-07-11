#include <stdio.h>

#if 1
int MaxArea(int *height,int heightSize)
{
	int max_area=0,mul=0;
	for(int i=0;i<heightSize-1;++i){//外层循环标记垂直线的起始位,内层循环用于遍历其后的所有垂直线
		for(int j=i+1;j<heightSize;++j){
			mul=(height[i]>height[j]?height[j]:height[i])*(j-i);
			if(mul>max_area) max_area=mul; 
		}
	}
	return max_area;
}
#else
//参考代码：双指针
//定义前后两个指针，每一步移动两边中最短的指针，直到两指针相遇
int MaxArea(int *height,int heightSize)
{
	int max_area=0,mul=0;
	int left_index=0,right_index=heightSize-1;
	while(left_index<right_index){
		if(height[left_index]>height[right_index]){
			mul=height[right_index]*(right_index-left_index);	
			right_index--;
		}else{
			mul=height[left_index]*(right_index-left_index);	
			left_index++;
		}
		if(mul>max_area) max_area=mul;
	}
	return max_area;
}
#endif

int main(int argc, const char *argv[])
{
	int height[]={1,8,6,2,5,4,8,3,7};
	int max_mul=MaxArea(height,sizeof(height)/sizeof(int));
	printf("max_mul=%d\n",max_mul);
	return 0;
}
