#include<stdio.h>
int main(){
	int e[10][10],k,i,j,n,m,t1,t2,t3;
	int inf = 99999999; //用inf表示无穷大
	//读入n和m,n表示顶点数，m表示边数
	scanf("%d %d",&n,&m);
	
	//使用邻接矩阵对地图进行初始化
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j)
				e[i][j] = 0;
			else
			    e[i][j] = inf;
	//读入边
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2] = t3;
	} 
	
	//Floyd-warshall核心内容
	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				if(e[i][k] < inf && e[k][j] < inf && e[i][j] > e[i][k]+e[k][j]) 
					e[i][j] = e[i][k]+e[k][j];
					
	//输出最终结果
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			printf("%10d",e[i][j]);
		}
		printf("\n");
	} 
	
	return 0;
}
