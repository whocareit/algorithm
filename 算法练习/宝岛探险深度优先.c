#include<stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y){
	//定义一个方向数组,方向为右 下 左 上 
	int next[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0} 
	}; 
	
	int k,tx,ty;
	for(k = 0; k <= 3; k++){
		//计算下一个点的坐标
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 1 || tx > n || ty < 1 || ty > m){
			continue;
		} 
		if(a[tx][ty] > 0 && book[tx][ty] == 0){
			sum++;
			book[tx][ty] = 1;
			dfs(tx,ty); //尝试下一个点 
		}
	} 
	return;
}

int main(){
	int i,j,startx,starty;
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	
	//读入地图
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d",&a[i][j]);
			
	book[startx][starty] = 1;
	sum = 1;
	//从降落的位置开始
	dfs(startx,starty);
	printf("%d",sum);
	getchar();getchar();
	return 0; 
} 
