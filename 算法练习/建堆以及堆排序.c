#include<stdio.h>
int h[101]; //���ڴ�Ŷ��е�����
int n; //�����洢����Ԫ�صĸ�����Ҳ���ǶѵĴ�С

//��������,���������������е�Ԫ�� 
void swap(int x, int y){
	int t; //�м佻������ 
	t = h[x];
	h[x] = h[y];
	h[y] = t;
	return ;
} 

//���µ�������
void shiftdown(int i){ //����һ����Ҫ���µ����Ľ����i�����������1����ӶѵĶ��㿪ʼ 
	int t,flag = 0; //flag�����ж��Ƿ����µ���
	//�����i�ж��ӣ���ʵ����������ӣ���������Ҫ��������ʱѭ��ִ��
	while(i*2 <= n && flag == 0){
		if(h[i] > h[i*2])
			t = i*2;
		else 
			t = i;
		//������Ҷ��ӣ��ٶ��Ҷ��ӽ�������
		if(i*2+1 <= n){
			if(h[t] > h[2*i + 1])
				t = 2*i + 1;
		} 
		if(t != i){
			swap(t,i);
			i = t;//����iΪ�ղ����������Ķ��ӵĽ���ţ����ڽ������ĵ��� 
		} 
		else
			flag = 1; 
	} 
	return;
}

//���Ѻ��� 
void create(){
	int i;
	//�����һ����ҳ��㵽��һ�����һ�ν������µ���
	for(i = n/2; i >= 1; i--){
		shiftdown(i);
	} 
	return;
}

//ɾ�����Ԫ��
int deletemax(){
	 int t;
	 t = h[1]; //����ʱ��������¼�Ѷ����ֵ
	 h[1] = h[n];
	 n--;
	 shiftdown(1); //���µ���
	 return t; 
} 

int main(){
	int i,num;
	//����Ҫ��������ֵĸ���
	scanf("%d",&num);
	for(i = 1; i <= num; i++){
		scanf("%d",&h[i]);
	} 
	n = num;
	//���� 
	create();
	
	//ɾ������Ԫ�أ�����ɾ��n�Σ���ʵ�ʾ��Ǵ�С����������
	for(i = 1; i <= num; i++){
		printf("%d ",deletemax());
	} 
	getchar(); getchar();
	return 0;
}
//���ַ�ʽ���õ������ǣ�ͨ��һ��deletemax�������ɾ����С�������������е�ɾ������Ӷ��ﵽ�����Ŀ�� 
