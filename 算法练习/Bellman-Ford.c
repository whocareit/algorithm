//�ڸ÷����л������Ƿ��и�Ȩ��·����
#include<stdio.h>
int main(){
	int dis[10],bak[10],i,k,n,m,u[10],v[10],w[10],check,flag;
	int inf = 999999999;
	scanf("%d %d",&n,&m);
	//�����
	for(i = 1; i <= m; i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	} 
	//��ʼ��dis����
	for(i = 1; i <= n; i++)
		dis[i] = inf;
	dis[1] = 0;
	//�㷨����
	for(k = 1; k <= n; k++){
		check = 0;
		for(i = 1; i <= m; i++){
			if(dis[v[i]] > dis[u[i]] + w[i]){
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}
		}
		if(check == 0) break;
	} 
	//��⸸Ȩ��¸����
	flag = 0;
	for(i = 1; i <= m; i++){
		if (dis[v[i]] = dis[u[i]] + w[i]) flag = 1;
	} 
	if(flag == 1)
		printf("��ͼ���и�Ȩ��·");
	else{
		//������ս��
		for(i = 1; i <= n; i++)
			printf("%d ",dis[i]); 
	} 
	getchar();getchar();
} 
