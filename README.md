# 2021-AST-Task
This repository is for 2021-AST-Task

```
#include<stdio.h>

typedef struct Struct{
    int id;
    double grades;
} Student;

void quicksort(Student *ps,int n);
int main()
{
    int n;
    scanf("%d",&n);
    Student a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d%lf",&a[i].id,&a[i].grades);
    }
    quicksort(&a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d %g\n",a[i].id,a[i].grades);
    }

}
void quicksort(Student *a,int n)
{
     int i,j;
     Student t;
     for(i=0;i<n;i++)
{
   for(j=0;j<=n-i;j++)
   {
     if(a[j].grades<a[j+1].grades)
   {
       t=a[j];
       a[j]=a[j+1];
       a[j+1]=t;
   }
   }
}

}
```

2.argc和argv参数在用命令行编译程序时有用。main( int argc, char* argv[], char **env ) 中
    第一个参数，int型的argc，为整型，用来统计程序运行时发送给main函数的命令行参数的个数，在VS中默认值为1。
    第二个参数，char*型的argv[]，为字符串数组，用来存放指向的字符串参数的指针数组，每一个元素指向一个参数。各成员含义如下：
    argv[0]指向程序运行的全路径名
    argv[1]指向在DOS命令行中执行程序名后的第一个字符串
    argv[2]指向执行程序名后的第二个字符串
    argv[3]指向执行程序名后的第三个字符串
    argv[argc]为NULL
