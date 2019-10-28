//有n个连通图，至少需要n-1条边，每条边有一段路径，现找寻
//无向图的最小生成树
#include<stdio.h>
struct edge{
	int u;
	int v;
	int w;
}; //使用结构体来存储边的关系
struct edge e[10];
int n,m;
int f[7] = {0},sum = 0,count = 0; //并查集需要用到一些变量
//f数组大小根据实际情况来设置，要比n的最大值大1
void quicksort(int left, int right){
	int i,j;
	struct edge t; 
	if(left > right)
		return;
	i = left;
	j = right;
	while(i != j){
		while(e[j].w >= e[left].w && i < j){
			j--;
		}
		while(e[i].w <= e[left].w && i < j){
			i++;
		}
		//交换
		if(i < j){
			t = e[i];
			e[i] = e[j];
			e[j] = t;
		} 
	}
	t = e[left];
	e[left] = e[i];
	e[i] = t;
	quicksort(left,i-1);
	quicksort(i+1,right);
	return;
} 

int getf(int v){
	if(f[v] == v)
		return v;
	else{
		f[v]=getf(f[v]);
		return f[v];
	}
}

//合并两个子集 
int merge(int v,int u){
	int t1,t2;
	t1 = getf(v);
	t2 = getf(u);
	if(t1 != t2){
		f[t2] = t1;
		return 1;
	}
	return 0;
}
int main(){
	int i;
	scanf("%d %d",&n,&m);
	
	//使用结构体来读入边
	for(i = 1; i <= m; i++)
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	quicksort(1,m);
	for(i = 1; i <= n; i++)
		f[i] = i;
	//Kruskal算法核心部分
	for(i = 1; i <= m; i++){
		if(merge(e[i].u,e[i].v)){
			count++;
			sum = sum+e[i].w;
		}
		if(count == n-1)
			break;
	} 
	printf("%d",sum);
	getchar();getchar();
	return 0;
}



