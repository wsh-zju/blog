---
title: Git 介绍与安装
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

# Git 介绍与安装

## 什么是 Git ？

Git 是目前世界上最先进的**分布式版本控制系统**（没有之一）！

Git 可以自动帮助你记录每次文件的细微改动，同时也可以实现与他人协作编辑，大大提升了开发的效率。

## Git 安装

我们可以在 Linux、Mac 以及 Windows 上安装 Git 并且正常使用。

首先，检查你的电脑上是否已经安装了 Git

```bash
git --version			# 查看已经安装的 git 的版本号
```

如果正常输出版本号，说明已经正确安装；如果并没有输出版本号，则需要参照以下教程安装。

1. **在 Linux 上安装 Git**

   - 如果你使用的是 Debian 或 Ubuntu Linux，在终端输入以下命令进行安装

     ```bash
     sudo apt install git
     ```

   - 如果是其他版本的 Linux，则需要参考其发行版说明进行安装

2. **在 macOS 上安装 Git**

   - **方法一**：通过 Homebrew 安装 Git

     ```bash
     brew install git
     ```

   - **方法二**：安装 Xcode 命令行工具

     ```bash
     xcode-select --install  
     ```

3. **在 Windows 上安装 Git**

   			- **方法一**：

   			- 

## Git 配置

因为 Git 是分布式版本控制系统，所以每个机器都必须自报家门：你的名字和 Email 地址。

首先我们先查看是否已经进行正确配置（q -> Enter 退出配置界面）

```bash
git config --list
```

如果已经有正确的 user.name 和 user.email ，我们可以跳过这个配置的步骤；如果没有正确配置，在终端输入以下命令进行配置

```bash
git config --global user.name "Your Name"
git config --global user.email "email@example.com"
```

> **注意** 
>
> git config 命令的 --global 参数表示你这台机器上所有的 Git 仓库都会使用这个配置，当然也可以对某个仓库指定不同的用户名和 Email 地址
