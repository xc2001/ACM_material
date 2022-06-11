#include <bits/stdc++.h>

using ll = long long;
using namespace std;

constexpr int INF = 0x3f3f3f3f;
constexpr ll N = 100000 + 5;

int n, m, start, k, cnt;
vector<pair<int, int> > G[N];

int dijkstra() {
    using piii = pair<pair<int, int>, int>;
    priority_queue<piii, vector<piii>, greater<piii> > q;
    vector<vector<int>> d(n + 1, vector<int> (11, -1));
    vector<vector<bool>> vis(n + 1, vector<bool> (11, false));
    q.push(make_pair(make_pair(d[start][0] = 0, start), 0));
    while (!q.empty()) {
        int u = q.top().first.second;
        int k = q.top().second;
        q.pop();
        if (vis[u][k]) continue;
        vis[u][k] = true;
        for (int i = 0; i < (int)G[u].size(); i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if (d[v][k] == -1) {
                q.push(make_pair(make_pair(d[v][k] = max(d[u][k], w), v), k));
            } else if (d[v][k] > max(d[u][k], w)) {
                q.push(make_pair(make_pair(d[v][k] = max(d[u][k], w), v), k));
            }
            if (k < cnt) {
                if (d[v][k + 1] == -1) {
                    q.push(make_pair(make_pair(d[v][k + 1] = d[u][k], v), k + 1));
                } else if (d[v][k + 1] > d[u][k]) {
                    q.push(make_pair(make_pair(d[v][k + 1] = d[u][k], v), k + 1));
                }
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= cnt; i++) if (d[k][i] != -1) ans = min(ans, d[k][i]);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> start >> k >> cnt;
    assert(n >= 1 && n <= 100000);
    assert(m >= 1 && m <= 200000);
    assert(cnt >= 0 && cnt <= 10);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        assert(u >= 1 && u <= 100000);
        assert(v >= 1 && v <= 100000);
        assert(w >= 1 && w <= 1000000000);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    int ans = dijkstra();
    assert(ans >= 0 && ans <= 1000000000);
    if (ans == INF) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        cout << ans << '\n';
    }
    
    return 0;
}