#include<stdio.h>
#include<stdlib.h>

//创建一个链表结构
struct node{
	int data;
	struct node *next;
}; 
int main(){
    //链表数据录入
    struct node *head, *p , *q, *t;
	int i,n,a;
	scanf("%d", &n);
	head = NULL;
	for(i = 1; i <= n; i++){
		scanf("%d",&a);
	    //申请一个动态储存空间 ，起到一个中间过渡的作用 
		p = (struct node *)malloc(sizeof(struct node));
		p -> data = a;
		p -> next = NULL;
		if(head == NULL){
			head = p;  //头节点的处理方式 
		} else {
			q -> next = p; //不是头结点就将上一次的后继指针指向当前结点 
		}
		q = p; //指针p也指向当前结点 
	}
	scanf("%d", &a); //输入要插入的数
	//链表数据插入 
	t = head;
	while(t != NULL){
		if(t -> next == NULL || t -> next -> data > a){
			p = (struct node *)malloc(sizeof(struct node));
			p -> data = a;
			//执行插入
			p -> next = t -> next; //将上一个指针后继结点指向的执行给当前创建动态结点的值 
			t -> next = p; //将之前的结点的后即结点指向当前这个结点即可完成链表改接 
			break; 
		}
		t = t -> next; //继续下一个结点 
	} 
	
	//输出链表结果 
	t = head;
	while(head != NULL){
		printf("%d ", t -> data);
		t = t -> next;
	}
	
	getchar(); getchar();
	return 0;
}
