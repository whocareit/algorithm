#include<stdio.h>
int main(){
	int n,m,i,j,k,min,t1,t2,t3;
	int e[7][7],dis[7],book[7] = {0};
	int inf = 99999999;
	int count = 0,sum = 0;
	
	//����n m
	scanf("%d %d",&n,&m);
	 
	//��ʼ��
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			if(i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
	//��ʼ�����
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&t1,&t2,&t3);
		//����������ͼ��������Ҫ���򴢴� 
		e[t1][t2] = t3;
		e[t2][t1] = t3;
	}  
	
	//��ʼ��dis���飬��Ҫע����Ǵ�ʱ��һ�Ŷ��㵽��������ľ��� 
	for(i = 1; i <= n; i++)
		dis[i] = e[1][i];
		
	//Prim����
	//��1�Ŷ������������
	book[1] = 1; //��¼1�Ŷ����Ѿ�����������
	count++;
	//����̾��� 
	while(count < n){
		min = inf;
		for(i = 1; i <= n; i++){
			if(book[i] == 0 && dis[i] < min){
				min = dis[i];
				j = i;
			}
		}
		book[j] = 1;
		count++;
		sum = sum + dis[j];
		//ɨ�赱ǰ����j���еıߣ�����jΪ�м�㣬������������ÿ����������ľ���
		for(k = 1; k <= n; k++){
			if(book[k] == 0 && dis[k] > e[j][k])
				dis[k] = e[j][k];
		} 
	} 
	printf("%d\n",sum);
	getchar();
	getchar();
	return 0;
}




