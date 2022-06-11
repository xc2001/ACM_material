#include <bits/stdc++.h>
using namespace std;

int t,n,a;

int main()
{
    cin >> t;
    while(t--){
        stack<int>s;
        int num = 1;
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a;
            if(a != num){
                s.push(a);
            }
            else {
                while(!s.empty()){
                    if(s.top() == a + 1){
                        s.pop();
                        a++;
                    }
                    else{
                        break;
                    }
                }
                num = a + 1;
            }
        }
        if(s.empty())cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
