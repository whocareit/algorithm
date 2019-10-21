//��ɫ���������̽������,ֻ��Ҫ��������½��ȫ������Ϊͬһ����ɫ���� 
//��ʱ����ɫֵ��һ�����ִ��� 
#include<stdio.h>
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x,int y,int color){
	//����һ����������,����Ϊ�� �� �� �� 
	int next[4][2] = {
		{0,1},{1,0},{0,-1},{-1,0} 
	};
	int k,tx,ty;
	a[x][y] = color; //������������ɫ
	for(k = 0; k <= 3; k++){
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
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
	//�����ͼ
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d",&a[i][j]);
			
	book[startx][starty] = 1;
	sum++;
	//�ӽ����λ�ÿ�ʼ������ɫ
	dfs(startx,starty,-1);
	//����Ѿ�Ⱦɫ��ĵ�ͼ
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			printf("%3d",a[i][j]); //3d�涨����ĸ�ʽ 
		}
		printf("\n");
	} 
	getchar();getchar();
	return 0;
}
