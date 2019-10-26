//题目所述：求最短骑行方案，给出五个顶点，两个顶点之间有一定的距离，有的两个顶点 
// 之间并没有距离。现需要求出从一个顶点到另外一个顶点之间的最短距离存地图的方式
//采用邻接矩阵的方式。数据给出内容如下
//  5   8
//  1   2   2        1    5   10
//  2   3   3        2    5   7
//  3   1   4        3    4   4
//  4   5   5        5    3   3
#include<stdio.h>
int min = 9999999,book[101],n,e[101][101]; //99999999表示无穷大
void dfs(int cur,int dis){
	int j;
	if(dis > min) return;
	if(cur == n){ //判断是否到达了目标城市 
		if(dis < min)
		 min = dis;
		return;
	}
	for(j = 1; j <=n; j++){
		//判断当前城市cur到城市j是否有路，并判断城市j是否在已走过的路径中 
		if(e[cur][j] != 99999999 && book[j] == 0){
			book[j] = 1;
			dfs(j,dis+e[cur][j]);
			book[j] = 0;
		}
	} 
	return;
} 

int main(){
	int i,j,m,a,b,c;
	scanf("%d %d",&n,&m);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j)
				e[i][j] = 0;
			else
				e[i][j] = 9999999;
	//读入城市之间的道路
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = c;
	} 
	
	//从一号城市出发
	book[1] = 1;
	dfs(1,0);
	printf("%d",min);
	
	getchar();getchar();
	return 0;
}
//实现原理，通过深度遍历的方式记录，计算每次到达目标点的距离之和，并且更新
//最短的距离即可 




