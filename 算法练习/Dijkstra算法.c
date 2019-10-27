//该方法的别名为单源最短路径算法，其算法基本思想，每次找到离源点最近的一个点，然后以顶点为中心进行扩展
//最终得到源点到其余所有点的最短路径。算法实现如下
#include<stdio.h>
int main(){
	int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
	int inf = 999999999;//表示最大值
	scanf("%d %d",&n,&m);
	//使用邻接矩阵的方式来存储 
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(i == j) 
				e[i][j] = 0;
			else 
				e[i][j] = inf;
	//读入每条边的值
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2] = t3;
	} 
	
	//初始化dis数组
	for(i = 1; i <=n; i++)
		dis[i] = e[1][i];
		
	//book数组初始化
	for(i = 1; i <= n; i++){
		book[i] = 0;
	} 
	book[1] = 1;
	
	//Dijkstra算法核心
	for(i = 1; i <= n-1; i++){//表示松弛的次数 
		//找到离一号顶点最近的点的顶点 
		min = inf;
		for(j = 1; j <= n; j++){
			if(book[j] == 0 && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		//松弛的实现过程 
		for(v = 1; v <= n; v++){
			if(e[u][v] < inf){
				if(dis[v] > dis[u] + e[u][v])
					 dis[v] = dis[u] + e[u][v];
			}
		}
	} 
	//输出最终结果
	for(i = 1; i <= n; i++){
		printf("%d ",dis[i]);
	} 
	getchar();getchar();
	return 0;
} 
//其算法实现的核心部分是，首先通过一个for循环去遍历整个dis数组找到离1顶点最近的
//一个点，然后再来进行松弛。该算法的缺陷是不能求解负边权边问题 
