//�ڴ洢һ������ͼʱ������ͼ���ڽӾ��󴢴淨�����1�ŵ������·�ߣ����ֵΪ1
//�Լ����Լ�Ϊ0�����û��·�߾�Ϊ����� 

#include<stdio.h>
int book[101],sum,n,e[101][101];
void dfs(int cur) { //cur �������ڵĶ����� 
	int i;
	printf("%d ",cur);
	sum++; //ÿ�η���һ������sum�ͼ�1
	if(sum == n) return; //�����еĶ��㶼�����ʹ�֮���ֱ���˳�
	for(i = 1; i <= n; i++){
		//�жϵ�ǰ�Ķ���cur�Ƿ��бߣ����ж϶���i�Ƿ��ѷ��ʹ�
		if(e[cur][i] == 1 && book[i] == 0){
			book[i] = 1;
			dfs(i);  
		}
	} 
	return;
}

int main(){
	int i,j,m,a,b;
	scanf("%d %d",&n,&m); 
	//��ʼ����ά����
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
		 	if(i == j) e[i][j] = 0;
			 else e[i][j] = 9999999; //����9999999Ϊ�����
			 
	//���붥��֮��ı�
	for(i = 1; i <= m; i++){
		scanf("%d %d",&a,&b);
		e[a][b] = 1;
		e[b][a] = 1; //��Ϊ��ͼΪ����ͼ�������Ҫ��e[b][a]Ҳ��ֵΪ1 
	} 
	
	book[1] = 1; //��һ�Ŷ��㿪ʼ����
	dfs(1);
	getchar();getchar();
	return 0; 
}
