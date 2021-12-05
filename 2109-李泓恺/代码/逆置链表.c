#include <stdio.h>
#include <stdlib.h>
 
typedef struct LNode{
	int data;		/* 链表数据 */
	struct LNode* next;	/* 链表指针 */
}LNode,*LinkList;

//链表的逆置
LNode *ReverseList(LNode *phead)
{
	LNode *p, *q, *r;
 
	p = phead;
	q=r=NULL;
 
	while(p)
	{
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	return r;
}
 
//输出链表
void ShowList(LNode *phead)
{
	LNode *p;
 
	p = phead;
	while(p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

 
int main()
{
	int i,data,count=0;
	LinkList L;
	LinkList p;
	LinkList q;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;	/* 头结点 */
    
	q = L;
	printf("请输入你的任意个整数,用空格隔开,输入大写字母Q表示结束\n");
	do                             /* 创建链表结点，顺序输入元素 */
	{    
		scanf("%d",&data);
		p =  (LinkList)malloc(sizeof(LNode));
		p->data =data;
		p->next = NULL;q->next = p;q = p;
		count++;
	}while(getchar() != 'Q');
	p = L->next;    /* p指针指向第一个结点 */
	q = L->next;
	i=1;
	
	printf("你输入的整数是:\n");	
	ShowList(p);	
	printf("\n");
	
	//逆置
	p =  ReverseList(p);
	
	printf("逆置后为\n");
	ShowList(p);
	 
	/* 释放空间 */
	p = L->next;
	i=1;
	while(i++ <= count)                    
	{
		q = p;
		p = p->next;
		free(q);
	} 
	return 0;
}
