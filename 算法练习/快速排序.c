#include<stdio.h>
int a[101],n;
//�����㷨ʵ�� 
 quicksort(int left,int right){
	//����temp��Ϊ��׼����t��Ϊ�м���� 
	int i,j,temp,t; 
	//��Ϊһ���жϵı�׼����ߴ����ұ�ʱ�Ͳ�ִ������Ĳ��� 
	if(left > right){
		return;
	}
	//��׼ֵ��ֵ 
	temp = a[left];
	i = left;
	j = right;
	while( i != j){
		//���ҵ���ʼ��ѯ�Ȼ�׼��С��ֵ 
		while( a[j] >= temp && i < j){
			j--;
		}
		// �������ҿ�ʼ��ѯ�Ȼ�׼ֵ����� 
		while( a[i] <= temp && i < j){
			i++;
		}
		//��ѯ�������������ľͽ���λ�õĽ��� 
		if(i < j){
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	} 
	//��׼ֵ���й�λ 
	a[left] = a[i];
	a[i] = temp;
	//ʹ�õݹ���л�λ֮��Ļ�׼������ֱ������left<right 
	quicksort(left,i-1);
	quicksort(i+1,right);
	return;
}
int main(){
	int i,j;
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	quicksort(1,n);
	for(i = 1; i <= n; i++){
		printf("%d ",a[i]);
	}
	getchar();
	getchar();
	return 0;
} 
