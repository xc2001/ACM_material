### Borrow

设钱较少的两人差钱最多的人分别$x，y$单位的钱，设$dp[x][y]$为达到平均状态的期望次数，$dp[0][0] = 0$。暂且设$x > y$, 那么转移分以下三种情况: 
	如果$y > 1$，那么$dp[x][y] = 1 + \frac{1}{2}(dp[x - 2][y - 1] + dp[x - 1][y - 2])$。
	如果$y = 1$，那么$dp[x][1] = 1 + \frac{1}{2}(dp[x - 2][0] + dp[x][1])$ 即$dp[x][1] = 2 + dp[x - 2][0]$。
	如果$y = 0$，那么$dp[x][0] = 1 + \frac{1}{2}(dp[x - 1][1] + dp[x + 1][2])$。又有$dp[x + 1][2] = 1 + \frac{1}{2}(dp[x - 1][1] + dp[x][0])$, 那么$dp[x][0] = \frac{3}{2} + \frac{3}{4}dp[x - 1][1] + \frac{1}{4}dp[x][0]$即$dp[x][0] = 2 + dp[x - 1][1]$。

由第二种和第三种情况的转移公式，我们可以求出所有$dp[x][0], dp[x][1], dp[0][y], dp[1][y]$的值。想要由起始状态达到最终状态，必须先出现第二种和第三种中的某一种情况，在那之前一定是第一种情况。而第一种情况中，每次$x+y$的变化量都是$-3$，我们借由组合数可以算出起始状态经过固定次数到达第二种或者第三种状态的概率，答案就是概率 乘以 期望值与固定次数的和 的和。


