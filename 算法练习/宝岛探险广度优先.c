#include<stdio.h>

struct note{
	int x;// ������
	int y;//������ 
};

int main(){
	//��չ����Ĵ�С 
	struct note que[2501];
	int head,tail;
	int a[51][51]; //��ͼ��С
	int book[51][51] = {0}; // ����ͼ�����
	int i,j,k,sum,max = 0,mx,my,n,m,startx,starty,tx,ty;
	//���巽������
	int next[4][2] = {
		{0,1}, //����
		{1,0}, //����
		{0,-1}, //����
		{-1,0}, //���� 
	};
	
	//����n,m�Լ���ʼ����
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	
	//�����ͼ
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
		 	scanf("%d",&a[i][j]);
		 	
	//���г�ʼ��
	head = 1; tail = 1;
	//������в��뽵������ʼ����
	que[tail].x = startx; que[tail].y = starty;
	tail++;
	book[startx][starty] = 1;
	sum = 1;
	
	//�����в�Ϊ��ʱ��ѭ��
	while(head < tail){
		for(k = 0; k <= 3; k++){
			//������һ��������� 
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			
			//�жϸõ��Ƿ�Խ��
			if(tx < 1 || tx > n || ty < 1 || ty > m){
				continue;
			} 
			
			//�жϸõ��Ƿ�Ϊ½�ز����Ƿ��Ѿ��߹�
			if(a[tx][ty] > 0 && book[tx][ty] == 0){
				sum++;
				//ÿ����ֻ����ջһ�Σ�������Ҫ��Ǹõ�
				book[tx][ty] = 1;
				//������չ�ĵ���뵽���е���
				que[tail].x = tx; que[tail].y = ty;
				tail++; 
			} 
		}
		head++;
	} 
	//����������Ĵ�С
	printf("%d\n",sum);
	getchar();getchar();
	return 0; 
} 




