## 树
1. **节点与边的关系**

$n_x$ :下标 $x$ 表示有 $x$ 个子节点

公式：$\sum in_i = \sum n_i - 1$ ，其中 $\sum in_i$ 表示边数，$\sum n_i$ 表示总节点个数

### 树的遍历（traversal）

```
    1
   / \
  2   3
 / \ / \
4  5 6  7
```

- **中序遍历（inorder）**
    - 顺序：左→根→右
    - e.g. $4 \to 2 \to 5 \to 1 \to 6 \to 3 \to 7$
- **先序遍历（preorder）**
    - 顺序：根→左→右
    - e.g. $1 \to 2 \to 4 \to 5 \to 3 \to 6 \to 7$
- **后序遍历（postorder）**
    - 顺序：左→右→根
    - e.g. $4 \to 5 \to 2 \to 6 \to 7 \to 3 \to 1$ 
- **层序遍历（level - order）**
    - 逐层遍历
    - e.g. $1 \to 2 \to 3 \to 4 \to 5 \to 6 \to 7$ 