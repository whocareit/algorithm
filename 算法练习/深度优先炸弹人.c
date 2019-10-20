#include<stdio.h>
char a[20][21];
int book[20][20],max,mx,my,n,m;

//�����������Ȼ��ʼ��ɢ 
int getnum(int i,int j){
	int sum,x,y;
	sum = 0;//���ڼ������������Ŀ
	//�ֱ����ĸ�����ʼ���м���
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//���Ͻ��м��� 
		x--;
	} 
	
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//���½��м��� 
		x++;
	} 
	
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//���ҽ��м��� 
		y++;
	} 
	
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//������м��� 
		y--;
	} 
	return sum; 
}

void dfs(int x, int y){
	//����һ�����ڱ�ʾ�ߵķ�������飬�ߵķ���
	//��Ҫ��һ���Ĵ��� 
	int next[4][2]={
			{0,1}, //���� 
			{1,0}, //���� 
			{0,-1}, //���� 
			{-1,0}, //���� 
	};
	
	int k,sum,tx,ty;
	
	//����õ��������ĵ�������Ϊ 
	sum = getnum(x,y);
	
	if(sum > max){
		//�������ֵ���Ҽ�¼�õ������ 
		max = sum;
		mx = x;
		my = y;
	} 
	
	for(k = 0 ; k <= 3; k++){
		//��ʾ��һ���������� 
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if(tx < 0 || tx > n-1 || ty < 0 || ty > m-1){
			continue;
		} 
		//�ж��Ƿ�Χǽ�����Ѿ��߹�
		if(a[tx][ty] == '.' && book[tx][ty] == 0){
			book[tx][ty] = 1;
			dfs(tx,ty); //��ʼ������һ���� 
		} 
	}
	return; 
}

int main(){
	int startx,starty,i;
	//����n,m��ʾ�ж��������У��Լ���ʼ�������λ��
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	
	//����n���ַ�
	for(i = 0; i <= n-1; i++){
		scanf("%s",a[i]);
	} 
	
	//��С�����ڵ�λ�ÿ�ʼ���г���
	book[startx][starty] == 1;
	max = getnum(startx,starty);
	mx = startx;
	my = starty;
	dfs(startx,starty);
	
	printf("��ը���˷���(%d,%d)���������ĵ�����ĿΪ%d",mx,my,max);
	getchar(); getchar();
	return 0; 
}






