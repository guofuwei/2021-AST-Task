# 科协第六周task

## 基础任务

### 1.malloc函数

malloc函数用于进行动态分配内存，malloc函数分配的空间存在于堆内存中

### 2.->运算符

该运算符->前面的表示指针名，->后面的表示用该指针访问结构中的成员

### 3.链表

对链表的定义可具体为定义了一个自定义结构，该结构可以分为两部分，一部分为前面具体的data值，另一部分为下一个节点的地址，用结构指针来表示

## 提高任务

### 1

```
#include<stdio.h>
#include<stdlib.h>
#define N 10
struct node
{
	int data;
	struct node *next;
};

int main()
{
	struct node* head,*p,*q,*t;
	int a,i;

	head = NULL;
	for(i=0;i<N;i++)
    {
        scanf("%d", &a);
		p = (struct node*)malloc(sizeof(struct node));
		p->data = a;
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			q->next= p;
		}
		q = p;
	}
	t = head;
	while (t != NULL)
	{
		printf("%d ", t->data);
		t = t->next;
	}
	
      return 0;
}
```

### 2

```
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* a = NULL;
    struct ListNode* b = head;
    while (b) {
        struct ListNode* next = b->next;
        b->next = a;
        a = b;
        b= next;
    }
    return a;
}
```



## Leetcode刷题

### 344

```
void reverseString(char* s, int sSize){
    int left=0,right=sSize-1;
    for(;left<right;left++,right--)
    {int temp;
    temp=s[left];
    s[left]=s[right];
    s[right]=temp;
    }
}
```

### 1

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int *result=NULL;
    *returnSize=2;
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                 result=(int*)malloc(sizeof(int)*2);
                 result[0]=i;
                 result[1]=j;
                 return result;
            }
        }
    }
    return result;
}
```

### 206

```
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* a = NULL;
    struct ListNode* b = head;
    while (b) {
        struct ListNode* next = b->next;
        b->next = a;
        a = b;
        b= next;
    }
    return a;
}
```

