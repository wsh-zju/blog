# Lucy Wisteria's Blog

Hexo 博客，使用 [FlatPaper](https://github.com/Homulilly/hexo-theme-flatpaper) 主题。

## 本地预览

```bash
npm ci
npm run clean
npm run build
npm run server
```

打开 http://localhost:4000/blog/ 。停止服务按 `Ctrl+C`。

## 配置与写作

- `_config.yml`：站点标题、网址、语言、文章链接、RSS 与站点地图。
- `_config.flatpaper.yml`：主题配色、头像、导航、精选文章、赞赏、Giscus 与统计。
- `source/_posts/`：现有文章；写新文章用 `npx hexo new "文章标题"`。
- `source/images/`：站点图片。在 front-matter 中使用 `cover: /images/文件名.jpg` 可设置封面。
- `source/categories/`、`source/tags/`、`source/about/`：导航页面。

`_config.flatpaper.yml` 由 Hexo 自动加载，无需额外传 `--config`。
首页精选在 `featured` 中填写文章标题或 slug，最多四篇。
Giscus 通过 `scripts/giscus.js` 接入，沿用原仓库与 pathname 映射；
页面 front-matter 设置 `comments: false` 可关闭评论。

## 发布与主题来源

将更改提交并推送到 `main` 后，GitHub Actions 会构建并部署到 `gh-pages`。
站点地址为 https://wsh-zju.github.io/blog/ 。

主题源文件直接存放在 `themes/flatpaper/`，便于 GitHub Actions 完整检出，
来源版本为上游提交 `2ef419372d7f99fa7427b42f02401e891c4ad458`（0.4.0）。
更新主题时保留该目录的 MIT 许可证，站点定制继续放在根目录主题配置和 `scripts/`。

原 `_config.icarus.yml` 保留备查。临时切回原主题可将 `_config.yml` 的
`theme` 改回 `icarus`，再清理并重新构建。
