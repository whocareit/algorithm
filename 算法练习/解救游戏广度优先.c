#include<stdio.h>
struct note{
	int x; //������
	int y; //������
	int f; //�����ڶ����еı��
	int s; //���� 
};

int main(){
	struct note que[2501]; //��ͼ�Ĵ�С������2501,���е���չ������2500
	
	int a[51][51] = {0},book[51][51] = {0};
	//�����ĸ���Ҫ�ߵķ���ֱ�Ϊ�� �� �� �� 
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
	int head,tail;
	int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
	scanf("%d %d",&n,&m); //��ͼ�Ĵ�С
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			scanf("%d",&a[i][j]);
		}
	} 
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//���г�ʼ��
	head = 1;tail = 1;
	//���������Ӳ�����Թ��������
	que[tail].x = startx; que[tail].y = starty;
	que[tail].f = 0; que[tail].s = 0;
	tail++;
	book[startx][starty] = 1;
	
	flag = 0; //�������Ƿ񵽴�ָ���㣬0��ʾδ���1��ʾ�ѵ���
	//�����в�Ϊ��ʱ��ѭ��
	while(head < tail){
		for(k = 0; k <= 3; k++){
			//������һ���������
			tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			//�ж��Ƿ�Խ��
			if(tx < 1 || tx > n || ty < 1 || ty > m){
				continue;
			} 
			//�жϸõ��Ƿ���·�ϣ�����û�������ϰ���
			if(a[tx][ty] == 0 && book[tx][ty] == 0){
				//�ڿ����У�ÿ��ֻ�����һ�Σ������Ѳ�ͬ������Ҫ��book���黹ԭ
				book[tx][ty] = 1;
				//�����µĵ㵽������
				que[tail].x = tx;
				que[tail].y = ty;
				que[tail].f = head;
				que[tail].s = que[head].s + 1;
				tail++; 
			} 
			
			if(tx == p && ty == q){
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			break;
		head++;
		}
	
	printf("%d",que[tail-1].s);
	getchar();getchar();
	return 0; 
} 
