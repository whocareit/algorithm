//��Ϸ������һЩ�������ر���ΪN*M�ĵ�λ�����Σ� Ŀǰ�Ѿ���
//������������һЩˮ�ܣ�ˮ�ܵ��ͺ������֣�Ҫ����һ���ӣ�1��1��
//����n��m)����ͨ�ܵ��ķ�ʽ
//�ּ�¼ˮ�ܵ�������̬����������Ϊ1,2,3,4,5,6
#include<stdio.h>
int a[51][51]; //�������صĴ�С������50*50
int book[51][51],n,m,flag = 0;
void dfs(int x.int y,int front){
	//������(n,m)�����ʱ���Ѿ�������һ�����跽�� 
	if(x == n && y == m+1){
		flag = 1;
		return ;
	} 
	
	//�ж��Ƿ�Խ��
	if(x < 1 || x > n || y < 1 || y > m){
		continue;
	} 
	
	//�ж�����ܵ��Ƿ���·����ʹ�ù�
	if(book[x][y] == 1)
		return;
	book[x][y] = 1; //���ʹ�õ�ǰ����ܵ�
	
	//��ǰˮ����ֱ�ܵ����
	if(a[x][y] >= 5 && a[x][y] <=6){
		//front��ʾ��ˮ������ߵ���� 
		if(front == 1){
			dfs(x,y+1,1);
		}
		if(front == 2){
			dfs(x+1,y,2);
		}
		if(front == 3){
			dfs(x,y-1,3);
		}
		if(front == 4){
			dfs(x-1,y,4); 
		}
	} 
	
	//��ǰˮ������ܵ����
	if(a[x][y] >= 1 && a[x][y] <= 4){
		if(front == 1){
			dfs(x+1,y,2); //3�� 
			dfs(x-1,y,4); //4�� 
		}
		if(front == 2){
			dfs(x,y+1,1); //1�� 
			dfs(x,y-1,3); //4�� 
		}
		if(front == 3){
			dfs(x-1,y,4); //1�� 
			dfs(x+1,y,2); //2�� 
		}
		if(front == 4){
			dfs(x,y+1,1); //2��
			dfs(x,y-1,3); //3�� 
		} 
	} 
	book[x][y] = 0; //ȡ����� 
	return ;
} 

int main(){
	int i, j, num = 0;
	scanf("%d %d",&n,&m);
	//�����ͼ
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d",&a[i][j]);
			
	dfs(1,1,1);
	if(flag == 0){
		printf("impossible\n");
	} else {
		pritf("���跽��Ϊ��\n");
	}
	getchar();getchar();
	return 0;
}




