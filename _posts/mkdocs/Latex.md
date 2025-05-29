

## 希腊字母

| 符号 | LaTeX 代码 | 符号 | LaTeX 代码 |
|------|------------|------|------------|
| $\alpha$    | `\alpha`   | $A$    | `A`   |
| $\beta$    | `\beta`    | $B$    | `B`    |
| $\gamma$    | `\gamma`   | $\Gamma$    | `\Gamma`   |
| $\delta$    | `\delta`   | $\Delta$    | `\Delta`   |
| $\epsilon$    | `\epsilon` | $E$    | `E` |
| $\zeta$    | `\zeta`    | $Z$    | `Z`    |
| $\eta$    | `\eta`     | $H$    | `H`     |
| $\theta$    | `\theta`   | $\Theta$    | `\Theta`   |
| $\lambda$    | `\lambda`  | $\Lambda$    | `\Lambda`  |
| $\mu$    | `\mu`      | $M$    | `M`      |
| $\pi$    | `\pi`      | $\Pi$    | `\Pi`      |
| $\sigma$    | `\sigma`   | $\Sigma$    | `\Sigma`   |
| $\omega$    | `\omega`   | $\Omega$    | `\Omega`   |

## 运算符

| 符号 | LaTeX 代码 | 符号 | LaTeX 代码 |
|------|------------|------|------------|
| $+$    | `+`        | $-$    | `-`        |
| $\times$    | `\times`   | $\div$    | `\div`     |
| $\pm$    | `\pm`      | $\mp$    | `\mp`      |
| $\cdot$    | `\cdot`    | $\ast$    | `\ast`     |
| $\leq$    | `\leq`     | $\geq$    | `\geq`     |
| $\leqslant$ | `\leqslant` | $\geqslant$ | `\geqslant` |
| $\nless$ | `\nless`    | $\ngtr$ | `\ngtr`      |
| $\nleq$ | `\nleq`      | $\ngeq$ | `\ngeq`      |
| $\ll$ | `\ll`        | $\gg$ | `\gg`        |
| $\prec$ | `\prec`      | $\succ$ | `\succ`      |
| $\preceq$ | `\preceq`    | $\succeq$ | `\succeq`    | 
| $\neq$    | `\neq`     | $\approx$    | `\approx`  |
| $\equiv$    | `\equiv`   | $\propto$    | `\propto`  |
| $\infty$    | `\infty`   | $\partial$    | `\partial` |
| $\nabla$    | `\nabla`   | $\sqrt{x}$    | `\sqrt{x}`  |
| $\int$    | `\int`     | $\iint$    | `\iint`    |
| $\sum$    | `\sum`     | $\prod$    | `\prod`    |
| $\cap$    | `\cap`     | $\cup$    | `\cup`     |
| $\in$    | `\in`      | $\notin$    | `\notin`   |
| $\subset$    | `\subset`  | $\supset$    | `\supset`  |
| $\perp$    | `\perp`    | $\angle$    | `\angle`   |

## 箭头符号

| 符号 | LaTeX 代码 | 符号 | LaTeX 代码 |
|------|------------|------|------------|
| $\to$ 或 $\rightarrow$ | `\to` 或 `\rightarrow` | $\leftarrow$ | `\leftarrow` |
| $\Rightarrow$ | `\Rightarrow` | $\Leftarrow$ | `\Leftarrow` |
| $\leftrightarrow$ | `\leftrightarrow` | $\Leftrightarrow$ | `\Leftrightarrow` |
| $\uparrow$ | `\uparrow` | $\downarrow$ | `\downarrow` |
| $\mapsto$ | `\mapsto` | $\rightharpoonup$ | `\rightharpoonup` |

## 括号和定界符

| 符号 | LaTeX 代码 | 符号 | LaTeX 代码 |
|------|------------|------|------------|
| $( )$  | `( )`      | $[ ]$  | `[ ]` 或 `\lbrack \rbrack` |
| $\{ \}$  | `\{ \}`    | $\langle \rangle$  | `\langle \rangle` |
| $\lceil \rceil$   | `\lceil \rceil` | $\lfloor \rfloor$ | `\lfloor \rfloor` |
| $\|$   | `\|` 或 `\Vert` | $\left( \right)$ | `\left( \right)` |

## 数学结构

1. **分数**: `\frac{分子}{分母}` 或 `\dfrac{分子}{分母}` (显示模式)
   
   - 示例: `\frac{a}{b}` → $\frac{a}{b}$

2. **上下标**:
   
   - 上标: `x^2` → $x^2$
   - 下标: `x_1` → $x_1$
   - 组合: `x^{a+b}` → $x^{a+b}$ 或 `x_{i,j}` → $x_{i,j}$

3. **根号**:
   
   - 平方根: `\sqrt{x}` → $\sqrt{x}$
   - n次方根: `\sqrt[n]{x}` → $\sqrt[n]{x}$

4. **矩阵**:

$$
\begin{matrix}
a & b \\
c & d 
\end{matrix}
$$

```latex
\begin{matrix}
a & b \\
c & d 
\end{matrix}
```
   
或带括号的矩阵:

$$
\begin{pmatrix}
a & b \\
c & d 
\end{pmatrix}
$$

```latex
\begin{pmatrix}
a & b \\
c & d 
\end{pmatrix}
```

5. **分段函数**:

$$
f(x) = \begin{cases}
x & \text{如果 } x \geq 0 \\
-x & \text{如果 } x < 0
\end{cases}
$$

```latex
f(x) = \begin{cases}
x & \text{如果 } x \geq 0 \\
-x & \text{如果 } x < 0
\end{cases}
```

## 常用数学环境

1. 行内公式: `$...$` 或 `\(...\)`
2. 显示公式: `\[...\]` 或 `\begin{equation}...\end{equation}`
3. 多行公式: `\begin{align}...\end{align}`
4. 编号公式: `\begin{equation}...\end{equation}`

## 其他常用符号

| 符号 | LaTeX 代码 | 描述 |
|------|------------|------|
| $\aleph$    | `\aleph`   | 阿列夫数 |
| $\hbar$    | `\hbar`    | 约化普朗克常数 |
| $\Im$    | `\Im`      | 虚部 |
| $\Re$    | `\Re`      | 实部 |
| $\prime$    | `\prime`   | 素数符号 |
| $\emptyset$    | `\emptyset` | 空集 |
| $\forall$    | `\forall`  | 全称量词 |
| $\exists$    | `\exists`  | 存在量词 |
| $\neg$    | `\neg`     | 逻辑非 |
| $\oplus$    | `\oplus`   | 异或 |
| $\otimes$    | `\otimes`  | 张量积 |
| $\odot$    | `\odot`    | 点积 |
| $\therefore$    | `\therefore` | 所以 |
| $\because$    | `\because` | 因为 |



