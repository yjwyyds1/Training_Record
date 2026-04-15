这个等式成立的核心在于，把被除数 $N$ 用 $M \times P$ 做带余除法展开。下面是具体的推导过程。

设 $N = q \cdot (M \times P) + r$，其中 $q = \left\lfloor \frac{N}{M \times P} \right\rfloor$ 是商，  $r= N \bmod (M \times P)$ 是余数，且 $0 \le r < M \times P$。

**先看等式右边：**

$$
\left\lfloor \frac{N \bmod (M \times P)}{M} \right\rfloor = \left\lfloor \frac{r}{M} \right\rfloor
$$

由于 $r < M \times P$，所以 $\frac{r}{M} < P$，因此 $\left\lfloor \frac{r}{M} \right\rfloor$ 是一个在 $0$ 到 $P-1$ 之间的整数。

**再看等式左边：**

$$
\begin{aligned}
\left\lfloor \frac{N}{M} \right\rfloor &= \left\lfloor \frac{q \cdot (M \times P) + r}{M} \right\rfloor \\
&= \left\lfloor q \cdot P + \frac{r}{M} \right\rfloor \\
&= q \cdot P + \left\lfloor \frac{r}{M} \right\rfloor \quad (\text{因为 } qP \text{ 是整数})
\end{aligned}
$$

然后对 $P$ 取模：

$$
\begin{aligned}
\left\lfloor \frac{N}{M} \right\rfloor \bmod P &= \left( q \cdot P + \left\lfloor \frac{r}{M} \right\rfloor \right) \bmod P \\
&= \left\lfloor \frac{r}{M} \right\rfloor \bmod P
\end{aligned}
$$

因为 $0 \le \left\lfloor \frac{r}{M} \right\rfloor < P$，所以 $\left\lfloor \frac{r}{M} \right\rfloor \bmod P = \left\lfloor \frac{r}{M} \right\rfloor$。

至此，左右两边都等于 $\left\lfloor \frac{r}{M} \right\rfloor$，等式得证。


# 规避模逆元的整除技巧：在更大模数下保留因子信息

这个方法的核心在于**利用更大的模数 $9M$ 来保留“整除性”信息**，从而用**整数除法**代替**模逆元**运算。

## 核心问题

你需要计算：
$\frac{10^{l_i}-1}{9} \times c_i \pmod{M}$

直接计算的障碍是：当 $\gcd(9, M) \neq 1$ 时，$9$ 在模 $M$ 下**没有乘法逆元**，因此无法直接计算 $(10^{l_i}-1) \times 9^{-1} \pmod{M}$。

## 规避原理

关键在于观察到 $10^{l_i} - 1$ 一定是 $9$ 的倍数（因为 $10 \equiv 1 \pmod{9}$，所以 $10^{l_i} \equiv 1 \pmod{9}$）。

### 步骤解析

设 $A = (10^{l_i}-1) \times c_i$，这是一个 $9$ 的倍数。

#### 传统方法（需要逆元）
计算 $A \div 9 \pmod{M}$ 需要 $9^{-1} \pmod{M}$，但 $9$ 可能不可逆。

#### 新技巧（规避逆元）

1. **在模 $9M$ 下计算**  
   计算 $R = A \bmod 9M$，其中 $0 \leq R < 9M$

2. **整除性保持**  
   因为 $A$ 是 $9$ 的倍数，且 $9M$ 也是 $9$ 的倍数，所以余数 $R$ 必然也是 $9$ 的倍数。  
   证明：$A = 9M \cdot q + R$，由于 $A$ 和 $9M \cdot q$ 都是 $9$ 的倍数，所以 $R$ 也是。

3. **整数除法**  
   令 $R = 9 \cdot R'$，则 $R' = R / 9$ 是整数（无需逆元，直接整除）

4. **结果对应**
   
   
   $R' \equiv \frac{A}{9} \pmod{M}$
   
   这是因为：
   - $A \equiv R \pmod{9M}$ 意味着 $A = R + 9M \cdot k = 9R' + 9M \cdot k = 9(R' + M \cdot k)$
   - 所以 $\frac{A}{9} = R' + M \cdot k \equiv R' \pmod{M}$

## 为什么这样可行？

| 特性 | 说明 |
|------|------|
| **信息不丢失** | 模 $9M$ 保留了模 $M$ 的信息，外加一个“是否为 $9$ 的倍数”的标记 |
| **整数除法 vs 模逆元** | 因为 $R$ 在 $[0, 9M)$ 范围内且是 $9$ 的倍数，直接除以 $9$ 得到的 $R'$ 一定满足 $R' \equiv \frac{A}{9} \pmod{M}$ |
| **规避互质限制** | 不需要 $9$ 和 $M$ 互质，因为我们从未在模 $M$ 下尝试“除以 $9$”，而是在整数范围内除法后再取模 |

