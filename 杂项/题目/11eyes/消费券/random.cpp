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

    freopen("/Users/sunyin/Desktop/ACM/11eyes/消费券/hard_sample/0.in", "w", stdout);

    int T = 1;
    while (T--) {
        srand((unsigned)time(0));
        int n = 100000;
        int m = random(100000) + 1 + 100000;
        for (int i = 1; i < n; i++) {
            int fa = random(i) + 1;
            e[i] = make_pair(fa, i + 1);
            h[e[i]] = h[make_pair(i + 1, fa)] = true;
        }
        for (int i = n; i <= m; i++) {
            int x, y;
            do {
                x = random(n) + 1, y = random(n) + 1;
            } while(x == y || h[make_pair(x, y)]);
            e[i] = make_pair(x, y);
            h[e[i]] = h[make_pair(y, x)] = true;
        }
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle(e + 1, e + 1 + m, default_random_engine(seed));
        int start = random(n) + 1, end = random(n) + 1, cnt = random(201);
        assert(cnt >= 0 && cnt <= 200);
        cout << n << " " << m << " " << start << " " << end << " " << cnt << '\n';
        for (int i = 1; i <= m; i++) {
            int w = random(1000000000) + 1;
            while (vis.count(w)) w = random(1000000000) + 1;
            vis[w] = true;
            cout << e[i].first << " " << e[i].second << " " << w << '\n';
        }
    }
    
    return 0;
}