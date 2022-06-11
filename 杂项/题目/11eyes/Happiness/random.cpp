#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ls (p << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
#define lowbit(x) ((x) & -(x))

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr double eps = 1e-8;
constexpr int NINF = 0xc0c0c0c0;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LNINF = 0xc0c0c0c0c0c0c0c0;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3f;
constexpr ll mod = 1e9 + 7;
constexpr ll N = 2e5 + 1;

pair<int, int> e[N];
map<pair<int, int>, bool> h;
map<int, bool> vis;

int random(int n) {
    return 1ll * rand() * rand() % n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("/Users/sunyin/Documents/problems/Happiness/sample/4.in", "w", stdout);

    int T = 1;
    while (T--) {
        srand((unsigned)time(0));
        int n = 4000;
        cout << n << '\n';
        assert(n >= 1 && n <= 5000);
        for (int i = 0; i < n; i++) {
            int x = random(1000000000) + 1;
            assert(x >= 1 && x <= 1000000000);
            cout << x << " \n"[i == n - 1];
        }
    }
    
    return 0;
}