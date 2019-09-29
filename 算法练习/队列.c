#include<stdio.h>
int main(){
	int q[102] = {0,6,3,1,7,5,8,9,2,4},head,tail;
	head = 1;
	//这里需要出队列的数有九个，当打印出第一个数后，让head+1的值添加到这个队列的尾部 
	tail = 10;
	while(head < tail){ //当队列不为空的时候执行循环 
		//打印出队列的首位然后将第二个数插入到队尾
		printf("%d",q[head]);
		//数组指针加1 
		head++;
		q[tail] = q[head];
		tail++;
		head++; 
	}
	getchar();getchar();
	return 0;
}
//队列是一种特殊的线性结构，只允许在队列的首部进行删除操作，这被称为出队，在队尾进行插入操作叫做入队 
//当队列中没有元素的时候即(head = tail)时，就是空队列。队列的特点就是先进先出 
