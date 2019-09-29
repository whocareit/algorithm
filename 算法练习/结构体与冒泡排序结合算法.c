#include<stdio.h>
//使用结构体使数据之间建立联系 
struct student{
	char name[21];
	int score;
};
int main(){
	//创建结构体变量a[]与t 
	struct student a[100],t;
	int i,j,n;
	scanf("%d",&n); //输入一个数n
	for(i = 1; i <= n; i++){
		//输入所关联的结构体中的两个数据 
		scanf("%s %d",a[i].name, &a[i].score);
	} 
	for(i = 1; i <= n - 1; i++){
		for(j = 1; j <= n - 1; j++){
			if(a[j].score < a[j+1].score){
				t = a[j]; //在这里进行交换的是这个结构体，因此这也是将t设置为结构体变量的原因 
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	} 
	for(i = 1; i <= n; i++){
		printf("%s\n",a[i].name);
	}
	getchar();
	getchar();
	return 0;
} 
