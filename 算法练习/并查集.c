#include<stdio.h>
int f[1001]={0},n,m,sum=0;
//初始化操作，数组内部存储的是自己的下标 
void init(){
	int i;
	for(i = 1; i <= n; i++)
		f[i] = i;
	return;
}

//使用递归的方式找到最大boss
int getf(int v){
	//表示找到了最大的boss 
	if(f[v] == v)
		return v;
	else{
		//路径压缩，找到最大boss 
		f[v] = getf(f[v]);
		return f[v];
	}
} 
//合并两个子集合的函数
void merge(int v,int u){
	//t1 t2分别为v和u的大boss，每次双方会谈必须是各自的最高领导人 
	int t1,t2;
	t1 = getf(v);
	t2 = getf(u);
	if(t1 != t2){
		//如果双方不在一个集合中，则实行靠左原则，左边的boss变成右边的boss 
		f[t2] = t1;
	}
	return;
} 
int main(){
	int i,x,y;
	scanf("%d %d",&n,&m);
	init(); //进行初始化
	for(i = 1; i <= m; i++){
		//开始合并
		scanf("%d %d",&x,&y);
		merge(x,y); 
	} 
	//最后扫描右多少个对立的集合
	for(i = 1; i <= n; i++){
		if(f[i] == i)
		sum++;
	} 
	printf("%d\n",sum);
	getchar();getchar();
	return 0;
}




