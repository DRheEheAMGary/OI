/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=105;
int n;
vector <int> b[N];
signed main() {
    Cios;
    cin>>n;
    for (int i=1;i<=n;i++) {
        int k;
        cin>>k;
        for (int j=1;j<=k;j++) {
            int a;
            cin>>a;
            b[a].push_back(i);
        }
    }
    for (int i=1;i<=n;i++) {
        cout<<b[i].size()<<" ";
        for (int v:b[i]) cout<<v<<" ";
        cout<<"\n";
    }
    return 0;
}