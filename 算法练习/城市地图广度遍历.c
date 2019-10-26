#include<stdio.h>
struct note{
	int x; //城市编号 
	int s; //转机次数 
}; 

int main(){
	struct note que[2501];
	int e[51][51] = {0},book[51] = {0};
	int head,tail;
	int i,j,n,m,a,b,cur,start,end,flag = 0;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	//初始化这个邻接矩阵
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j) 
				e[i][j] = 0;
			else 
				e[i][j] = 99999999;
	
	//读入城市之间的航班
	for(i = 1; i <= m; i++){
		scanf("%d %d",&a,&b);
		//在这里是无向图
		e[a][b] = 1;
		e[b][a] = 1; 
	} 
	
	//队列初始化
	head = 1;
	tail = 1; 
	//从start号城市出发，将start号城市加入队列 
	que[tail].x = start;
	que[tail].s= 0;
	tail++;
	book[start] = 1;
	//当队列不为空时
	while(head < tail){
		cur = que[head].x; //当前队列的首城市编号
		for(j = 1; j <= n; j++){ //从1~n一次尝试 
			if(e[cur][j] != 9999999 && book[j] == 0){
				//如果城市cur到城市j有航班并且城市j不在队列中，则城市j入队 
				que[tail].x = j;
				que[tail].s = que[head].s + 1; //转机次数
				tail++;
				//标记城市j已经在队列中 
				book[j] = 1; 
			}
			if(que[tail-1].x == end){
				flag = 1;
				break;
			}
		} 
		if(flag == 1){
			break;
		}
		head++; //当一个点扩展结束后，head才能继续扩展 
	}
	
	printf("%d",que[tail-1].s);
	getchar();getchar();
	return 0; 
}



