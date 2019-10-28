#include<stdio.h>
int h[101]; //用于存放堆中的数组
int n; //用来存储堆中元素的个数，也就是堆的大小

//交换函数,用来交换两个堆中的元素 
void swap(int x, int y){
	int t; //中间交换变量 
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return ;
} 

//向下调整函数
void shiftdown(int i){ //传入一个需要向下调整的结点编号i，即如果传入1，则从堆的顶点开始 
	int t,flag = 0; //flag用于判断是否向下调整
	//当结点i有儿子（其实至少有左儿子）并且有需要继续调整时循环执行
	while(i*2 <= n && flag == 0){
		if(h[i] > h[i*2])
			t = i*2;
		else 
			t = i;
		//如果有右儿子，再对右儿子进行讨论
		if(i*2+1 <= n){
			if(h[t] > h[2*i + 1])
				t = 2*i + 1;
		} 
		if(t != i){
			swap(t,i);
			i = t;//更新i为刚才与他交换的儿子的结点编号，便于接下来的调整 
		} 
		else
			flag = 1; 
	} 
	return;
}

//建堆函数 
void create(){
	int i;
	//从最后一个非页结点到第一个结点一次进行向下调整
	for(i = n/2; i >= 1; i--){
		shiftdown(i);
	} 
	return;
}

//删除最大元素
int deletemax(){
	 int t;
	 t = h[1]; //用临时变量来记录堆顶点的值
	 h[1] = h[n];
	 n--;
	 shiftdown(1); //向下调整
	 return t; 
} 

int main(){
	int i,num;
	//读入要排序的数字的个数
	scanf("%d",&num);
	for(i = 1; i <= num; i++){
		scanf("%d",&h[i]);
	} 
	n = num;
	//建堆 
	create();
	
	//删除顶部元素，连续删除n次，其实质就是从小到大把数输出
	for(i = 1; i <= num; i++){
		printf("%d ",deletemax());
	} 
	getchar(); getchar();
	return 0;
}
//这种方式采用的排序是，通过一个deletemax函数因此删除最小数，最后输出所有的删除结果从而达到排序的目的 
