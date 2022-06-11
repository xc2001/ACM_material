const double eps = 1.010000e-06;
const double ans[] = {
  87.00000000000000000000,
  35.99999999999999995837,
  21.99999999999999998439,
  60.00000000000000000000,
  26.99999999999999999133,
  69.00000000000000000000,
  30.99999999999999997918,
  35.99999999999999999653,
  59.00000000000000000000,
  57.00000000000000000000,
  74.00000000000000000000,
  37.99999999999999997918,
  71.00000000000000000000,
  81.00000000000000000000,
  70.99999999999999996531,
  26.00000000000000000000,
  5.99999999999999990242,
  58.00000000000000000000,
  45.99999999999999998959,
  65.00000000000000000000,
  8.99999999999999950213,
  85.00000000000000000000,
  99.99999999999999999306,
  68.99999999999999997918,
  87.00000000000000000000,
  70.99999999999999995143,
  1.99999999999999610370,
  92.99999999999999997918,
  81.00000000000000000000,
  90.00000000000000000000,
  29.99999999999999999653,
  71.99999999999999994449,
  28.00000000000000000000,
  54.00000000000000000000,
  84.00000000000000000000,
  72.00000000000000000000,
  20.00000000000000000000,
  15.99999999999999999913,
  23.99999999999999996531,
  52.00000000000000000000,
  89.00000000000000000000,
  51.00000000000000000000,
  65.00000000000000000000,
  57.00000000000000000000,
  65.99999999999999995837,
  52.00000000000000000000,
  7.99999999999999970770,
  95.99999999999999998612,
  93.99999999999999999306,
  11.99999999999999997311,
  4.99999999999999914522,
  39.00000000000000000000,
  19.00000000000000000000,
  17.99999999999999994275,
  44.00000000000000000000,
  99.99999999999999997918,
  91.00000000000000000000,
  87.00000000000000000000,
  65.00000000000000000000,
  4.99999999999999974456,
  28.99999999999999999653,
  68.99999999999999999306,
  11.00000000000000000000,
  30.99999999999999998786,
  37.00000000000000000000,
  65.99999999999999999306,
  59.00000000000000000000,
  24.99999999999999999133,
  99.99999999999999999306,
  71.99999999999999997918,
  30.99999999999999997051,
  64.00000000000000000000,
  96.99999999999999994449,
  69.00000000000000000000,
  66.99999999999999998612,
  85.00000000000000000000,
  7.99999999999999992627,
  18.99999999999999994102,
  72.99999999999999999306,
  10.99999999999999995056,
  1.99999999999999996444,
  56.00000000000000000000,
  4.99999999999999996661,
  67.99999999999999999306,
  51.00000000000000000000,
  24.99999999999999999827,
  82.00000000000000000000,
  72.99999999999999996531,
  86.00000000000000000000,
  42.99999999999999999653,
  91.00000000000000000000,
  82.00000000000000000000,
  56.00000000000000000000,
  69.99999999999999994449,
  56.00000000000000000000,
  85.00000000000000000000,
  68.00000000000000000000,
  55.00000000000000000000,
  2.99999999999999992497,
  21.99999999999999994449,
};
const int T = sizeof(ans) / sizeof(ans[0]);

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <cmath>
using namespace std;

const int maxn = 3e5;
typedef double real;

int n;
char s[maxn + 1];
int m;
int head[maxn];

void WrongAnswer(void) {
  puts("WA");
  exit(0);
}

void Accepted(void) {
  puts("AC");
  exit(0);
}

int main(void) {
  n = fread(s, 1, maxn, stdin);
  s[n] = '\0';
  m = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && s[j] != '\n') ++j;
    int k = j;
    while (k > i && isspace(s[k - 1])) --k;
    s[k] = '\0';
    head[m++] = i;
    i = j + 1;
  }
  while (m > 0 && s[head[m - 1]] == '\0') --m;

  if (m != T) {
    WrongAnswer();
  }
  for (int i = 0; i < T; ++i) {
    real x, y = ans[i];
    sscanf(s + head[i], "%lf", &x);
    if (!isfinite(x)) {
      WrongAnswer();
    }
    if (abs(x - y) > max(1.0, abs(y)) * eps) {
      WrongAnswer();
    }
  }
  Accepted();
}
