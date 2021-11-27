# git学习

## 创建版本库

初始化一个Git仓库，使用`git init`命令。

添加文件到Git仓库，分两步：

1. 使用命令`git add <file>`，`（file: readme.txt）`注意，可反复多次使用，添加多个文件；
2. 使用命令`git commit -m <message>`，`（message: 本次提交的说明，可以输入任意内容，当然最好是有意义的，这样你就能从历史记录里方便地找到改动记录）代表输出文件的改变信息`,完成。

## 时光机穿梭

- 要随时掌握工作区的状态，使用`git status`命令。
- 如果`git status`告诉你有文件被修改过，用`git diff 文件名`可以查看修改内容。

### 版本回退

- `HEAD`指向的版本就是当前版本，因此，Git允许我们在版本的历史之间穿梭，使用命令`git reset --hard commit_id`。`git reset --hard HEAD^`表示回退到上个版本，上上个版本用^^，或者`HEAD~2`
- 穿梭前，用`git log`可以查看提交历史，以便确定要回退到哪个版本。 `commit后边的十六进制数字就是版本号，用的时候输入前几位即可（足够搜索）`
- 要重返未来，用`git reflog`查看命令历史，以便确定要回到未来的哪个版本。

### 工作区与暂存区

#### 工作区（Working Directory）

电脑里能看到的目录，如`learngit`文件夹

#### 版本库（Repository）

工作区有一个隐藏目录`.git`，这个不算工作区，而是Git的**版本库**。

Git的版本库里存了很多东西，其中最重要的就是称为stage（或者叫index）的**暂存区**，还有Git为我们**自动创建的第一个分支`master`**，以及指向`master`的一个**指针**叫`HEAD`。



把文件往Git版本库里添加的时候分两步执行：

1. 用`git add`把文件添加进去，实际上是把文件修改添加到暂存区
2. 用`git commit`提交修改，把暂存区的所有内容提交到当前分支

在创建Git版本库的时候Git自动创建了一个`master`分支，所以现在就是在`master`分支上提交更改

### 管理修改

每次修改后都需要`git add`到暂存区，才能commit

### 撤销修改

* **场景1：**当你改乱了工作区某个文件的内容，想**直接丢弃工作区的修改**时，用命令`git checkout -- file`。例如`git checkout -- readme.txt`

  ​	命令`git checkout -- readme.txt`意思就是，把`readme.txt`文件在工作区的修改全部撤销，这里有两种情况：

  ​	一种是`readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

  ​	一种是`readme.txt`已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

  ​	总之，就是让这个文件回到**最近一次**`git commit`或`git add`时的状态。

* **场景2：**当你不但改乱了工作区某个文件的内容，还**添加到了暂存区**时，想丢弃修改，分两步，第一步用命令`git reset HEAD <file>`，就回到了场景1，第二步按场景1操作。

* **场景3：**已经提交了不合适的修改到版本库时，想要**撤销本次提交**，参考[版本回退](https://www.liaoxuefeng.com/wiki/896043488029600/897013573512192)一节，不过**前提是没有推送到远程库**。

### 删除文件

删除文件`rm test.txt`，如果文件之前已经提交，`git status`会告诉你哪些文件被删除了

* 如果确实要删除文件，`git rm test.txt`并且`git commit`，删除版本库中的文件
* 如果是误删，只要版本库里边还有该文件，可以用`git checkout -- test.txt`还原。
  * `git checkout`其实是用版本库里的版本替换工作区的版本，所以工作区无论是修改还是删除，都可以“一键还原”

**注意**只能恢复文件到最新版本，会丢失最后一次提交后修改的内容。

## 远程仓库

GitHub

1. 创建SSH Key

   在用户主目录里找到`.ssh`目录，里面有`id_rsa`和`id_rsa.pub`两个文件，这两个就是SSH Key的秘钥对，`id_rsa`是私钥，不能泄露出去，`id_rsa.pub`是公钥，可以放心地告诉任何人。

2. 登陆GitHub，打开“Account settings”，“SSH Keys”页面：

   然后，点“Add SSH Key”，填上任意Title，在Key文本框里粘贴`id_rsa.pub`文件的内容：

### 添加远程库

* 要关联一个远程库，使用命令`git remote add origin git@github.com:用户名/仓库名.git`；
* 关联一个远程库时必须给远程库指定一个名字，`origin`是默认习惯命名；
* 关联后，使用命令`git push -u origin master`第一次推送master分支的所有内容；
* 此后，每次本地提交后，只要有必要，就可以使用命令`git push origin master`推送最新修改，把master分支的最新修改推送到GitHub
* 删除远程库 `git remote rm 仓库名`
  * 先用`git remote -v`查看远程库信息
  * 实质上是解除了本地和远程的绑定关系，不是物理上删除远程库，远程库没有任何改动。要真正删除远程库需要在GitHub上删除

### 从远程库克隆

* 创建仓库的时候勾选`initialize this repository with a README`，生成README.md文件

* `git clone git@github.com:xhxyygt/要克隆的仓库名.git`

* GitHub给出的地址不止一个，还可以用`https://github.com/michaelliao/gitskills.git`这样的地址。实际上，Git支持多种协议，默认的`git://`使用ssh，但也可以使用`https`等其他协议。

  使用`https`除了速度慢以外，还有个最大的麻烦是每次推送都必须输入口令，但是在某些只开放http端口的公司内部就无法使用`ssh`协议而只能用`https`。

  Git支持多种协议，包括`https`，但`ssh`协议速度最快。

