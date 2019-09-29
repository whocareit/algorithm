#include<stdio.h>
int main(){
	//data用于存放数据  right表示位置 
	int data[101],right[101];
	int i, n , t, len;
	//读入已有的数
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		//i 表示顺序 data[i]用于表示存储的数据 
		scanf("%d", &data[i]);
	} 
	len = n;
	//初始化right数组
	for(i = 1; i <= n; i++){
		//right数组中存放的是当前数组的下一个位置 
		if(i != n ){
			right[i] = i + 1;
		} else {
			right[i] = 0;
		}
	} 
	//直接在data数组的末尾增加一个数
	len++;
	//输入插入的数 
	scanf("%d", &data[len]); 
	//从链表的头部开始遍历	
	t = 1;
	while( t!= 0){
		//如果待插入的数小于当前结点的下一个数，就执行插入操作 
		if(data[right[t]] > data[len]){
			right[len] = right[t];
			right[t] = len; 
			break;
		}
		t = right[t];
	} 
	
	t = 1;
	while(t != 0){
		printf("%d ",data[t]);
		t = right[t];
	}
	
	getchar(); getchar();
	return 0;
}
