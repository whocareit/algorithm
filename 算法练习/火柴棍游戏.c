//������Ϸ����:��n��������ϣ��ƴ��A+B=C�ĵ�ʽ����ʽ�е�
//A,B,C�����û���ƴ��������������������������ƴ�ɵĵ�ʽ������ 
#include<stdio.h> 
int fun(int n){
	int num=0;
	//ƴ����������Ҫ�Ļ������������ʾ 
	int f[10] = {6,2,5,5,4,5,6,3,7,6};
	while( n/10 != 0 ){
		num += f[ n % 10];
		n = n /10;
	} 
	num += f[n];
	return num;
}

int main(){
	int a,b,c,m,sum=0;
	scanf("%d",&m);
	for(a = 0; a <= 1111; a++){
		for(b = 0; b <= 1111; b++){
			c = a + b;
			if(fun(a) + fun(b) + fun(c) == m - 4){
				printf("%d + %d = %d\n",a,b,c);
				sum++; 
			}
		}
	}
	printf("ƴ�ɵĻ����ĵ�ʽ����Ϊ%d",sum);
	
	getchar(); getchar();
	return 0;
}
