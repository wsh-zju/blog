---
title: 【macOS 终端】Oh My Zsh + Powerlevel10k，让你的 Mac 终端告别“黑白时代”
date: 2026-03-09 20:00:00
updated: 2026-03-09 22:00:00 # 显示最后更新时间，对技术文章很重要
tags: 
  - macOS
  - 终端
  - Oh My Zsh   
  - Powerlevel10k
categories: 
  - 工具配置
toc: true # 确保开启右侧目录，阅读长文必备
mathjax: true # 如果文章包含数学公式，一定要开启这个！
excerpt: maccOS 终端美化基础篇
---


## NO.1 赋予终端“灵魂” (Oh My Zsh)

macOS 默认使用 Zsh，我们需要安装 **Oh My Zsh** 来管理终端的各种插件与主题。

1. **安装 Oh My Zsh**：打开 macOS 自带的“终端”，粘贴以下命令并回车：

```bash
sh -c "$(curl -fsSL [https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh](https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh))"

```

2. 检查环境：安装成功后，你的终端光标样式将会发生变化，这说明 Oh My Zsh 已接管了你的终端配置：

```bash
➜  ~ git:(master) ✗ 
```

---

## NO.2 安装依赖字体

**Nerd Fonts** 是一系列开源字体的集合，被特别增强，包含大量开发工具、编程语言和版本控制系统的图标。

1. **下载字体**：下载 [MesloLGS NF 字体](https://www.google.com/search?q=https://github.com/romkatv/powerlevel10k-media/raw/master/MesloLGS%2520NF%2520Regular.ttf)（直接下载 `.ttf` 文件即可）。
2. **安装**：双击下载的 `.ttf` 文件进行安装。
3. **设置**：打开终端设置 `(Terminal -> Settings)` -> 描述文件 (Profiles) -> 文本 (Text) -> 字体 (Font) -> 更改 -> 选择 **MesloLGS NF**。

---

## NO.3 安装 Powerlevel10k 主题

1. **下载主题**：执行以下命令将主题克隆到 Oh My Zsh 的自定义主题目录中：

```bash
git clone --depth=1 [https://github.com/romkatv/powerlevel10k.git](https://github.com/romkatv/powerlevel10k.git) ${ZSH_CUSTOM:-$HOME/.oh-my-zsh/custom}/themes/powerlevel10k
```

2. **修改配置文件**：打开 `.zshrc` 文件：

```bash
nano ~/.zshrc
```

找到 `ZSH_THEME="robbyrussell"`，修改为：

```bash
ZSH_THEME="powerlevel10k/powerlevel10k"
```

3. **保存并退出**：按下 `Ctrl + O` 保存 -> 回车确认 -> `Ctrl + X` 退出。

> **温馨提示**：修改 `.zshrc` 时，请注意不要覆盖原有的环境变量或 alias 配置，建议操作前先执行 `cp ~/.zshrc ~/.zshrc.bak` 进行备份。

---

## NO.4 激活并配置

1. **刷新配置**：运行以下命令使配置立即生效：

```bash
source ~/.zshrc
```

2. **启动配置向导**：执行上述命令后，屏幕上会自动跳出 Powerlevel10k 的配置向导，按照终端里的引导，选择你喜欢的图标风格和配色即可完成美化！

