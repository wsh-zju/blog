---
title: 工作区与暂存区
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

1. **工作区**：也就是在本机中可以看到的目录，比如后边创建的 `git_repo` 文件夹

2. **版本库**：又名仓库（Repository），可以简单理解成一个目录
   - 在工作区中有一个隐藏目录 `.git`（不属于工作区），这就是 `git init` 创建的版本库
   - 其中存储了很多重要的东西，最重要的是**暂存区** stage、Git 自动创建的第一个分支 `master` 以及指向 `master` 的一个指针 `HEAD`
   - Git 可以管理这个目录里面的所有文件，并且追踪每个文件的修改、删除。

## 创建版本库

1. **创建一个空目录并进入**

   ```bash
   mkdir git_repo
   cd git_repo
   ```

2. **把这个目录变成 Git 可以管理的仓库**

   ```bash
   git init 			
   # 已初始化空的 Git 仓库于 你的目录地址/.git/
   ```

   - 执行成功后，当前目录下会增加一个 `.git` 的目录，这个目录是 Git 用来跟踪管理版本库的（千万不要手动修改这个目录里面的文件，否则会破坏 Git 仓库）

   - 如果没有看到 `.git` 目录，那是因为这个目录默认是隐藏的，在终端输入以下命令就可以显示

     ```bash
     ls --ah
     ```

## 把文件添加到版本库

1. **在 git_repo 目录下创建一个 readme.txt 文件**：内容如下

   ```txt
   Git is a version control system.
   ```

2. **将文件修改添加到暂存区**

   ```bash
   git add readme.txt
   ```

3. **把暂存区的所有内容提交到当前分支**

   ```bash
   git commit -m "提交说明"
   ```

   在创建版本库时，Git 自动创建了目前唯一一个分支 `master`，此时就是往 `master` 分支上提交更改
