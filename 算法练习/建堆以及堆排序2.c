#include<stdio.h>
int h[101]; //用于存放堆中的数组
int n;//表示堆大小 


//交换函数 
void swap(int x,int y){
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;
} 

//向下调整函数,此时的向下调整是最大堆的调整过程 
void shifdown(int i){
	int t,flag = 0;
	// 当i结点有儿子(即至少有左儿子)并且有需要即flag=0即可调整
	while(2*i <= n && flag == 0){ 
		//首先判断其与左儿子之间的大小关系 
		if(h[i] < h[2*i])
			t = i*2;
		else 
			t = i;
		if(i*2+1 <= n){ //判断是否有右儿子 
			if(h[t] < h[2*i + 1])
				t = 2*i+1;
		}
		if(t != i){
			swap(t,i);
			i = t;
		}
		else
			flag = 1;
	} 
	return;
}

//建堆函数
void create(){
	int i;
	//从最后一个非叶结点到第一个结点依次向下调整 
	for(i = n/2; i >= 1; i--){
		shifdown(i);
	}
	return;
} 

//堆排序
void heapsort(){
	while(n > 1){
		swap(1,n);
		n--;
		shifdown(1);
	}
	return;
} 

int main(){
	int i,num;
	scanf("%d",&num);
	
	for(i = 1; i <= num; i++)
		scanf("%d",&h[i]);
	n = num;
	//建堆函数 
	create(); 
	//堆排序
	heapsort();
	//输出
	for(i = 1; i <= num; i++)
		printf("%d ",h[i]);
	getchar();
	getchar();
	return 0;
}
//第二种方式输出堆排序的方式与第一种不同，首先此时建立的堆为最大堆，其次是
//再进行h[1]与h[n]之间的互换，此时h[n]为最大，切记，h[1]被交换后还是需要符 
//合堆的特性因此需要进行调整。 
