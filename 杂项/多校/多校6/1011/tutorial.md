不存在三点共线时使用极角排序维护两侧点不出现的概率并对每条有向线段单独计算贡献即可。

考虑存在$n$点共线时该直线上的有向线段的贡献：

设直线左侧一个点都不出现的概率为$q_L$，右侧一个点都不出现的概率为$q_R$，直线上的点的坐标为$c_i$，$\times$为叉乘，则贡献为：
$$
(q_R(1-q_L)-q_L(1-q_R))\sum_{l=1}^{n-1}\sum_{r=l+1}^n(p_l\prod_{i=1}^{l-1}(1-p_i)c_l \times p_r\prod_{i=r+1}^n(1-p_i)c_r)
$$
由叉乘的双线性性可以用类似前缀和的东西将该步的复杂度降为线性。总复杂度$O(n^2\log n)$。

注意到没有点出现的概率是$0$或$1$可以降低代码量。

