#include <stdio.h>
#include <stdlib.h>
 
typedef struct LNode{
	int data;		/* �������� */
	struct LNode* next;	/* ����ָ�� */
}LNode,*LinkList;
 
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
	while(i < count)                /* �����������Ԫ�� */
	{
		printf("NO.%d:",i);
		printf("%5d\t",q->data);
		q = q->next;
		if(0 == i%4)
		printf("\n");
		i++;
	}
	printf("\n");
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
