#include<stdio.h>
int e[101][101];
int match[101];
int book[101];
int n,m;
int dfs(int u){
	int i;
	for(i = 1; i <= n; i++){
		if(book[i] == 0 && e[u][i] == 1){
			book[i] = 1;//标记该点已经被访问过 
			//如果点i未被配对或者已经找到了新的配对 
			if( match[i] == 0 || dfs(match[i])){
				//更新配对关系
				match[i] = u;
				return 1; 
			}
		}
	}
	return 0;
}

int main(){
	int i,j,t1,t2,sum = 0;
	scanf("%d %d",&n,&m);
	for(i = 1; i <= m; i++){ //读入边 
		scanf("%d %d",&t1,&t2);
		e[t1][t2] = 1;
	}
	for(i = 1; i <= n; i++)
		match[i] = 0;
	for(i = 1; i <=n; i++){
		for(j = 1; j <= n; j++)
			book[j] = 0;
		if(dfs(i))
			sum++;
	}
	printf("%d",sum);
	getchar();getchar();
	return 0;
}
