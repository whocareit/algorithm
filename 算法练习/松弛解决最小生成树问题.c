#include<stdio.h>
int main(){
	int n,m,i,j,k,min,t1,t2,t3;
	int e[7][7],dis[7],book[7] = {0};
	int inf = 99999999;
	int count = 0,sum = 0;
	
	//读入n m
	scanf("%d %d",&n,&m);
	 
	//初始化
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
	//开始读入边
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		//这里是无向图，所以需要反向储存 
		e[t1][t2] = t3;
		e[t2][t1] = t3;
	}  
	
	//初始化dis数组，需要注意的是此时是一号顶点到各个顶点的距离 
	for(i = 1; i <= n; i++)
		dis[i] = e[1][i];
		
	//Prim核心
	//将1号顶点加入生成树
	book[1] = 1; //记录1号顶点已经加入生成树
	count++;
	//求最短距离 
	while(count < n){
		min = inf;
		for(i = 1; i <= n; i++){
			if(book[i] == 0 && dis[i] < min){
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum = sum + dis[j];
		//扫描当前顶点j所有的边，再以j为中间点，更新生成树到每个非树顶点的距离
		for(k = 1; k <= n; k++){
			if(book[k] == 0 && dis[k] > e[j][k])
				dis[k] = e[j][k];
		} 
	} 
	printf("%d\n",sum);
	getchar();
	getchar();
	return 0;
}




