# 科协第五周Task----汪嘉铖

## Git学习：

首先在repository文件夹中右键Git bash here

### 创建目录，选中

1.输入mkdir <文件名>（在repository中创建一个文件夹，以learngit为例

2.输入cd选中该文件夹,pwd显示地址

3输入git init把该目录（文件夹）变成可管理的仓库，通过ls查看该目录下的目录（文件

### add commit

1.将readme.txt文件放进learngit文件夹中

2.输入git add <文件>,以readme.txt为例 

   		git commit -m "备注"

将文件添加，提交到仓库中（可以一次add多个文件，再一次提交上去)

### status diff

1.将readme.txt文件修改后

2.输入git status查看当前仓库下的状态（告诉readme.txt文件被修改

   输入git diff查看修改的内容

![image-20211114121309079](C:\Users\SHALLOW\AppData\Roaming\Typora\typora-user-images\image-20211114121309079.png)

### reset cat log reflog 

1.进行修改后，可以通过输入git reset --hard HEAD^回到上一个修改版本

回到上两个或上n个：HEAD^^  /  HEAD~100

2.通过输入cat 查看readme.txt里面的内容

3.也可以通过git reset --hard <版本号>回到指定版本

4.输入git log查看所有版本号

5.输入git reflog记录每一次命令

![image-20211114122145858](C:\Users\SHALLOW\AppData\Roaming\Typora\typora-user-images\image-20211114122145858.png)

### switch branch

分支：增加一个新的指针dev，改变HEAD的指向，我们在之后的修改都在该分支dev上，不会对master分支造成影响

1.输入git switch -c <分支名>创建一个分支，以dev为例

2.输入git switch <分支名>切换分支

3.输入git branch查看所有分支

4.输入git branch -d <分支名>删除分支

![image-20211114123444437](C:\Users\SHALLOW\AppData\Roaming\Typora\typora-user-images\image-20211114123444437.png)

### merge

当切换到dev分支后，我们可以对readme.txt文件进行修改并add commit，再switch到master分支，发现readme.txt文件并未发生修改，此时需要merge合并dev分支上的修改到master分支上

1.首先switch到master分支上

2.输入git merge dev将dev分支合并到当前分支(master)，此时修改合并到了master分支上

![image-20211114135302610](C:\Users\SHALLOW\AppData\Roaming\Typora\typora-user-images\image-20211114135302610.png)

### Push

1.通过git push -u origin master将本地的仓库上传到github的账户项目的master分支中

