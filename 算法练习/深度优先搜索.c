#include<stdio.h>

//设置全局变量 
int a[10],book[10],n; 
//数组a代表记录当前在第几个盒子面前，book用于记录扑克牌是否在手上
//需要注意的是，当没有给数组中的元素赋初值时，默认的初始值为每个数组
//的初始值为0

//封装dfs函数用于解决在当前第几个盒子前应该做的事情。
void dfs(int step){ //step表示在第几个盒子的面前
  int i;
  if(step == n+1) { //在第n+1个盒子面前时，表示盒子被占满，输出排列的结果即可 
  	for(i = 1; i <= n; i++){
  		printf("%d",a[i]);
	  }
	printf("\n");
	return; //返回到之前一步 
  }	
  
  //尝试所有的可能
  for(i = 1; i <= n ; i++){
  	if(book[i] == 0){
  		a[step]=i;
  		book[i]=1;
  		
  		//当前的盒子已经被占有走向下一个盒子
		dfs(step+1);
		book[i] = 0;
	  }
  } 
  return;
} 

int main(){
	scanf("%d",&n); //输入的n在1~9之间 
	dfs(1);
	getchar(); getchar(); 
	return 0;
} 
