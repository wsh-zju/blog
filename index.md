---
title: Home
layout: default
---
# ヾ(＠^∇^＠)ノ
# Welcome to Lucy Wisteria's Notebook!

## 励志格言
<p style="text-align: center;">有志者，事竟成</p>

<p style="text-align: center;">破釜沉舟，百二秦关终归楚</p>

<p style="text-align: center;">苦心人，天不负</p>

<p style="text-align: center;">卧薪尝胆，三千越甲可吞吴</p>

!!! note "Notice!"
    此文档仅供本人做笔记！不允许复制粘贴！


{% for post in site.posts %}
  <article>
    <h2>{{ post.title | capitalize }}</h2>
    <p class="date">
      发布于 {{ post.date | date: "%Y-%m-%d" }}
    </p>
    <div class="excerpt">
      {{ post.excerpt | strip_html | truncate: 100 }}
    </div>
  </article>
{% endfor %}