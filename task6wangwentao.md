## 科协Task6-By王文韬

### malloc()函数笔记

```c
malloc函数是c语言中的一个动态内存分配函数，其返回值是一个void类型的指针，一般需要强制类型转换为所需要的类型
使用示例：int *p;
         p=(int*)malloc(所需字节数)；
使用malloc函数后一般要用free()函数释放内存
```

### 结构体指针学习笔记

```c
//结构体指针
struct date{
    int month;
    int day;
    int year;
}myday;
struct date *p=&myday;//定义结构体类型的指针
(*p).month=12;        //*p即结构体变量myday(1)
p->month=12;  //用->表示指针所指的结构变量中的成员(2)
//方式1和2效果相同
```

### 提高任务

1.创建单链表并输出

```c
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct _node{
	int data;
	struct _node *next;
}Node; 
int main(void){
	Node *head=NULL;
	int number;
	do{ scanf("%d",&number);
		if(number!=-1){
			Node *p=(Node*)malloc(sizeof(Node));
			p->data=number;
			p->next=NULL;
			Node *last=head;
			if(last){
				while(last->next){
					last=last->next;
				}
			last->next=p;
		}else{
			head=p;
		}
	}
	}while(number!=-1);
	while(head){
		printf("%d ",head->data);
		head=head->next;
	}
	
}
```

### 力扣题

344 反转字符串

```c
void reverseString(char* s, int sSize){
int i;
char temp;
for(i=0;i<=(sSize-1)/2;i++){
  temp=s[i];
  s[i]=s[sSize-1-i];
  s[sSize-1-i]=temp;
}
}
```

1 两数之和

```c
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
*returnSize=2;
int* result=NULL;
int i,j;
for(i=0;i<numsSize;i++){
    for(j=i+1;j<numsSize;j++){
        if(nums[i]+nums[j]==target)
        {result=(int*)malloc(sizeof(int)*2);
         result[0]=i;
         result[1]=j;
        }
    }
}
return result;
}
```

15 3Sum

```c
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
int i,j,k;
int sum;
*returnSize=0;
int** result = (int**)malloc(sizeof(int*) * (numsSize)*(numsSize));
 *returnColumnSizes = (int*)malloc(sizeof(int) * (numsSize)*(numsSize)); 
if(numsSize>=3){
for(i=0;i<numsSize;i++){
   for(j=i+1;j<numsSize;j++){
       for(k=j+1;k<numsSize;k++){
            sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
             result[*returnSize] = (int*)malloc(sizeof(int) * 3);
               (*returnColumnSizes)[*returnSize] = 3; 
              result[*returnSize][0]=nums[i];
              result[*returnSize][1]=nums[j];
               result[*returnSize][2]=nums[k];
               (*returnSize)++;
            }
       }
   }
   }}
   else
   return NULL;
   return result;
}
```

371 不用加号求和

```c
int getSum(int a, int b){
int result;
result= (int)(&((char*)a)[b]);
return result;
}
```

35 搜索插入位置

```c
int searchInsert(int* nums, int numsSize, int target){
int result=0,i,j;
for(i=0;i<numsSize;i++){
    if(target==nums[i]){
    result=i;
    break;}
    else if(i==numsSize-1){
        for(j=0;j<numsSize;j++){
            if(target>nums[j])
            result=j+1;
        }
    }
}
return result;
}
```

