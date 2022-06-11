#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define debug(x) cout<<#x<<":"<<x<<endl;
#define dl(x) printf("%lld\n",x);
#define di(x) printf("%d\n",x);
#define _CRT_SECURE_NO_WARNINGS
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const int N = 2e6 + 10;
const ll mod= 1000000007;
const double eps = 1e-9;
const double PI = acos(-1);
template<typename T>inline void read(T &a){char c=getchar();T x=0,f=1;while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
while(isdigit(c)){x=(x<<1)+(x<<3)+c-'0';c=getchar();}a=f*x;}
int gcd(int a,int b){return (b>0)?gcd(b,a%b):a;}
int n,m;
int h[N],e[N],w[N],ne[N],idx;
int S,T,num;
int d[N];
bool st[N];


void bfs(){
    memset(st,0,sizeof st);
    queue<int> q;
    q.push(S);
    st[S] = 1;
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            if(st[j]) continue;
            st[j] = true;
            d[j] = d[t] + 1;
            q.push(j);
        }
    }
}

void add(int x,int y,int z){
    ne[idx] = h[x],e[idx] = y,w[idx] = z,h[x] = idx++;
}

bool spfa(int mid){
    memset(st,0,sizeof st);
    memset(d,0x3f,sizeof d);
    d[S] = 0;
    queue<int> q;
    q.push(S);
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];~i;i = ne[i]){
            int j = e[i];
            int p = w[i] > mid ? 1 : 0;
            if(d[j] > d[t] + p){
                d[j] = d[t] + p;
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return d[T] <= num;
}

int main(){
    memset(h,-1,sizeof h);
    read(n),read(m),read(S),read(T),read(num);
    while(m--){
        int x,y,z;
        // srcFile >> x >> y >> z;
        read(x),read(y),read(z);
        add(x,y,z),add(y,x,z);
    }
    bfs();
    if(!st[T]){
        puts("No");
        return 0;
    }
    puts("Yes");
    if(d[T] <= num){
        puts("0");
        return 0;
    }
    int l = 0,r = 1e9;
    while(l < r){
        int mid = l + r >> 1;
        if(spfa(mid)) r = mid;
        else l = mid + 1;
    }
    di(l);
    return 0;
}

/**
*　　┏┓　　　┏┓+ +
*　┏┛┻━━━┛┻┓ + +
*　┃　　　　　　　┃
*　┃　　　━　　　┃ ++ + + +
*  ████━████+
*  ◥██◤　◥██◤ +
*　┃　　　┻　　　┃
*　┃　　　　　　　┃ + +
*　┗━┓　　　┏━┛
*　　　┃　　　┃ + + + +Code is far away from 　
*　　　┃　　　┃ + bug with the animal protecting
*　　　┃　 　 ┗━━━┓ 神兽保佑,代码无bug　
*　　　┃ 　　　　　　 ┣┓
*　　  ┃ 　　　　　 　┏┛
*　    ┗┓┓┏━┳┓┏┛ + + + +
*　　　　┃┫┫　┃┫┫
*　　　　┗┻┛　┗┻┛+ + + +
*/