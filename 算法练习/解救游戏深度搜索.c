//游戏描述：以最快的速度到达指定的点，将地图存储在一个二维数组中，地图中的障碍物
//用数字1代替，其余的点用数字1代替，求从数组中的一个点到另外一个点之间的最短距离 
#include<stdio.h>
//生命全局变量,q p代表目的地 m n代表存储数组的大小 
int n,m,p,q,min=99999999; 
//数组a用于表示地图  数组book用于标记 
int a[51][51],book[51][51]; 


//深度遍历找到最段路径的方法 
void dfs(int x,int y, int step){
	//用于表示某个点可以走的四个方向 
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
	
	int tx,ty,k;
	//判断是否到达指定的位置
	if(x==p && y==q){
		//更新最小值
		if(step < min){
			min = step;
		} 
		return;
	} 
	
	//枚举四种走法
	for(k = 0; k <= 3; k++){
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 1|| tx > n || ty < 1 || ty > m){
			continue;	
		} 
		if(a[tx][ty] == 0 && book[tx][ty] == 0){
			book[tx][ty] = 1;
			dfs(tx, ty, step+1);
			book[tx][ty] = 0;
		}
	} 
	return;
} 

int main(){
	int i,j,startx,starty;
	//读入地图大小 
	scanf("%d %d",&n,&m); 
	//读入地图内容
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			scanf("%d",&a[i][j]);
		}
	} 
	//读入开始点的位置与指定位置
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//从起点开始搜索  
	book[startx][starty] = 1;
	dfs(startx,starty,0);
	
	//输出最短步数
	printf("%d",min);
	getchar();getchar();
	return 0; 
	 
} 



