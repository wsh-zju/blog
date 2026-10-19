---
title: 远程仓库
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



我们已经掌握了本地“时光穿梭”，是时候见识 Git 的杀手锏了：**远程仓库**。

与老牌的 SVN 不同，Git 的分布式特性让每一台机器都拥有完整的版本库。虽然你可以在一台电脑上克隆多个仓库玩，但 Git 真正的威力在于**协作**。我们找一台 24 小时开机的服务器充当枢纽，大家各自提交、互相拉取，这才是现代开发的常态。

而 **Github** 就是这样一个 提供 Git 仓库托管服务的网站。

## 设置 Github

1. **自行注册 Github 账号**

2. 由于你的本地 Git 仓库和 GitHub 仓库之间的传输是通过 SSH 加密的，所以我们需要进行如下设置

   - **创建 SSH Key**：

     - 查看本机用户主目录下是否有 `.ssh` 目录

     - 如果有，再看这个目录下有没有 `id_rsa` 和 `id_rsa.pub` 这两个文件

       - 如果已经有了，可直接跳到下一步

       - 如果没有，打开终端，创建SSH Key（一路回车即可）

         ```bash
         ssh-keygen -t rsa -C "youremail@example.com"
         ```

     > `id_rsa` 和 `id_rsa.pub` 这两个文件个就是SSH Key的秘钥对
     > `id_rsa` 是私钥，不能泄露出去，` id_rsa.pub` 是公钥，可以放心地告诉任何人

      - **登陆 GitHub** 
        - 打开用户设置界面，找到“SSH and GPG keys”
        - **新建 SSH key**：填入任意的 title ，在 Key 文本框里粘贴 `id_rsa.pub` 文件的内容，就可以填加成功了

## 添加远程仓库

我们已经在本地创建了一个 Git 仓库，又想在 GitHub 创建一个 Git 仓库，并且让这两个仓库进行远程同步。这样，GitHub 上的仓库既可以作为备份，又可以让其他人通过该仓库来协作，真是一举多得。

1. **首先登陆GitHub**，在右上角找到“Create new repository”，**创建一个新的仓库**：
   - 在 Repository name 填入 git_repo ，其他保持默认设置
   - 点击“Create repository”按钮，就成功地创建了一个新的 Git 仓库

2. **关联远程仓库**

   - **进入仓库**在仓库的起始界面选择 SSH，根据生成的提示，在本地的 `git_repo` 仓库下执行

     ```bash
     git remote add origin your_SSH
     ```

   - 这个命令可以帮我们**关联新创建的 Github 远程库**，这个远程库的名字是 `origin`（当然也可以随意修改）

3. **将本地仓库的所有内容推送到远程仓库**

   ```bash
   git push -u origin master
   ```

   实际上这个命令是把当前分支 `master` 推送到远程仓库

   > 1. 当然，每一个人的分支名称可能不相同，可以使用 `git branch` 查看当前所处分支
   >
   > 2. `-u`：把本地的 `master` 分支和远程的 `master` 分支关联起来，在以后的推送或者拉取时就可以使用简化命令
   >
   >    ```bash
   >    git push origin master
   >    ```

## 删除远程仓库

1. 如果想在本机上删除远程库，可以先使用

   ```bash
   git remote -v
   ```

   **查看已经添加的远程仓库信息**

2. **删除远程仓库**（根据之前查询到的信息）

   ```bash
   git remote rm origin
   ```

   > 此处的“删除”其实是**解除了本地和远程的绑定关系**，远程库本身并没有任何改动。
   >
   > 要真正删除远程库，需要登录到 GitHub，在仓库的设置界面删除。

## 从远程仓库克隆

如果我们**先创建的是远程仓库**，想要创建一个对应的本地仓库，最好的方式是**从远程仓库克隆**

```bash
git clone your_SSH
```

> 其实，Git支持多种协议，默认的 git:// 使用 SSH ，但也可以使用 HTTPS 等其他协议
