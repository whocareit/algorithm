#include<stdio.h>

struct note{
	int x;// 横坐标
	int y;//纵坐标 
};

int main(){
	//扩展数组的大小 
	struct note que[2501];
	int head,tail;
	int a[51][51]; //地图大小
	int book[51][51] = {0}; // 给地图做标记
	int i,j,k,sum,max = 0,mx,my,n,m,startx,starty,tx,ty;
	//定义方向数组
	int next[4][2] = {
		{0,1}, //向右
		{1,0}, //向下
		{0,-1}, //向左
		{-1,0}, //向上 
	};
	
	//读入n,m以及初始坐标
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	
	//读入地图
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
		 	scanf("%d",&a[i][j]);
		 	
	//队列初始化
	head = 1; tail = 1;
	//向队列中插入降落点的起始坐标
	que[tail].x = startx; que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;
	
	//当队列不为空时的循环
	while(head < tail){
		for(k = 0; k <= 3; k++){
			//计算下一个点的坐标 
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			
			//判断该点是否越界
			if(tx < 1 || tx > n || ty < 1 || ty > m){
				continue;
			} 
			
			//判断该点是否为陆地并且是否已经走过
			if(a[tx][ty] > 0 && book[tx][ty] == 0){
				sum++;
				//每个点只能入栈一次，所以需要标记该点
				book[tx][ty] = 1;
				//将新扩展的点加入到队列当中
				que[tail].x = tx; que[tail].y = ty;
				tail++; 
			} 
		}
		head++;
	} 
	//最后输出岛屿的大小
	printf("%d\n",sum);
	getchar();getchar();
	return 0; 
} 




