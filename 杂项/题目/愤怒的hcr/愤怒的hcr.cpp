#include <bits/stdc++.h>
using namespace std;

int t;
int n;
int a[105] = {0};

int main()
{
    cin >> t;
    while(t--){
        cin >> n;
        int num = 0;
        int res = 0;
        for(int i = 1;i <= n;i++)cin >> a[i];
        for(int i = 1;i <= n;i++){
            if(a[i] == 1){
                for(int j = i + 1;j <= n;j++){
                    if(a[j] == 1){
                        num += j - (i + 1);
                        break;
                    }
                }
            }
        }
        cout << num << endl;
    }
    return 0;
}
