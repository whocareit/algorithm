#include<stdio.h>
//ʹ�ýṹ��ʹ����֮�佨����ϵ 
struct student{
	char name[21];
	int score;
};
int main(){
	//�����ṹ�����a[]��t 
	struct student a[100],t;
	int i,j,n;
	scanf("%d",&n); //����һ����n
	for(i = 1; i <= n; i++){
		//�����������Ľṹ���е��������� 
		scanf("%s %d",a[i].name, &a[i].score);
	} 
	for(i = 1; i <= n - 1; i++){
		for(j = 1; j <= n - 1; j++){
			if(a[j].score < a[j+1].score){
				t = a[j]; //��������н�����������ṹ�壬�����Ҳ�ǽ�t����Ϊ�ṹ�������ԭ�� 
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	} 
	for(i = 1; i <= n; i++){
		printf("%s\n",a[i].name);
	}
	getchar();
	getchar();
	return 0;
} 
