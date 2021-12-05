#include <stdio.h>
#include <stdlib.h>
 
typedef struct LNode{
	int data;		/* �������� */
	struct LNode* next;	/* ����ָ�� */
}LNode,*LinkList;

//���������
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
 
//�������
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
	L->next = NULL;	/* ͷ��� */
    
	q = L;
	printf("������������������,�ÿո����,�����д��ĸQ��ʾ����\n");
	do                             /* ���������㣬˳������Ԫ�� */
	{    
		scanf("%d",&data);
		p =  (LinkList)malloc(sizeof(LNode));
		p->data =data;
		p->next = NULL;q->next = p;q = p;
		count++;
	}while(getchar() != 'Q');
	p = L->next;    /* pָ��ָ���һ����� */
	q = L->next;
	i=1;
	
	printf("�������������:\n");	
	ShowList(p);	
	printf("\n");
	
	//����
	p =  ReverseList(p);
	
	printf("���ú�Ϊ\n");
	ShowList(p);
	 
	/* �ͷſռ� */
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
