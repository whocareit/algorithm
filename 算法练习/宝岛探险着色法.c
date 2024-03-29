//着色法解决宝岛探险问题,只需要将经过的陆地全部命名为同一种颜色即可 
//此时的颜色值用一个数字代替 
#include<stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y,int color){
	//定义一个方向数组,方向为右 下 左 上 
	int next[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0} 
	};
	int k,tx,ty;
	a[x][y] = color; //对这个点进行着色
	for(k = 0; k <= 3; k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 1 || tx > n || ty < 1 || ty > m){
			continue;
		} 
		if(a[tx][ty] > 0 && book[tx][ty] == 0){
			sum++;
			book[tx][ty] = 1;
			dfs(tx,ty,color);
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
	sum++;
	//从降落的位置开始进行着色
	dfs(startx,starty,-1);
	//输出已经染色后的地图
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			printf("%3d",a[i][j]); //3d规定输出的格式 
		}
		printf("\n");
	} 
	getchar();getchar();
	return 0;
}
