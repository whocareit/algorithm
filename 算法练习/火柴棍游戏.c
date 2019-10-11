//火柴棍游戏描述:有n根火柴棍，希望拼成A+B=C的等式，等式中的
//A,B,C均是用火柴棍拼出来的整数，给定火柴棍数量求拼成的等式的数量 
#include<stdio.h> 
int fun(int n){
	int num=0;
	//拼成整数所需要的火柴棍数的数组表示 
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
	printf("拼成的火柴棍的等式总数为%d",sum);
	
	getchar(); getchar();
	return 0;
}
