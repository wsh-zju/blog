'use strict';

// Keep this site-specific integration outside the vendored theme.
const { escapeHTML } = require('hexo-util');
const contentPages = new Map();

hexo.extend.filter.register('before_generate', function () {
  contentPages.clear();
  for (const collection of ['posts', 'pages']) {
    this.locals.get(collection).forEach(page => {
      contentPages.set(new URL(page.permalink).pathname, page);
    });
  }
});

hexo.extend.filter.register('after_render:html', function (html) {
  const theme = this.theme.config;
  if (this.config.theme !== 'flatpaper' || theme.comments !== 'giscus') return html;
  const canonical = html.match(/<link rel="canonical" href="([^"]+)"/);
  if (!canonical) return html;
  const page = contentPages.get(new URL(canonical[1]).pathname);
  if (!page || page.comments === false || page.layout === '404') return html;

  const config = theme.giscus || {};
  if (!config.repo || !config.repo_id || !config.category_id) return html;
  const attributes = Object.entries(config).map(([key, value]) =>
    `data-${key.replace(/_/g, '-')}="${escapeHTML(String(value))}"`
  ).join(' ');
  const section = `<section class="comments-section" id="comments" aria-label="评论">
<header class="comments-section__head"><h2>评论</h2></header>
<div class="giscus"></div>
<script src="https://giscus.app/client.js" ${attributes} crossorigin="anonymous" async></script>
</section>`;
  // The last section before </main> is the content column on posts and pages.
  const mainEnd = html.indexOf('</main>');
  const contentEnd = html.lastIndexOf('</section>', mainEnd);
  if (mainEnd < 0 || contentEnd < 0) return html;
  return html.slice(0, contentEnd) + section + html.slice(contentEnd);
});
