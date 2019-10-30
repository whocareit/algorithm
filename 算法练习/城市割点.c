//割点的定义：对于某个顶点u,如果存在至少一个顶点v（即顶点u的儿子），使得
//low[v] >= num [u]，即不能回到祖先，那么u点为割点
#include<stdio.h>
int n,m,e[9][9],root;
int num[9],low[9],flag[9],index; //index用来进行时间戳的递增
//求两个数中较小一个数的函数
int min(int a,int b){
	return a > b ? b : a;
} 
//割点算法的核心
void dfs(int cur, int father){ //需要传入两个参数，当前顶点编号和父顶点编号
	 int child = 0,i; //child用于记录在生成树中当前顶点cur的儿子个数
	 
	 index++; //时间戳加1
	 num[cur] = index; //当前节点cur的时间戳 
	 low[cur] = index; //当前节点能够访问到最早顶点的时间戳，刚开始就是自己
	 for(i = 1; i <= n; i++){
	 	if(e[cur][i] == 1){
	 		if(num[i] == 0){//如果顶点i的时间戳为0，说明顶点i还没有被访问过 
	 			//从生成树的角度来说，此时的i为cur的儿子
				 child++;
				 dfs(i,cur); //继续向下深度遍历
				 //更新当前顶点cur能访问到的最早顶点的时间戳
				 low[cur] = min(low[cur],low[i]);
				 //如果当前顶点不是根节点并且满足low[i]>=num[cur],则当前顶点为割点
				 if(cur != root && low[i] >= num[cur])
				 	flag[cur] = 1;
				 //如果当前顶点是根节点，在生成树中根节点必须有两个儿子，那么这个根节点才是割点
				 if(cur == root &&  child == 2)
				 	flag[cur] = 1; 
			 }
			 else if(i != father){
			 	//如果顶点被访问过，并且这个顶点不是当前顶点cur的父亲，则说明
				//此时的i为cur的祖先，因此需要更新当前节点cur能访问到最早顶点的时间戳 
			 	low[cur] = min(low[cur],num[i]);
			 }
		 }
	 } 
	 return;
} 
int main(){
	int i,j,x,y;
	scanf("%d %d",&n,&m);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++) 
			e[i][j] = 0;
	for(i = 1; i <= m; i++){
		scanf("%d %d",&x,&y);
		e[x][y] = 1;
		e[y][x] = 1;
	}
	root = 1;
	dfs(1,root);
	for(i = 1; i <= n; i++){
		if(flag[i] == 1)
			printf("%d ",i);
	}
	getchar();getchar();
	return 0;
} 



