//malloc函数，从内存中申请分配指定字节大小的空间
//int *p  p = (int *) malloc(sizeof(int)); 表示成功的分配了一个动态的空间
//malloc函数的返回类型是 void *类型， void * 表示未确定类型的指针

//下面表示使用一个结构体来表示链表
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next; //表示指向下一个地址的指针 
}; 

int main(){
	struct node *p, *q, *t, *head;
	int i,n,a;
	scanf("%d",&n);//输入一个数,表示该链表的长度为多少 
	head = NULL;//头指针初始化
	for(i = 1; i <= n; i++){
		scanf("%d",&a);
		//动态申请一个空间，用来存放某个结点，并且使用临时指针p指向这个结点 
		p = (struct node *) malloc (sizeof(struct node));
		p->data = a; //将输入的值放在结构体中的data中
		p->next = NULL; //设置下一个结点为空，也就是当前结点的后继指针为空
		if(head == NULL) { //如果头指针为空 
			head = p; //如果是头指针，就将头指针指向这个结点 
		}else{
			q->next = p;  //如果不是头指针，就将上一个结点的后继指针指向当前结点 
		}
		q = p; 
	}  
	
	//输出链表中的所有数
	t = head; //为一个临时标量，用来输出整个链表
	while( t != NULL){
		printf("%d ",t->data);
		t = t->next;
	} 
	
	getchar(); getchar();
	return 0;
} 
