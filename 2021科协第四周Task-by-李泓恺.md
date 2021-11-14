# 2021-AST-Task4 by 李泓恺
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

## 远程仓库

### 添加远程库

* 要关联一个远程库，使用命令`git remote add origin git@server-name:path/repo-name.git`；

* 关联一个远程库时必须给远程库指定一个名字，`origin`是默认习惯命名；

* 关联后，使用命令`git push -u origin master`第一次推送master分支的所有内容；

* 此后，每次本地提交后，只要有必要，就可以使用命令`git push origin master`推送最新修改；

## 分支管理

### 创建与合并分支

在项目目录下

`git checkout -b 分支名` 创建并切换。相当于`$ git branch dev  $ git checkout dev`两条命令

* 查看分支：`git branch`
* 创建分支：`git branch <name>`
* 切换分支：`git checkout <name>`或者`git switch <name>`
* 创建+切换分支：`git checkout -b <name>`或者`git switch -c <name>`
* 合并某分支到当前分支：`git merge <name>`
* 删除分支：`git branch -d <name>`







add test
