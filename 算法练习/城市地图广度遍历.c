#include<stdio.h>
struct note{
	int x; //���б�� 
	int s; //ת������ 
}; 

int main(){
	struct note que[2501];
	int e[51][51] = {0},book[51] = {0};
	int head,tail;
	int i,j,n,m,a,b,cur,start,end,flag = 0;
	scanf("%d %d %d %d",&n,&m,&start,&end);
	//��ʼ������ڽӾ���
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j) 
				e[i][j] = 0;
			else 
				e[i][j] = 99999999;
	
	//�������֮��ĺ���
	for(i = 1; i <= m; i++){
		scanf("%d %d",&a,&b);
		//������������ͼ
		e[a][b] = 1;
		e[b][a] = 1; 
	} 
	
	//���г�ʼ��
	head = 1;
	tail = 1; 
	//��start�ų��г�������start�ų��м������ 
	que[tail].x = start;
	que[tail].s= 0;
	tail++;
	book[start] = 1;
	//�����в�Ϊ��ʱ
	while(head < tail){
		cur = que[head].x; //��ǰ���е��׳��б��
		for(j = 1; j <= n; j++){ //��1~nһ�γ��� 
			if(e[cur][j] != 9999999 && book[j] == 0){
				//�������cur������j�к��ಢ�ҳ���j���ڶ����У������j��� 
				que[tail].x = j;
				que[tail].s = que[head].s + 1; //ת������
				tail++;
				//��ǳ���j�Ѿ��ڶ����� 
				book[j] = 1; 
			}
			if(que[tail-1].x == end){
				flag = 1;
				break;
			}
		} 
		if(flag == 1){
			break;
		}
		head++; //��һ������չ������head���ܼ�����չ 
	}
	
	printf("%d",que[tail-1].s);
	getchar();getchar();
	return 0; 
}



