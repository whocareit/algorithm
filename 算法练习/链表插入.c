#include<stdio.h>
#include<stdlib.h>

//����һ������ṹ
struct node{
	int data;
	struct node *next;
}; 
int main(){
    //��������¼��
    struct node *head, *p , *q, *t;
	int i,n,a;
	scanf("%d", &n);
	head = NULL;
	for(i = 1; i <= n; i++){
		scanf("%d",&a);
	    //����һ����̬����ռ� ����һ���м���ɵ����� 
		p = (struct node *)malloc(sizeof(struct node));
		p -> data = a;
		p -> next = NULL;
		if(head == NULL){
			head = p;  //ͷ�ڵ�Ĵ���ʽ 
		} else {
			q -> next = p; //����ͷ���ͽ���һ�εĺ��ָ��ָ��ǰ��� 
		}
		q = p; //ָ��pҲָ��ǰ��� 
	}
	scanf("%d", &a); //����Ҫ�������
	//�������ݲ��� 
	t = head;
	while(t != NULL){
		if(t -> next == NULL || t -> next -> data > a){
			p = (struct node *)malloc(sizeof(struct node));
			p -> data = a;
			//ִ�в���
			p -> next = t -> next; //����һ��ָ���̽��ָ���ִ�и���ǰ������̬����ֵ 
			t -> next = p; //��֮ǰ�Ľ��ĺ󼴽��ָ��ǰ�����㼴���������Ľ� 
			break; 
		}
		t = t -> next; //������һ����� 
	} 
	
	//��������� 
	t = head;
	while(head != NULL){
		printf("%d ", t -> data);
		t = t -> next;
	}
	
	getchar(); getchar();
	return 0;
}
