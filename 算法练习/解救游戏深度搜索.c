//��Ϸ�������������ٶȵ���ָ���ĵ㣬����ͼ�洢��һ����ά�����У���ͼ�е��ϰ���
//������1���棬����ĵ�������1���棬��������е�һ���㵽����һ����֮�����̾��� 
#include<stdio.h>
//����ȫ�ֱ���,q p����Ŀ�ĵ� m n����洢����Ĵ�С 
int n,m,p,q,min=99999999; 
//����a���ڱ�ʾ��ͼ  ����book���ڱ�� 
int a[51][51],book[51][51]; 


//��ȱ����ҵ����·���ķ��� 
void dfs(int x,int y, int step){
	//���ڱ�ʾĳ��������ߵ��ĸ����� 
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
	
	int tx,ty,k;
	//�ж��Ƿ񵽴�ָ����λ��
	if(x==p && y==q){
		//������Сֵ
		if(step < min){
			min = step;
		} 
		return;
	} 
	
	//ö�������߷�
	for(k = 0; k <= 3; k++){
		//������һ���������
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
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
	//�����ͼ��С 
	scanf("%d %d",&n,&m); 
	//�����ͼ����
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			scanf("%d",&a[i][j]);
		}
	} 
	//���뿪ʼ���λ����ָ��λ��
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//����㿪ʼ����  
	book[startx][starty] = 1;
	dfs(startx,starty,0);
	
	//�����̲���
	printf("%d",min);
	getchar();getchar();
	return 0; 
	 
} 