## 分支管理

### 创建与合并分支

每次提交，Git都把他们串成一条时间线，一个时间线就是一条分支

在项目目录下

`git checkout -b 分支名` 创建并切换。相当于`$ git branch dev  $ git checkout dev`两条命令

* 查看分支：`git branch`，在当前分支的名字前会标`*`
* 创建分支：`git branch <name>`
* 切换分支：`git checkout <name>`或者`git switch <name>`
* 创建+切换分支：`git checkout -b <name>`或者`git switch -c <name>`
* 合并某分支到当前分支：`git merge <name>`，合并之后就可以删除另一个分支
* 删除分支：`git branch -d <name>`

**注意**

* 每次修改完需要add和commit之后，才能做到分支的内容不影响其他分支，否则系统只视为直接对文件修改，没有提交到仓库，仓库就不能保存你做的改动

### 解决冲突

在两个分支分别修改并且提交会出现冲突提示，`git status`告诉我们冲突的文件，在文件内修改后再提交

当Git无法自动合并分支时，就必须首先解决冲突。解决冲突后，再提交，合并完成。

解决冲突就是把Git合并失败的文件手动编辑为我们希望的内容，再提交。

用`git log --graph`命令可以看到分支合并图。

### 分支管理策略

通常，合并分支时，如果可能，Git会用`Fast forward`模式，但这种模式下，删除分支后，会丢掉分支信息。

如果要强制禁用`Fast forward`模式，Git就会在merge时生成一个新的commit，这样，从分支历史上就可以看出分支信息。

合并分支时，加上`--no-ff`参数就可以用普通模式合并，合并后的历史有分支，能看出来曾经做过合并，而`fast forward`合并就看不出来曾经做过合并。

~~~c
git merge --no-ff -m "merge with no-ff" dev
~~~

因为本次合并要创建一个新的commit，所以加上`-m`参数，把commit描述写进去。

### bug分支

* 修复bug时，我们会通过创建新的bug分支进行修复，然后合并，最后删除；

* 当手头工作没有完成时，先把工作现场`git stash`一下，然后去修复bug，修复后，再`git stash pop`，回到工作现场；
* 如何查看刚刚的工作现场存在哪儿了？`git stash list`

* 在master分支上修复的bug，想要合并到当前dev分支，可以用`git cherry-pick <commit>`命令，把bug提交的修改“复制”到当前分支，避免重复劳动。(commit是那个十六进制数字)

### Feature分支

开发feature最好新建一个分支

如果要丢弃一个没有被合并过的分支，可以通过`git branch -D <name>`强行删除。

### 多人协作

1. 首先，可以试图用`git push origin <branch-name>`推送自己的修改；
2. 如果推送失败，则因为远程分支比你的本地更新，需要先用`git pull`试图合并；
3. 如果合并有冲突，则解决冲突，并在本地提交；
4. 没有冲突或者解决掉冲突后，再用`git push origin <branch-name>`推送就能成功！

如果`git pull`提示`no tracking information`，则说明本地分支和远程分支的链接关系没有创建，用命令`git branch --set-upstream-to=origin/远程分支名 本地分支名`。

这就是多人协作的工作模式，一旦熟悉了，就非常简单。

### 小结

- 查看远程库信息，使用`git remote -v`；
- 本地新建的分支如果不推送到远程，对其他人就是不可见的；
- 从本地推送分支，使用`git push origin branch-name`，如果推送失败，先用`git pull`抓取远程的新提交；
- 在本地创建和远程分支对应的分支，使用`git checkout -b 分支名（远程） origin/分支名`，本地和远程分支的名称最好一致；
- 建立本地分支和远程分支的关联，使用`git branch --set-upstream-to=origin/远程分支名 本地分支名`；
- 从远程抓取分支，使用`git pull`，如果有冲突，要先处理冲突。

### Rebase

- rebase操作可以把本地未push的分叉提交历史整理成直线；
- rebase的目的是使得我们在查看历史提交的变化时更容易，因为分叉的提交需要三方对比。

## 标签管理

tag就是一个让人容易记住的有意义的名字，它跟某个commit绑在一起

### 创建标签

- 命令`git tag <tagname>`用于新建一个标签，默认为`HEAD`（最新提交的commit），也可以指定一个commit id；`git tag 标签名 提交id`
- 命令`git tag -a <tagname> -m "blablabla..."`可以指定标签信息；
- 命令`git tag`可以查看所有标签。
- `git show 标签名`查看说明文字

 **注意：标签总是和某个commit挂钩。如果这个commit既出现在master分支，又出现在dev分支，那么在这两个分支上都可以看到这个标签。**

### 操作标签

- 命令`git push origin <tagname>`可以推送一个本地标签；
- 命令`git push origin --tags`可以推送全部未推送过的本地标签；
- 命令`git tag -d <tagname>`可以删除一个本地标签；
- 命令`git push origin :refs/tags/<tagname>`可以删除一个远程标签。

## GitHub

- 在GitHub上，可以任意Fork开源仓库；
- 自己拥有Fork后的仓库的读写权限；
- 可以推送pull request给官方仓库来贡献代码。

`git clone git@github.com:xhxyygt/仓库名.git`
