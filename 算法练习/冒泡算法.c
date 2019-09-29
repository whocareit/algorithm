#include<stdio.h>
int main(){
	int a[100],i,j,t,n;
	scanf("%d",&n);//表示要进行排序的数的个数是多少
	for(i = 1; i <= n; i++){
		scanf("%d",&a[i]); //将所要排序的数存放在这个数组之中 
	} 
	//冒泡排序核心部分
	for(i = 1; i <= n - 1; i++){ //对于n个数需要进行的比较的次数为n-1次 
		for(j = 1; j <= n - 1; j++){ //从第一位开始进行比较直到最后需要进行的比较的次数为n-1 
			if(a[j] < a[j+1]){  //t作为中间变量进行变量之间值的交换 
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	} 
	for(i = 1; i <= n; i++){
		printf("%d ",a[i]);
	}
	getchar();
	getchar();
	return 0;
}
