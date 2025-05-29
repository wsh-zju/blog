## 提示框
### 普通提示框

代码如下：

1. 提示框的配置

    ```yaml
    markdown_extensions:
        - admonition
        - pymdownx.details
        - pymdownx.superfences
    theme:
        icon:
            admonition:
            note: octicons/tag-16
            abstract: octicons/checklist-16
            info: octicons/info-16
            tip: octicons/squirrel-16
            success: octicons/check-16
            question: octicons/question-16
            warning: octicons/alert-16
            failure: octicons/x-circle-16
            danger: octicons/zap-16
            bug: octicons/bug-16
            example: octicons/beaker-16
            quote: octicons/quote-16
    ```

2. 内容如下：

    ```markdown
    !!! note "这是 note 类型的提示框" 
        提示：更多精彩内容记得关注我啊

    !!! success "这是 success 类型的提示框" 
        成功！

    !!! failure "这是 failure 类型的提示框" 
        失败！

    !!! bug "这是 bug 类型的提示框" 
        发现一个 bug，请尽快修复！
    ```

显示样例如下：

!!! note "这是 note 类型的提示框" 
    提示：更多精彩内容记得关注我啊

!!! success "这是 success 类型的提示框" 
    成功！

!!! failure "这是 failure 类型的提示框" 
    失败！

!!! bug "这是 bug 类型的提示框" 
    发现一个 bug，请尽快修复！

### 可以折叠的提示框：

代码如下
    ```markdown
    ??? note "这是 note 类型的提示框"
        提示：更多精彩内容记得关注我啊

        第二行

        第三行

        第四行

        第五行
        ...
    ```
    
显示样例：

??? note "这是 note 类型的提示框" 
    提示：更多精彩内容记得关注我啊

    第二行

    第三行

    第四行

    第五行
    ...



##代码高亮

代码如下：
    ```yaml
    theme:
        name: material
    markdown_extensions:
        - pymdownx.highlight:
            anchor_linenums: true
        - pymdownx.inlinehilite
        - pymdownx.snippets
        - pymdownx.superfences
    ```