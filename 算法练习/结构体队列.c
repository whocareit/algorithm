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
//	�����еĳ�ʼֵ����Ϊ1�����������������ݵ���β 
	for(i = 1; i <= 9; i++){
		scanf("%d",&q.array[q.tail]);
		q.tail++;//ִ�������һ�κ�ʣ�����������һ��λ�ò�û��ֵ 
	}
	while(q.head < q.tail){ //�����в�Ϊ��ʱִ������ĳ��� 
		printf("%d",q.array[q.head]);
		q.head++;
		q.array[q.tail] = q.array[q.head];
		q.tail++;
		q.head++; 
	} 
	getchar();getchar();
	return 0;
}
//���൱�ڽ����װ��һ�������У�Ȼ������ͬ�����ֵһ��ȥ������������� 
