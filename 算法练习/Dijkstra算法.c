//�÷����ı���Ϊ��Դ���·���㷨�����㷨����˼�룬ÿ���ҵ���Դ�������һ���㣬Ȼ���Զ���Ϊ���Ľ�����չ
//���յõ�Դ�㵽�������е�����·�����㷨ʵ������
#include<stdio.h>
int main(){
	int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
	int inf = 999999999;//��ʾ���ֵ
	scanf("%d %d",&n,&m);
	//ʹ���ڽӾ���ķ�ʽ���洢 
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(i == j) 
				e[i][j] = 0;
			else 
				e[i][j] = inf;
	//����ÿ���ߵ�ֵ
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2] = t3;
	} 
	
	//��ʼ��dis����
	for(i = 1; i <=n; i++)
		dis[i] = e[1][i];
		
	//book�����ʼ��
	for(i = 1; i <= n; i++){
		book[i] = 0;
	} 
	book[1] = 1;
	
	//Dijkstra�㷨����
	for(i = 1; i <= n-1; i++){//��ʾ�ɳڵĴ��� 
		//�ҵ���һ�Ŷ�������ĵ�Ķ��� 
		min = inf;
		for(j = 1; j <= n; j++){
			if(book[j] == 0 && dis[j] < min){
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		//�ɳڵ�ʵ�ֹ��� 
		for(v = 1; v <= n; v++){
			if(e[u][v] < inf){
				if(dis[v] > dis[u] + e[u][v])
					 dis[v] = dis[u] + e[u][v];
			}
		}
	} 
	//������ս��
	for(i = 1; i <= n; i++){
		printf("%d ",dis[i]);
	} 
	getchar();getchar();
	return 0;
} 
//���㷨ʵ�ֵĺ��Ĳ����ǣ�����ͨ��һ��forѭ��ȥ��������dis�����ҵ���1���������
//һ���㣬Ȼ�����������ɳڡ����㷨��ȱ���ǲ�����⸺��Ȩ������ 
