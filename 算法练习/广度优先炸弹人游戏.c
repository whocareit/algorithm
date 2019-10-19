#include<stdio.h>
struct note{
	int x;  //存储横坐标 
	int y;	//存储纵坐标 
}; 

char a[20][21];

//getnum函数，用于去获取炸弹数量的多少,i j表示可以扩展的点 
int getnum(int i,int j){
	int sum,x,y;
	//sum用于计数，表示可以消灭的敌人的数量，将其初始化为0 
	sum = 0; 
	//向上统计可以消灭的敌人的数量
	
	x = i; y = j;
	while(a[x][y] != '#'){
		//如果当前点是敌人就进行计数
		if(a[x][y] == 'G')
			sum++;
		//向上进行统计 
		x--; 
	} 
	
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G')
			sum++;
		//向下进行统计 
		x++;
	}
	
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G')
			sum++;
		//向左进行统计 
		y--;
	}
	
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G')
			sum++;
		//向右进行统计 
		y++;
	}
	return sum; 
}


int main(){
	struct note que[401];
	int head,tail;
	//声明一个标记数组 
	int book[20][20] = {0};
	int i,j,k,sum,max = 0,mx,my,n,m,startx,starty,tx,ty;
	
	//定义地图上可走方向 下 右 左 上 
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; 
	
	//读入地图大小与初始位置 
	scanf("%d %d %d %d",&n,&m,&startx,&starty); 
	
	for(i = 0; i <= n-1; i++)
			scanf("%s",a[i]);
	 
	 //队列初始化
	 head = 1;
	 tail = 1;
	 que[tail].x = startx;
	 que[tail].y = starty;
	 tail++;
	 book[startx][starty] = 1;
	 max = getnum(startx,starty);
	 //mx my 用于去记录坐标点的位置 
	 mx = startx;
	 my = starty;
	 //当队列不为空时执行
	 while(head < tail){
	 	//尝试下一个坐标点位置
		 for(k = 0; k <= 3; k++){
		 	tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			 
			 //判断是否越界
			 if(tx < 0 || tx > n || ty < 0 || ty > m){
			 	continue;
			 } 
			 
			 //判断是否为可走地与是否曾经走过
			 if(a[tx][ty] == '.' && book[tx][ty] == 0){
			 	//所有的点都只能入队列一次，因此需要标记这些点已经走过 
			 	book[tx][ty] = 1;
			 	//插入新扩展的点到队列中
				 que[tail].x = tx;
				 que[tail].y = ty;
				 tail++;
				 
				 //统计当前点可以消灭的敌人数量
				 sum = getnum(tx,ty);
				 if(sum > max){
				 	max = sum;
				 	//记录此时的坐标
					 mx = tx;
					 my = ty; 
				 } 
			 } 
		 }
		 head++; //当一个点扩展之后要对进行head++ 
	 } 
	 
	 //最后输出结果即可
	 printf("将炸弹放在(%d,%d)处，可以消灭的最大敌人数量为%d",mx,my,max);
	 getchar(); getchar();
	 return 0; 
}




