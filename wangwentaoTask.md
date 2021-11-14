## 科协Task-by王文韬

### github学习

学会了安装以及简单使用git

#### 1.基础操作

```c
//基础操作
//cd:进入某个文件夹    pwd:显示当前目录
//mkdir:创建文件夹    git init:创建仓库
//git add 文件名：添加文件
//git commit -m"" :将add的文件提交至本地仓库
//git status:可以查看当前状态

```

#### 2.远程库操作（结合github)

```c
//1.添加远程仓库
//  在本地仓库下运行命令git remote add origin git @github.com:github账户名/远程仓库名
//  origin是git对远程仓库的默认叫法，运行上述命令就将本地仓库与github上远程仓库关联起来了
//  可以在本地仓库内进行文件的修改，根据需求添加及提交后可以向远程库推送
//  推送命令git push -u origin(即远程库名) (本地分支名)
//  之后推送可以不要-u
//  删除远程库git remote rm origin(远程库名)
```

```c
//2.从远程库克隆
//  先在github上fork仓库至自己的账号下
//  fork操作的作用相当于将别人发布的仓库复制一份到自己的github账号，注意不是复制到本地
//  克隆到本地git clone git@github.com:github账号名/要克隆的仓库名
//  之后添加和修改文件的操作与添加远程仓库中相同
//  再用git push origin 本地分支名  进行推送，将自己在本地仓库中修改后的文件推送至自己在github上克隆的仓库内
```

#### 3.分支操作

```c
//  git checkout -b 分支名 或者git switch -c 分支名  这两个指令用于创建并进入新的分支
//  查看当前拥有的分支 git branch，git remote可以查看远程库分支
//  在分支内修改文件，其操作与主分支相同
//  切换分支 git switch(或者checkout) 分支名，分支之间是互不干扰的
//  推送分支  git push origin 本地分支名  ，推送后github的仓库内会出现对应的分支
//  分支的合并 git merge 分支名   即合并当前所在分支与输入分支名所对应的分支
//  删除分支 git branch -d 分支名，即删除了对应分支
```

#### 4.github上pull request

```c
//pull request是一种通知机制，发起pull request即通知原来的作者希望能合并修改，并征求对方同意
//使用步骤
//fork别人的仓库并做出自己的修改后，在自己fork的仓库中修改后的分支按下“New pull request"
//之后会进入一个新的页面，有base和head两个选项，base是希望提交变更的那个目标，head是目前包含你的变更的那个分支或仓库
//之后可按需求填写说明，最后按下“create pull request"即可
```

