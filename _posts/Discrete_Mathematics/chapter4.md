### 定理 3 费马小定理
如果\(p\)为素数，\(a\)是一个不能被\(p\)整除的整数，则

\[
a^{p - 1}\equiv 1\pmod{p}
\]

再者，对每个整数\(a\)都有

\[
a^{p}\equiv a\pmod{p}
\]

!!! note "欧拉函数"
    \(\varphi(n)\)为欧拉函数，表示小于\(n\)的与\(n\)互质的数的个数 
    
    - 当\(n\)为质数时，\(\varphi(n)=n - 1\)，则
        
        \[
        a^{\varphi(n)}\equiv 1\pmod{n}
        \]

    - 若\(p\neq q\)且\(p\)，\(q\)为质数，\(\varphi(pq)=(p - 1)(q - 1)\) 

### 定理 2 中国剩余定理
令\(m_1,m_2,\cdots,m_n\)为大于\(1\)的**两两互素**的正整数，而\(a_1,a_2,\cdots,a_n\)是任意整数。则同余方程组：

\[
x\equiv a_1\pmod{m_1}
\]

\[
x\equiv a_2\pmod{m_2}
\]

\[
\cdots
\]

\[
x\equiv a_n\pmod{m_n}
\]

有唯一的模\(m = m_1m_2\cdots m_n\)的解。（即，存在一个满足\(0\leq x\leq m\)的解\(x\)，而所有其他的解均与此解模\(m\)同余。）

**求解方法**：

1. 要构造一个满足所有方程的解，首先令

\[
M_k = m/m_k，k = 1,2,\cdots,n
\] 

2. 存在整数\(y_k\)，使得

\[
M_ky_k\equiv 1\pmod{m_k}
\]

求出\(y_k\)

3. 取和

\[
x = a_1M_1y_1 + a_2M_2y_2+\cdots+a_nM_ny_n
\]

??? note "同余方程组求解"
    **Question:**
    
    同余方程组为：

    \(x\equiv 2\pmod{3}\)
    \(x\equiv 3\pmod{5}\)
    \(x\equiv 2\pmod{7}\)

    **Answer:**

    1. **计算相关参数**
    令 \(m = 3\times5\times7=105\)
    \(M_1=\frac{m}{3}=35\)
    \(M_2=\frac{m}{5}=21\)
    \(M_3=\frac{m}{7}=15\)

    2. **求模逆元**
    - 因为 \(35\times2\equiv2\times2\equiv1\pmod{3}\)，所以 \(2\) 是 \(M_1 = 35\) 模 \(3\) 的逆，即 \(y_1 = 2\)。
    - 因为 \(21\equiv1\pmod{5}\)，所以 \(1\) 是 \(M_2 = 21\) 模 \(5\) 的逆，即 \(y_2 = 1\)。
    - 因为 \(15\equiv1\pmod{7}\)，所以 \(1\) 是 \(M_3 = 15\) 模 \(7\) 的逆，即 \(y_3 = 1\)。

    3. **计算同余方程组的解**
    根据公式 \(x\equiv a_1M_1y_1 + a_2M_2y_2 + a_3M_3y_3\pmod{m}\)，其中 \(a_1 = 2\)，\(a_2 = 3\)，\(a_3 = 2\)。
    \[
    \begin{align*}
    x&\equiv 233\pmod{105}\\
    &\equiv 23\pmod{105}
    \end{align*}
    \]

    所以，\(23\) 是该同余方程组的最小正整数解 