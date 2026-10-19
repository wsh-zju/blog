---
title: 冲突解决
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



## 冲突的产生

虽然分支合并非常快速且方便，但是仍会存在一些难以避免的问题。

1. **新建分支 `feature1`**

   ```bash
   git switch -c feature1
   ```

2. 在新分支上对 `readme.txt` 文件**作修改并提交**

3. **切换回 `master` 分支**

   ```bash
   git switch master
   ```

4. 在 `master` 分支上对 `readme.txt` 再次修改并提交

5. 此时，分支状态如下图所示
   
   <img src="5-5.png" style="width:30%;display: block;margin: 20px auto;">
   
   这种情况下如果合并分支，就可能会**产生冲突**

6. **尝试合并 `feature1` 分支**

   ```bash
   git merge feature1
   ```

   - 运行之后，Git 会告诉我们 `readme.txt` 文件存在冲突，必须**手动解决后再提交**
   - 并且在 `readme.txt` 文件中会用 `<<<<<<<` ， `======= `，` >>>>>>>` 标记出不同分支的内容

## 冲突的解决

1. 冲突产生后，我们需要决定留下哪个分支的内容，**手动修改后**，再次提交

   ```bash
   git add readme.txt 
   git commit -m "conflict fixed"
   ```

2. 现在，分支的状态如下图所示

   <img src="5-6.png" style="width:30%;display: block;margin: 20px auto;">

3. **删除 `feature1` 分支**

   ```bash
   git branch -d feature1
   ```

   此时，我们就成功合并了两个冲突的分支。
