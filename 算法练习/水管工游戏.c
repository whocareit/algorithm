//游戏描述：一些矩形土地备分为N*M的单位正方形， 目前已经在
//土地中埋下了一些水管，水管的型号有两种，要求创造一条从（1，1）
//到（n，m)的连通管道的方式
//现记录水管的六种形态，将其命名为1,2,3,4,5,6
#include<stdio.h>
int a[51][51]; //假设土地的大小不超过50*50
int book[51][51],n,m,flag = 0;
void dfs(int x.int y,int front){
	//当到达(n,m)这个点时，已经产生了一种铺设方案 
	if(x == n && y == m+1){
		flag = 1;
		return ;
	} 
	
	//判断是否越界
	if(x < 1 || x > n || y < 1 || y > m){
		continue;
	} 
	
	//判断这个管道是否在路径中使用过
	if(book[x][y] == 1)
		return;
	book[x][y] = 1; //标记使用当前这个管道
	
	//当前水管是直管的情况
	if(a[x][y] >= 5 && a[x][y] <=6){
		//front表示进水口在左边的情况 
		if(front == 1){
			dfs(x,y+1,1);
		}
		if(front == 2){
			dfs(x+1,y,2);
		}
		if(front == 3){
			dfs(x,y-1,3);
		}
		if(front == 4){
			dfs(x-1,y,4); 
		}
	} 
	
	//当前水管是弯管的情况
	if(a[x][y] >= 1 && a[x][y] <= 4){
		if(front == 1){
			dfs(x+1,y,2); //3号 
			dfs(x-1,y,4); //4号 
		}
		if(front == 2){
			dfs(x,y+1,1); //1号 
			dfs(x,y-1,3); //4号 
		}
		if(front == 3){
			dfs(x-1,y,4); //1号 
			dfs(x+1,y,2); //2号 
		}
		if(front == 4){
			dfs(x,y+1,1); //2号
			dfs(x,y-1,3); //3号 
		} 
	} 
	book[x][y] = 0; //取消标记 
	return ;
} 

int main(){
	int i, j, num = 0;
	scanf("%d %d",&n,&m);
	//读入地图
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d",&a[i][j]);
			
	dfs(1,1,1);
	if(flag == 0){
		printf("impossible\n");
	} else {
		pritf("铺设方案为：\n");
	}
	getchar();getchar();
	return 0;
}




