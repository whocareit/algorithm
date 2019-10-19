#include<stdio.h>
struct note{
	int x;  //�洢������ 
	int y;	//�洢������ 
}; 

char a[20][21];

//getnum����������ȥ��ȡը�������Ķ���,i j��ʾ������չ�ĵ� 
int getnum(int i,int j){
	int sum,x,y;
	//sum���ڼ�������ʾ��������ĵ��˵������������ʼ��Ϊ0 
	sum = 0; 
	//����ͳ�ƿ�������ĵ��˵�����
	
	x = i; y = j;
	while(a[x][y] != '#'){
		//�����ǰ���ǵ��˾ͽ��м���
		if(a[x][y] == 'G')
			sum++;
		//���Ͻ���ͳ�� 
		x--; 
	} 
	
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G')
			sum++;
		//���½���ͳ�� 
		x++;
	}
	
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G')
			sum++;
		//�������ͳ�� 
		y--;
	}
	
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G')
			sum++;
		//���ҽ���ͳ�� 
		y++;
	}
	return sum; 
}


int main(){
	struct note que[401];
	int head,tail;
	//����һ��������� 
	int book[20][20] = {0};
	int i,j,k,sum,max = 0,mx,my,n,m,startx,starty,tx,ty;
	
	//�����ͼ�Ͽ��߷��� �� �� �� �� 
	int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}}; 
	
	//�����ͼ��С���ʼλ�� 
	scanf("%d %d %d %d",&n,&m,&startx,&starty); 
	
	for(i = 0; i <= n-1; i++)
			scanf("%s",a[i]);
	 
	 //���г�ʼ��
	 head = 1;
	 tail = 1;
	 que[tail].x = startx;
	 que[tail].y = starty;
	 tail++;
	 book[startx][starty] = 1;
	 max = getnum(startx,starty);
	 //mx my ����ȥ��¼������λ�� 
	 mx = startx;
	 my = starty;
	 //�����в�Ϊ��ʱִ��
	 while(head < tail){
	 	//������һ�������λ��
		 for(k = 0; k <= 3; k++){
		 	tx = que[head].x + next[k][0];
			ty = que[head].y + next[k][1];
			 
			 //�ж��Ƿ�Խ��
			 if(tx < 0 || tx > n || ty < 0 || ty > m){
			 	continue;
			 } 
			 
			 //�ж��Ƿ�Ϊ���ߵ����Ƿ������߹�
			 if(a[tx][ty] == '.' && book[tx][ty] == 0){
			 	//���еĵ㶼ֻ�������һ�Σ������Ҫ�����Щ���Ѿ��߹� 
			 	book[tx][ty] = 1;
			 	//��������չ�ĵ㵽������
				 que[tail].x = tx;
				 que[tail].y = ty;
				 tail++;
				 
				 //ͳ�Ƶ�ǰ���������ĵ�������
				 sum = getnum(tx,ty);
				 if(sum > max){
				 	max = sum;
				 	//��¼��ʱ������
					 mx = tx;
					 my = ty; 
				 } 
			 } 
		 }
		 head++; //��һ������չ֮��Ҫ�Խ���head++ 
	 } 
	 
	 //�������������
	 printf("��ը������(%d,%d)�����������������������Ϊ%d",mx,my,max);
	 getchar(); getchar();
	 return 0; 
}




