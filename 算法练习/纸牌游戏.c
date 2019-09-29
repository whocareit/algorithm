//ֽ����Ϸ�����������˳��ƣ������е��ƿ�ʼһ���ȳ��������棬��������������Լ�������һ����
//�ͽ����������м�Ĳ��ְ�������������������Լ��������Ƶ����
//�߼�������1.���˳��������ƵĹ��̰��յ��Ƕ��е��߼�
//          2.�����ϵ����ǰ���ջ�Ļ��ƽ���
#include<stdio.h>
//���нṹ�� 
struct queue{
	int data[1000];
	int head;
	int tail; 
}; 
//ջ�ṹ��
struct stack{
	//���ϵ��������Ϊ1~9���ƣ��������������ջ�Ĵ�СΪ11 
	int data[10];
	int top;
};
int main(){
	struct queue q1,q2;//q1��q2�ֱ�ģ���������е���
	struct stack s;
	int book[10];//���ڱ�������ϵ��Ƶ�����
	int i,t;
	
	//��ʼ��������ջ
	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;
	s.top = 0;
	
	//���ڱ�������ϵ��Ƶ����� 
	for(i = 1; i <= 9; i++){
		book[i] = 0;
	} 
	
	//������������������1~9�е�����������
	for(i = 1; i <= 6; i++){
		scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}
	
	for(i = 1; i <= 6; i++){
		scanf("%d",&q2.data[q2.tail]);
		q2.tail++;
	}
	
	//ģ����ƹ���
	while(q1.head < q1.tail && q2.head < q2.tail){ //�����������ж�����ʱִ�����沿�ֵ��߼� 
		t = q1.data[q1.head]; //tΪ�������Ƶĵ�һ�� 
		if(book[t] == 0){ //���������û���ƾ�ִ������Ĺ��� 
			q1.head++;
			s.top++;
			s.data[s.top] = t; //���Ʒ���������
			book[t] = 1; //��¼������ 
		}else{
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;//ȡ�������ϵı��
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--; //�����ϵ��Ƽ���Ϊ1 
			}
			//�ջ���t��ȵ�������
			book[s.data[s.top]] = 0;//ȡ�������ϵı��
			q1.data[q1.tail] = s.data[s.top];
			q1.tail++;
			s.top--; //�����ϵ��Ƽ���Ϊ1 
		}
		if(q1.head == q1.tail) break; //�����һ���˵��Ƴ�����Ϸ��������һ���˻�ʤ
		
		//����һ���˳���
		t = q2.data[q2.head]; //tΪ�������Ƶĵ�һ�� 
		if(book[t] == 0){ //���������û���ƾ�ִ������Ĺ��� 
			q2.head++;
			s.top++;
			s.data[s.top] = t; //���Ʒ���������
			book[t] = 1; //��¼������ 
		}else{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;//ȡ�������ϵı��
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--; //�����ϵ��Ƽ���Ϊ1 
			}
			//�ջ���t��ȵ�������
			book[s.data[s.top]] = 0;//ȡ�������ϵı��
			q2.data[q2.tail] = s.data[s.top];
			q2.tail++;
			s.top--; //�����ϵ��Ƽ���Ϊ1 
		}	 
	}
	//������
	if(q2.head == q2.tail){
		printf("others win\n");
		printf("others cards");
		for(i = q1.head; i <= q1.tail-1; i++){
			printf("%d ",q1.data[i]);
		}
		if(s.top > 0){
			printf("\n������");
			for(i = 1; i <= s.top; i++){
				printf(" %d",s.data[i]);
			}
		}else{
			printf("no cards");
		}
	}else{
		printf("owner win\n");
		printf("others cards");
		for(i = q2.head; i <= q2.tail-1; i++){
			printf(" %d",q2.data[i]);
		}
		if(s.top > 0){
			printf("\n������");
			for(i = 1; i <= s.top; i++){
				printf(" %d",s.data[i]);
			}
		}else{
			printf("no cards");
		}
	}
	
	getchar(); getchar();
	return 0;
} 




