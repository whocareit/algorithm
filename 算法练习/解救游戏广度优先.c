#include<stdio.h>
struct note{
	int x; //横坐标
	int y; //纵坐标
	int f; //父亲在队列中的编号
	int s; //步数 
};

int main(){
	struct note que[2501]; //地图的大小不超过2501,队列的扩展不超过2500
	
	int a[51][51] = {0},book[51][51] = {0};
	//定义四个需要走的方向分别为右 下 左 上 
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m); //地图的大小
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			scanf("%d",&a[i][j]);
		}
	} 
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//队列初始化
	head = 1;tail = 1;
	//向队列中添加插入的迷宫入口坐标
	que[tail].x = startx; que[tail].y = starty;
	que[tail].f = 0; que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0; //用与标记是否到达指定点，0表示未到达，1表示已到达
	//当队列不为空时的循环
	while(head < tail){
		for(k = 0; k <= 3; k++){
			//计算下一个点的坐标
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//判断是否越界
			if(tx < 1 || tx > n || ty < 1 || ty > m){
				continue;
			} 
			//判断该点是否在路上，并且没有遇到障碍物
			if(a[tx][ty] == 0 && book[tx][ty] == 0){
				//在宽深中，每个只能入队一次，与深搜不同这里需要将book数组还原
				book[tx][ty] = 1;
				//插入新的点到队列中
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++; 
			} 
			
			if(tx == p && ty == q){
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
		head++;
		}
	
	printf("%d",que[tail-1].s);
	getchar();getchar();
	return 0; 
} 
