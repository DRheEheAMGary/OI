/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define intl long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define szof sizeof
#define uint unsigned int
intc N=2e7+10;
uint seed;
inline uint getnext () {
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
    return seed;
}
uint n,a[N],res;
bool vis[N];
signed main() {
    Cios;
    cin>>n>>seed;
    for (int i=1;i<=n;i++) a[i]=getnext();
    vis[1]=1;
    for (int i=2;i<=n;i++) {
        if (!vis[i]) {
            for (int j=i,k=1;j<=n;j+=i,k++) a[j]+=a[k],vis[j]=1;
        }
    }
    for (int i=1;i<=n;i++) res^=a[i];
    cout<<res<<"\n";
    return 0;
}