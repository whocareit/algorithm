#include<stdio.h>
int f[1001]={0},n,m,sum=0;
//��ʼ�������������ڲ��洢�����Լ����±� 
void init(){
	int i;
	for(i = 1; i <= n; i++)
		f[i] = i;
	return;
}

//ʹ�õݹ�ķ�ʽ�ҵ����boss
int getf(int v){
	//��ʾ�ҵ�������boss 
	if(f[v] == v)
		return v;
	else{
		//·��ѹ�����ҵ����boss 
		f[v] = getf(f[v]);
		return f[v];
	}
} 
//�ϲ������Ӽ��ϵĺ���
void merge(int v,int u){
	//t1 t2�ֱ�Ϊv��u�Ĵ�boss��ÿ��˫����̸�����Ǹ��Ե�����쵼�� 
	int t1,t2;
	t1 = getf(v);
	t2 = getf(u);
	if(t1 != t2){
		//���˫������һ�������У���ʵ�п���ԭ����ߵ�boss����ұߵ�boss 
		f[t2] = t1;
	}
	return;
} 
int main(){
	int i,x,y;
	scanf("%d %d",&n,&m);
	init(); //���г�ʼ��
	for(i = 1; i <= m; i++){
		//��ʼ�ϲ�
		scanf("%d %d",&x,&y);
		merge(x,y); 
	} 
	//���ɨ���Ҷ��ٸ������ļ���
	for(i = 1; i <= n; i++){
		if(f[i] == i)
		sum++;
	} 
	printf("%d\n",sum);
	getchar();getchar();
	return 0;
}




