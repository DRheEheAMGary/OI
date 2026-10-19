/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=6010,inf=0x3f3f3f3f;
int n;
int a[N][N],c[N][N];
int f[N],cp[N];
signed main() {
    Cios;
    cin>>n;
    string s,t;
    cin>>s;
    cin>>t;
    s=" "+s;
    t=" "+t;
    for (int i=n;i>=1;i--) {
        for (int j=n;j>=1;j--) {
            if (s[i]==t[j]) a[i][j]=a[i+1][j+1]+1;
            else a[i][j]=0;
        }
    }
    for (int i=n;i>=1;i--) {
        for (int j=1;j<=n;j++) {
            if (s[i]==t[j]) c[i][j]=c[i+1][j-1]+1;
            else c[i][j]=0;
        }
    }
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for (int i=0;i<n;i++) {
        if (f[i]==inf) continue;
        if (s[i+1]==t[i+1]) f[i+1]=min(f[i+1],f[i]);
        cp[i]=-1;
        for (int k=i+1;k<=n;k++) cp[k]=max(cp[k-1],k+a[k+1][i+1]);
        for (int j=i+1;j<=n;j++) {
            int upk=min(j,i+c[i+1][j]);
            if (upk>=i+1&&cp[upk]>=j) f[j]=min(f[j],f[i]+1);
        }
    }
    if (f[n]==inf) cout<<-1<<"\n";
    else cout<<f[n]<<"\n";
    return 0;
}