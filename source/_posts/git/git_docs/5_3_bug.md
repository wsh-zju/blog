---
title: Bug 修复
date: 2026-05-06 15:00:00
updated: 2026-05-06 15:00:00 # 显示最后更新时间，对技术文章很重要
tags: 
  - Git
categories: 
  - Git 入门 & 进阶
toc: true     # 是否显示目录（Icarus 侧边栏支持）
thumbnail: images/git.png # Icarus 首页显示的缩略图（可选）
mathjax: true # 如果文章包含数学公式，一定要开启这个！
excerpt: Git 入门 & 进阶
---


软件开发中，Bug 时常不定时的出现，从而，使用新分支修复 Bug 是我们必须要掌握的技能之一。

假如，在我们正**在 `dev` 分支上**进行某些工作，但是还没有完成并且提交。此时，我们突然接到一个修复 Bug 的任务，怎样保证我们在 `dev` 分支上**未提交的工作**不丢失，并且还能修复 Bug 呢？

1. **储藏 `dev` 工作现场**

   ```bash
   git stash
   ```

   - 此时，查看工作区状态，没有需要提交的文件
   - 并且，`dev` 分支上没有提交的内容消失不见了

2. **切换到需要修复 Bug 的分支**（这里以 `master` 为例）

   ```bash
   git switch master
   ```

3. **创建临时分支**

   ```bash
   git checkout -b issue-101
   ```

4. **修复 Bug**，然后再次提交 `commit`

5. 修复完成后，返回 `master` 分支，并完成合并，然后删除临时分支

   ```bash
   git switch master
   git merge --no-ff -m "bug" issue-101
   git branch -d issue-101

6. 现在我们的 Bug 已经修复完毕，现在要**回到 `dev` 继续工作了**

   - **切换回 `dev` 分支**，这时我们会发现文档中的内容并不是我们最新修改的内容，这是因为 Git 把 `stash` 内容存在了某个地方，需要我们进行恢复

   - **查看 `stash` 的内容**

     ```bash
     git stash list
     ```

7. **恢复 `stash` 中的内容**

   - **方法一**：

     - 恢复 `stash` 中的内容（但是不删除 `stash`）

       ```bash
       git stash apply
       ```

     - 手动删除 `stash`

       ```bash
       git stash drop
       ```

   - **方法二**：恢复的同时可以删除 `stash` 中的内容

     ```bash
     git stash pop
     ```

     此时 `stash` 中不再有内容

> 当然我们可以多次 `stash` ，恢复的时候先查看 `stash` 中的内容，然后恢复指定的 `stash`
>
> ```bash
> git stash apply stash@{0}
> ```

8. 由于`dev` 分支是早期从 `master` 分支分出来的，所以存在同样的 Bug ，要想**在 `dev` 分支上修复同样的 Bug** ，我们可以使用

   ```bash
   git cherry-pick <commit>
   ```

   把 Bug 提交的修改“复制”到当前分支，避免重复劳动

> 前提是合并的时候使用 `--no-ff` 模式
