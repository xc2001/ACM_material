#include <bits/stdc++.h>
using namespace std;

struct stu
{
    int no;
    char name[105];
    int score;
}a[105];

int cmp(struct stu a,struct stu b)
{
    return a.score > b.score;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d%s%d",&a[i].no,a[i].name,&a[i].score);
    }
    sort(a + 1,a + n + 1,cmp);
    for(int i = 1;i <= n;i++){
        printf("%d %s %d %d\n",a[i].no,a[i].name,a[i].score,i);
    }
    return 0;
}
