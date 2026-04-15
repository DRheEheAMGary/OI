/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n;
signed main() {
    Cios;
    int T;
    cin>>T;
    while (T--) {
        cin>>n;
        bool notsolved=1;
        for (int b=0,vb=1;b<63&&vb<=n;b++,vb<<=1) {
            int a=n-vb;
            string str="";
            while (a) str.push_back(a%10+'0'),a/=10;
            string rts=str;
            reverse(rts.begin(),rts.end());
            if (str==rts) {
                cout<<"Yes\n";
                notsolved=0;
                break;
            }
        }
        if (notsolved) cout<<"No\n";
    }
    return 0;
}