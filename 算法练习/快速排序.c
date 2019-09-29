#include<stdio.h>
int a[101],n;
//快排算法实现 
 quicksort(int left,int right){
	//其中temp作为基准数，t作为中间变量 
	int i,j,temp,t; 
	//作为一个判断的标准，左边大于右边时就不执行下面的操作 
	if(left > right){
		return;
	}
	//基准值赋值 
	temp = a[left];
	i = left;
	j = right;
	while( i != j){
		//从右到左开始查询比基准数小的值 
		while( a[j] >= temp && i < j){
			j--;
		}
		// 从左往右开始查询比基准值大的数 
		while( a[i] <= temp && i < j){
			i++;
		}
		//查询到不符合条件的就进行位置的交换 
		if(i < j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	} 
	//基准值进行归位 
	a[left] = a[i];
	a[i] = temp;
	//使用递归进行换位之后的基准数排序直至满足left<right 
	quicksort(left,i-1);
	quicksort(i+1,right);
	return;
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	quicksort(1,n);
	for(i = 1; i <= n; i++){
		printf("%d ",a[i]);
	}
	getchar();
	getchar();
	return 0;
} 
