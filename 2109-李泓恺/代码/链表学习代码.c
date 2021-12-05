#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;				//������ 
	struct Node *next;		//ָ���� 
};

//�������� 
struct Node* createList(){
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode  ��Ϊ�˽ṹ�����
	//��ʼ��
	headNode->data = 1;
	headNode->next = NULL;
	return headNode;
}

//������� 
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

//����
void insertNodeByHead(struct Node* headNode,int data){
	//��������Ľ��
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode; 
} 

//ָ��λ��ɾ�� 
void deleteNodeByAppoin(struct Node* headNode, int posData){
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL){
		printf("�޷�ɾ������Ϊ��\n");
	}
	else{
		while (posNode->data != posData){
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if(posNode == NULL){
				printf("û���ҵ������Ϣ���޷�ɾ��\n");
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


