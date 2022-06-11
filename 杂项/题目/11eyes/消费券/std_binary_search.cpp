#include <bits/stdc++.h>

using ll = long long;
using namespace std;

constexpr int INF = 0x3f3f3f3f;
constexpr ll N = 100000 + 5;

int n, m, start, k, cnt;
vector<pair<int, int> > G[N];

bool check(int x) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> d(n + 1, INF);
    vector<bool> vis(n + 1);
    q.push({d[start] = 0, start});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if (d[v] > d[u] + (w > x)) {
                q.push({d[v] = d[u] + (w > x), v});
            }
        }
    }
    return d[k] <= cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("/Users/sunyin/Desktop/ACM/11eyes/消费券/hard_sample/5.in", "r", stdin);
    freopen("/Users/sunyin/Desktop/ACM/11eyes/消费券/hard_sample/5.out", "w", stdout);

    cin >> n >> m >> start >> k >> cnt;
    assert(n >= 1 && n <= 100000);
    assert(m >= 1 && m <= 200000);
    assert(cnt >= 0 && cnt <= 200);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        assert(u >= 1 && u <= 100000);
        assert(v >= 1 && v <= 100000);
        assert(w >= 1 && w <= 1000000000);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    int L = 0, R = 1000000001, mid, ans = -1;
    while (L < R) {
        mid = (L + R) / 2;
        if (check(mid)) {
            R = mid;
            ans = mid;
        } else {
            L = mid + 1;
        }
    }
    assert(ans >= 0 && ans <= 1000000000);
    if (ans == -1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << ans << '\n';
    }
    
    return 0;
}