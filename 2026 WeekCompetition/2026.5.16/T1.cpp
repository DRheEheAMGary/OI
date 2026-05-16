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
int mp[55][55];
signed main() {
    Cios;
    cin>>n;
    cout<<"Yes\n";
    if (n==2) {
        cout<<"1 2\n3 4\n";
        return 0;
    }
    for (int i=1;i<n;i++) mp[1][i]=2*n;
    for (int i=2;i<=n;i++) mp[i][n]=2*n;
    mp[1][n]=2*n-1;
    int nw=2*n-2;
    mp[2][1]=1;
    mp[2][2]=2;
    mp[n][1]=3;
    mp[n][2]=4;
    for (int i=3;i<n;i++) {
        for (int j=2;j<=n;j++) mp[j][i]=nw;
        nw--;
    }
    for (int i=3;i<n;i++) mp[i][1]=mp[i][2]=nw--;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) cout<<mp[i][j]<<" \n"[j==n];
    }
    return 0;
}