#include<stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x, int y, int color){
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	
	int k,tx,ty;
	a[x][y] = color; //对格子进行着色
	for(k = 0; k <= 3; k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 1 || tx > n || ty < 1 || ty >m){
			continue;
		} 
		//判断是否为陆地
		if(a[tx][ty] > 0 && book[tx][ty] == 0){
			sum++;
			book[tx][ty] = 1;
			dfs(tx,ty,color);
		} 
	} 
	return 0;
}

int main(){
	int i,j,num = 0;
	scanf("%d %d",&n,&m);
	//读入地图 
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++ )
			scanf("%d",&a[i][j]);
	 //对于每个大于0的点尝试进行dfs染色
	 for(i = 1; i <= n; i++){
	 	for(j = 1; j <= m; j++){
	 		if(a[i][j] > 0){
	 			num--; //小岛需要染色的编号
				//每发现一个小岛应染不同的颜色，因此每次要-1
				book[i][j] = 1;
				dfs(i,j,num); 
			 } 
		 }
	 } 
	 
	 //最后输出已经染色的地图
	 for(i = 1; i <= n; i++){
	 	for(j = 1; j <= m; j++){
	 		printf("%3d",a[i][j]); 
		 } 
	 printf("\n");
	}
	
	//输出小岛的个数
	printf("有%d个小岛",-num);
	getchar();getchar();
	return 0; 
}



