#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const ll maxn = 1e6 + 5;
const int N = 5000 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<vector<ll>> f(n + 1, vector<ll>(n + 1));
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int k = i - j;
            f[j + 1][k] = max(f[j + 1][k], f[j][k] + 1ll * a[i].first * abs(a[i].second - (j + 1)));
            f[j][k + 1] = max(f[j][k + 1], f[j][k] + 1ll * a[i].first * abs(n - k - a[i].second));
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) ans = max(ans, f[i][n - i]);
    cout << ans << '\n';

    return 0;
}