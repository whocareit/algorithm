#include<stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x, int y, int color){
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	
	int k,tx,ty;
	a[x][y] = color; //�Ը��ӽ�����ɫ
	for(k = 0; k <= 3; k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if(tx < 1 || tx > n || ty < 1 || ty >m){
			continue;
		} 
		//�ж��Ƿ�Ϊ½��
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
	//�����ͼ 
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++ )
			scanf("%d",&a[i][j]);
	 //����ÿ������0�ĵ㳢�Խ���dfsȾɫ
	 for(i = 1; i <= n; i++){
	 	for(j = 1; j <= m; j++){
	 		if(a[i][j] > 0){
	 			num--; //С����ҪȾɫ�ı��
				//ÿ����һ��С��ӦȾ��ͬ����ɫ�����ÿ��Ҫ-1
				book[i][j] = 1;
				dfs(i,j,num); 
			 } 
		 }
	 } 
	 
	 //�������Ѿ�Ⱦɫ�ĵ�ͼ
	 for(i = 1; i <= n; i++){
	 	for(j = 1; j <= m; j++){
	 		printf("%3d",a[i][j]); 
		 } 
	 printf("\n");
	}
	
	//���С���ĸ���
	printf("��%d��С��",-num);
	getchar();getchar();
	return 0; 
}



