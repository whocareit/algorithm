//在存储一个无向图时，采用图的邻接矩阵储存法，如果1号到五号有路线，则该值为1
//自己到自己为0，如果没有路线就为无穷大 

#include<stdio.h>
int book[101],sum,n,e[101][101];
void dfs(int cur) { //cur 代表所在的顶点编号 
	int i;
	printf("%d ",cur);
	sum++; //每次访问一个顶点sum就加1
	if(sum == n) return; //当所有的顶点都被访问过之后就直接退出
	for(i = 1; i <= n; i++){
		//判断当前的顶点cur是否有边，并判断顶点i是否已访问过
		if(e[cur][i] == 1 && book[i] == 0){
			book[i] = 1;
			dfs(i);  
		}
	} 
	return;
}

int main(){
	int i,j,m,a,b;
	scanf("%d %d",&n,&m); 
	//初始化二维矩阵
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
		 	if(i == j) e[i][j] = 0;
			 else e[i][j] = 9999999; //假设9999999为无穷大
			 
	//读入顶点之间的边
	for(i = 1; i <= m; i++){
		scanf("%d %d",&a,&b);
		e[a][b] = 1;
		e[b][a] = 1; //因为该图为无向图，因此需要将e[b][a]也赋值为1 
	} 
	
	book[1] = 1; //从一号顶点开始出发
	dfs(1);
	getchar();getchar();
	return 0; 
}
