#include<stdio.h>
int main(){
	int i,j,n,m,a,b,cur,book[101] = {0},e[101][101];
	int que[10001],head,tail;
	scanf("%d %d",&n,&m);
	//初始化矩阵
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j) e[i][j] = 0;
			else e[i][j] = 999999999;
			
	//读入顶点的边
	for(i = 1; i <= m; i++){
		scanf("%d %d",&a,&b);
		e[a][b] = 1;
		e[b][a] = 1; //存储的是一个无向图，所以需要e[b][a]也为1 
	} 
	
	//队列初始化
	head = 1; tail = 1;
	
	//从一号顶点出发，先将一号顶点入队
	que[tail] = 1;
	tail++;
	book[1] = 1;
	while(head < tail && tail <= n){
		cur = que[head];
		for(i = 1; i <= n; i++){
			if(e[cur][i] == 1 && book[i] == 0){
				que[tail] = i;
				tail++;
				book[i] = 1;
			}
			if(tail > n){
				break;
			}
		}
		head++;
	} 
	for(i = 1; i < tail; i++)
		printf("%d ",que[i]);
	getchar();getchar();
	return 0;
}
