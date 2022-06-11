#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n,m;
int p[N];
char ch;
int a,b;
int find(int x)
{
    if(p[x] != x)p[x] = find(p[x]);
    return p[x];
}
int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)p[i] = i;
    while(m--){
        cin >> ch >> a >> b;
        if(ch == 'P'){
            p[find(b)] = find(a);
        }
        else{
            if(find(a) == find(b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
