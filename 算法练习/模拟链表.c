#include<stdio.h>
int main(){
	//data���ڴ������  right��ʾλ�� 
	int data[101],right[101];
	int i, n , t, len;
	//�������е���
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		//i ��ʾ˳�� data[i]���ڱ�ʾ�洢������ 
		scanf("%d", &data[i]);
	} 
	len = n;
	//��ʼ��right����
	for(i = 1; i <= n; i++){
		//right�����д�ŵ��ǵ�ǰ�������һ��λ�� 
		if(i != n ){
			right[i] = i + 1;
		} else {
			right[i] = 0;
		}
	} 
	//ֱ����data�����ĩβ����һ����
	len++;
	//���������� 
	scanf("%d", &data[len]); 
	//�������ͷ����ʼ����	
	t = 1;
	while( t!= 0){
		//������������С�ڵ�ǰ������һ��������ִ�в������ 
		if(data[right[t]] > data[len]){
			right[len] = right[t];
			right[t] = len; 
			break;
		}
		t = right[t];
	} 
	
	t = 1;
	while(t != 0){
		printf("%d ",data[t]);
		t = right[t];
	}
	
	getchar(); getchar();
	return 0;
}
