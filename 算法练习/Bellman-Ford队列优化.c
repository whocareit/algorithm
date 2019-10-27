#include<stdio.h>
int main(){
	int n,m,i,j,k;
	//初始化一个邻接表，具体的内存大小要按照具体的情况来实现
	//u v w数组的值要比m边数大1
	int u[8],v[8],w[8];
	//firsr要比顶点数大1,next要比边数大1
	int first[6],next[8];
	int dis[6] = {0},book[6] = {0};
	int que[101] = {0},head = 1, tail = 1;
	int inf = 999999999;
	//输入顶点数与边数 
	scanf("%d %d",&n,&m);  
	
	//初始化dis数组，dis数组表示一号顶点到其余各点之间的位置
	for(i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0; //自己到自己的位置初始化为0
	
	//初始化book数组，刚开始没有一个点在队列中，因此全为0；
	for(i = 1; i <= n; i++)
		book[i] = 0;
	
	//初始化first数组
	for(i = 1; i <= n; i++)
		first[i] = -1;
		
	for(i = 1; i <= m; i++){
		//读入每一条边，并且将邻接表初始化
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
	} 
	
	//1号顶点入队
	que[tail] = 1;
	tail++;
	book[1] = 1;
	while(head < tail){
		k = first[que[head]]; //当前需要处理的队首顶点 
		while(k != -1){ //扫描当前顶点所有的边 
			if(dis[v[k]] > dis[u[k]] + w[k]){
				dis[v[k]] = dis[u[k]] + w[k];
				if(book[v[k]] == 0){
					que[tail] = v[k];
					tail++;
					book[v[k]] == 1;
				}
			} 
			k = next[k];
		}
		//出队 
		book[que[head]] = 0;
		head++;
	}
	for(i = 1; i <= n; i++){
		printf("%d ",dis[i]);
	} 
	
	getchar();getchar();
	return 0;
}
