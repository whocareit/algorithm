//malloc���������ڴ����������ָ���ֽڴ�С�Ŀռ�
//int *p  p = (int *) malloc(sizeof(int)); ��ʾ�ɹ��ķ�����һ����̬�Ŀռ�
//malloc�����ķ��������� void *���ͣ� void * ��ʾδȷ�����͵�ָ��

//�����ʾʹ��һ���ṹ������ʾ����
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next; //��ʾָ����һ����ַ��ָ�� 
}; 

int main(){
	struct node *p, *q, *t, *head;
	int i,n,a;
	scanf("%d",&n);//����һ����,��ʾ������ĳ���Ϊ���� 
	head = NULL;//ͷָ���ʼ��
	for(i = 1; i <= n; i++){
		scanf("%d",&a);
		//��̬����һ���ռ䣬�������ĳ����㣬����ʹ����ʱָ��pָ�������� 
		p = (struct node *) malloc (sizeof(struct node));
		p->data = a; //�������ֵ���ڽṹ���е�data��
		p->next = NULL; //������һ�����Ϊ�գ�Ҳ���ǵ�ǰ���ĺ��ָ��Ϊ��
		if(head == NULL) { //���ͷָ��Ϊ�� 
			head = p; //�����ͷָ�룬�ͽ�ͷָ��ָ�������� 
		}else{
			q->next = p;  //�������ͷָ�룬�ͽ���һ�����ĺ��ָ��ָ��ǰ��� 
		}
		q = p; 
	}  
	
	//��������е�������
	t = head; //Ϊһ����ʱ���������������������
	while( t != NULL){
		printf("%d ",t->data);
		t = t->next;
	} 
	
	getchar(); getchar();
	return 0;
} 
