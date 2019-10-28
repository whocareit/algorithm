#include<stdio.h>
int h[101]; //���ڴ�Ŷ��е�����
int n;//��ʾ�Ѵ�С 


//�������� 
void swap(int x,int y){
	int t;
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return;
} 

//���µ�������,��ʱ�����µ��������ѵĵ������� 
void shifdown(int i){
	int t,flag = 0;
	// ��i����ж���(�������������)��������Ҫ��flag=0���ɵ���
	while(2*i <= n && flag == 0){ 
		//�����ж����������֮��Ĵ�С��ϵ 
		if(h[i] < h[2*i])
			t = i*2;
		else 
			t = i;
		if(i*2+1 <= n){ //�ж��Ƿ����Ҷ��� 
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

//���Ѻ���
void create(){
	int i;
	//�����һ����Ҷ��㵽��һ������������µ��� 
	for(i = n/2; i >= 1; i--){
		shifdown(i);
	}
	return;
} 

//������
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
	//���Ѻ��� 
	create(); 
	//������
	heapsort();
	//���
	for(i = 1; i <= num; i++)
		printf("%d ",h[i]);
	getchar();
	getchar();
	return 0;
}
//�ڶ��ַ�ʽ���������ķ�ʽ���һ�ֲ�ͬ�����ȴ�ʱ�����Ķ�Ϊ���ѣ������
//�ٽ���h[1]��h[n]֮��Ļ�������ʱh[n]Ϊ����мǣ�h[1]������������Ҫ�� 
//�϶ѵ����������Ҫ���е����� 
