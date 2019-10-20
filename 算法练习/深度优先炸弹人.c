#include<stdio.h>
char a[20][21];
int book[20][20],max,mx,my,n,m;

//给出点的坐标然后开始扩散 
int getnum(int i,int j){
	int sum,x,y;
	sum = 0;//用于计算消灭敌人数目
	//分别向四个方向开始进行计数
	x = i; y = j;
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//向上进行计数 
		x--;
	} 
	
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//向下进行计数 
		x++;
	} 
	
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//向右进行计数 
		y++;
	} 
	
	while(a[x][y] != '#'){
		if(a[x][y] == 'G'){
			sum++;
		}
		//向左进行计数 
		y--;
	} 
	return sum; 
}

void dfs(int x, int y){
	//定义一个用于表示走的方向的数组，走的方向
	//需要有一定的次序 
	int next[4][2]={
			{0,1}, //向右 
			{1,0}, //向下 
			{0,-1}, //向左 
			{-1,0}, //向上 
	};
	
	int k,sum,tx,ty;
	
	//计算该点可以消灭的敌人总数为 
	sum = getnum(x,y);
	
	if(sum > max){
		//更新最大值并且记录该点的坐标 
		max = sum;
		mx = x;
		my = y;
	} 
	
	for(k = 0 ; k <= 3; k++){
		//表示下一个结点的坐标 
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx < 0 || tx > n-1 || ty < 0 || ty > m-1){
			continue;
		} 
		//判断是否围墙或者已经走过
		if(a[tx][ty] == '.' && book[tx][ty] == 0){
			book[tx][ty] = 1;
			dfs(tx,ty); //开始尝试下一个点 
		} 
	}
	return; 
}

int main(){
	int startx,starty,i;
	//输入n,m表示有多少行与列，以及开始点的坐标位置
	scanf("%d %d %d %d",&n,&m,&startx,&starty);
	
	//读入n行字符
	for(i = 0; i <= n-1; i++){
		scanf("%s",a[i]);
	} 
	
	//从小人所在的位置开始进行尝试
	book[startx][starty] == 1;
	max = getnum(startx,starty);
	mx = startx;
	my = starty;
	dfs(startx,starty);
	
	printf("将炸弹人放在(%d,%d)，最多消灭的敌人数目为%d",mx,my,max);
	getchar(); getchar();
	return 0; 
}






