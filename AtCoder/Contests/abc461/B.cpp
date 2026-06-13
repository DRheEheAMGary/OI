/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int n;
int a[200],b[200];
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    bool fl=1;
    for (int i=1;i<=n;i++) fl=fl&&(b[a[i]]==i);
    cout<<(fl?"Yes\n":"No\n");
    return 0;
}