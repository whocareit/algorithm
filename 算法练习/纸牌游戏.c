//纸牌游戏规则：由两个人出牌，从手中的牌开始一人先出放于桌面，如果桌面上由与自己出的牌一样的
//就将这两张牌中间的部分包括这两张牌收入放在自己的手中牌的最后。
//逻辑分析：1.两人出牌与收牌的过程按照的是队列的逻辑
//          2.在桌上的牌是按照栈的机制进行
#include<stdio.h>
//队列结构体 
struct queue{
	int data[1000];
	int head;
	int tail; 
}; 
//栈结构体
struct stack{
	//桌上的牌面最多为1~9张牌，因此在这里设置栈的大小为11 
	int data[10];
	int top;
};
int main(){
	struct queue q1,q2;//q1与q2分别模拟两人手中的牌
	struct stack s;
	int book[10];//用于标记桌面上的牌的数量
	int i,t;
	
	//初始化队列与栈
	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;
	s.top = 0;
	
	//用于标记桌面上的牌的数量 
	for(i = 1; i <= 9; i++){
		book[i] = 0;
	} 
	
	//依次向队列中随机插入1~9中的任意六张牌
	for(i = 1; i <= 6; i++){
		scanf("%d",&q1.data[q1.tail]);
		q1.tail++;
	}
	
	for(i = 1; i <= 6; i++){
		scanf("%d",&q2.data[q2.tail]);
		q2.tail++;
	}
	
	//模拟出牌过程
	while(q1.head < q1.tail && q2.head < q2.tail){ //当两个人手中都有牌时执行下面部分的逻辑 
		t = q1.data[q1.head]; //t为所出的牌的第一张 
		if(book[t] == 0){ //如果桌面上没有牌就执行下面的过程 
			q1.head++;
			s.top++;
			s.data[s.top] = t; //把牌放在桌面上
			book[t] = 1; //记录这张牌 
		}else{
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;//取消桌面上的标记
				q1.data[q1.tail] = s.data[s.top];
				q1.tail++;
				s.top--; //桌面上的牌减少为1 
			}
			//收回与t相等的那张牌
			book[s.data[s.top]] = 0;//取消桌面上的标记
			q1.data[q1.tail] = s.data[s.top];
			q1.tail++;
			s.top--; //桌面上的牌减少为1 
		}
		if(q1.head == q1.tail) break; //如果第一个人的牌出完游戏结束另外一个人获胜
		
		//另外一个人出牌
		t = q2.data[q2.head]; //t为所出的牌的第一张 
		if(book[t] == 0){ //如果桌面上没有牌就执行下面的过程 
			q2.head++;
			s.top++;
			s.data[s.top] = t; //把牌放在桌面上
			book[t] = 1; //记录这张牌 
		}else{
			q2.head++;
			q2.data[q2.tail] = t;
			q2.tail++;
			while(s.data[s.top] != t){
				book[s.data[s.top]] = 0;//取消桌面上的标记
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--; //桌面上的牌减少为1 
			}
			//收回与t相等的那张牌
			book[s.data[s.top]] = 0;//取消桌面上的标记
			q2.data[q2.tail] = s.data[s.top];
			q2.tail++;
			s.top--; //桌面上的牌减少为1 
		}	 
	}
	//结果输出
	if(q2.head == q2.tail){
		printf("others win\n");
		printf("others cards");
		for(i = q1.head; i <= q1.tail-1; i++){
			printf("%d ",q1.data[i]);
		}
		if(s.top > 0){
			printf("\n桌面牌");
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
			printf("\n桌面牌");
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




