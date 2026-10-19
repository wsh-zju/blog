---
title: 分支基本操作
date: 2026-05-06 01:00:00
updated: 2026-03-09 22:00:00 # 显示最后更新时间，对技术文章很重要
tags: 
  - Git
categories: 
  - Git 入门 & 进阶
toc: true     # 是否显示目录（Icarus 侧边栏支持）
thumbnail: images/git.png # Icarus 首页显示的缩略图（可选）
mathjax: true # 如果文章包含数学公式，一定要开启这个！
excerpt: Git 入门 & 进阶
---


## 创建并切换分支

在版本回退里，Git 会把每次提交串成一条时间线，这条时间线就是一个分支。截至目前，我们只有一条主分支 `master` ，如图所示。

<img src="5-1.png" style="width:30%;display: block;margin: 20px auto;">

每次提交，`master` 都会向前移动一步。

1. **创建新分支 `dev`**

   ```bash
   git branch dev
   ```

   当我们创建新的分支时，其实就是创建了一个新的指针 `dev`。

   <img src="5-2.png" style="width:30%;display: block;margin: 20px auto;">

2. **切换到新分支**

   ```bash
   git checkout dev
   ```

   这时候我们对工作区的修改和提交就是针对 `dev` 分支了。当我们进行一次新的提交，`dev` 指针会向前移动一步，但是 `master` 指针不变。

   <img src="5-3.png" style="width:30%;display: block;margin: 20px auto;">

3. 当然，我们还有**更简单的创建和切换分支的方法**

   ```bash
   git checkout -b dev					# 创建并切换分支
   ```

4. **查看当前分支**

   ```bash
   git branch
   ```

   这个命令会列出所有分支，前边标 `*` 的就是当前分支。
   
5. **`switch`**：

   - 我们知道，`git checkout` 有两个作用：切换分支以及撤销修改，有点不太好分辨
   
   - 实际上，切换分支这个动作，用 `switch` 更科学
   
   - **创建并切换到新的分支**
   
     ```bash
	  git switch -c dev
	  ```
	
	- **直接切换到已有分支**
	
	  ```bash
	  git switch master
	  ```

## 合并分支

现在我们可以在 `dev` 上正常进行提交了。

1. 首先**修改 `readme.txt` 文件并且提交**

2. 现在假设我们 `dev` 分支的工作已经完成，**切换回 `master` 分支**

   ```bash
   git checkout master
   ```

   执行过后你会发现，在 `dev` 分支上进行的修改消失了，回退到了 `master` 分支所在的提交点

3. **合并分支**：把 `dev `分支的工作合并到 `master` 分支上

   ```bash
   git merge dev
   ```

   合并后，我们可以发现 `readme.txt` 的内容和 `dev` 分支的最新提交**是完全一样的**。

   这一步实际上是将 `master` 指针指向 `dev` 的最新提交，从而完成合并。

   <img src="5-4.png" style="width:30%;display: block;margin: 20px auto;">

> 在进行上述合并分支操作时，可以看到使用的是 `Fast-forward` 模式，但是此时使用 `git log` 就**无法看出曾经做过合并**。
>
> 如果想要**用普通模式进行合并**，则执行
>
> ```bash
> git merge --no-ff -m "merge with no-ff" dev
> ```
>
> 这个命令会**在 `merge` 时生成一个新的 `commit`**，从而可以使用 `git log` 查看分支合并的历史。

## 删除分支

1. 合并之后，我们可以放心的**删除 `dev` 分支**了

   ```bash
   git branch -d dev
   ```

   > 如果要**丢弃一个没有被合并过**的分支，可以通过 `git branch -D <name>` 强行删除

2. 此时查看当前分支，发现只剩下 `master` 分支（删除了 `dev` 指针）

   >因为创建、合并和删除分支非常快，所以 Git 鼓励我们使用分支完成某个任务，合并后再删掉分支，
   >
   >这和直接在 `master` 分支上工作效果是一样的，**但过程更安全**
