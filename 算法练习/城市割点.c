//���Ķ��壺����ĳ������u,�����������һ������v��������u�Ķ��ӣ���ʹ��
//low[v] >= num [u]�������ܻص����ȣ���ôu��Ϊ���
#include<stdio.h>
int n,m,e[9][9],root;
int num[9],low[9],flag[9],index; //index��������ʱ����ĵ���
//���������н�Сһ�����ĺ���
int min(int a,int b){
	return a > b ? b : a;
} 
//����㷨�ĺ���
void dfs(int cur, int father){ //��Ҫ����������������ǰ�����ź͸�������
	 int child = 0,i; //child���ڼ�¼���������е�ǰ����cur�Ķ��Ӹ���
	 
	 index++; //ʱ�����1
	 num[cur] = index; //��ǰ�ڵ�cur��ʱ��� 
	 low[cur] = index; //��ǰ�ڵ��ܹ����ʵ����綥���ʱ������տ�ʼ�����Լ�
	 for(i = 1; i <= n; i++){
	 	if(e[cur][i] == 1){
	 		if(num[i] == 0){//�������i��ʱ���Ϊ0��˵������i��û�б����ʹ� 
	 			//���������ĽǶ���˵����ʱ��iΪcur�Ķ���
				 child++;
				 dfs(i,cur); //����������ȱ���
				 //���µ�ǰ����cur�ܷ��ʵ������綥���ʱ���
				 low[cur] = min(low[cur],low[i]);
				 //�����ǰ���㲻�Ǹ��ڵ㲢������low[i]>=num[cur],��ǰ����Ϊ���
				 if(cur != root && low[i] >= num[cur])
				 	flag[cur] = 1;
				 //�����ǰ�����Ǹ��ڵ㣬���������и��ڵ�������������ӣ���ô������ڵ���Ǹ��
				 if(cur == root &&  child == 2)
				 	flag[cur] = 1; 
			 }
			 else if(i != father){
			 	//������㱻���ʹ�������������㲻�ǵ�ǰ����cur�ĸ��ף���˵��
				//��ʱ��iΪcur�����ȣ������Ҫ���µ�ǰ�ڵ�cur�ܷ��ʵ����綥���ʱ��� 
			 	low[cur] = min(low[cur],num[i]);
			 }
		 }
	 } 
	 return;
} 
int main(){
	int i,j,x,y;
	scanf("%d %d",&n,&m);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++) 
			e[i][j] = 0;
	for(i = 1; i <= m; i++){
		scanf("%d %d",&x,&y);
		e[x][y] = 1;
		e[y][x] = 1;
	}
	root = 1;
	dfs(1,root);
	for(i = 1; i <= n; i++){
		if(flag[i] == 1)
			printf("%d ",i);
	}
	getchar();getchar();
	return 0;
} 



