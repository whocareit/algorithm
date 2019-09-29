#include<stdio.h> 

struct queue{
	int array[101];
	int head;
	int tail;
};
int main(){
	struct queue q;
	int i;
	q.head = 1;
	q.tail = 1;
//	将队列的初始值设置为1，最后在依次添加数据到队尾 
	for(i = 1; i <= 9; i++){
		scanf("%d",&q.array[q.tail]);
		q.tail++;//执行完最后一次后剩余的数组的最后一个位置并没有值 
	}
	while(q.head < q.tail){ //当队列不为空时执行下面的程序 
		printf("%d",q.array[q.head]);
		q.head++;
		q.array[q.tail] = q.array[q.head];
		q.tail++;
		q.head++; 
	} 
	getchar();getchar();
	return 0;
}
//就相当于将其封装在一个对象中，然后再如同上面的值一样去输出这个结果即可 
