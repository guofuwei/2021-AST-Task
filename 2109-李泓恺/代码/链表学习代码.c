#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;				//数据域 
	struct Node *next;		//指针域 
};

//创建链表 
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode  成为了结构体变量
	//初始化
	headNode->data = 1;
	headNode->next = NULL;
	return headNode;
}

//创建结点 
struct Node* createNode(int data){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void printList(struct Node* headNode){
	struct Node* pMove = headNode->next;
	while (pMove) {
		printf("%d\t",pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

//插入
void insertNodeByHead(struct Node* headNode,int data){
	//创建插入的结点
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode; 
} 

//指定位置删除 
void deleteNodeByAppoin(struct Node* headNode, int posData){
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL){
		printf("无法删除链表为空\n");
	}
	else{
		while (posNode->data != posData){
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if(posNode == NULL){
				printf("没有找到相关信息，无法删除\n");
				return;
			}
		}
		posNodeFront->next = posNode->next;
		free(posNode);
	}
}

int main()
{
	struct Node* list = createList();
	insertNodeByHead(list, 1);
	insertNodeByHead(list, 2);
	insertNodeByHead(list, 3);
	printList(list);
	deleteNodeByAppoin(list, 2);
	printList(list);
	
	return 0; 
} 


