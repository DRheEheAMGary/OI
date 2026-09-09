/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e5+10,lN=17;
int n,h[N];
int lg[N];
int st[N][lN],stp[N][lN],stm[N][lN];
void InitLog () {
    lg[1]=1;
    for (int i=1;i<=n;i++) lg[i]=lg[i/2]+1;
}
void InitST () {
    for (int i=1;i<=n;i++) st[i][0]=h[i],stp[i][0]=h[i]+i,stm[i][0]=h[i]-i;
    for (int j=1;j<=lg[n];j++) {
        for (int i=1;i<=n;i++) {
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            stp[i][j]=max(stp[i][j-1],stp[i+(1<<(j-1))][j-1]);
            stm[i][j]=max(stm[i][j-1],stm[i+(1<<(j-1))][j-1]);
        }
    }
}
int query (int l,int r) {
    int llen=lg[r-l+1];
    return max(st[l][llen],st[r-(1<<llen)+1][llen]);
}
int queryp (int l,int r) {
    int llen=lg[r-l+1];
    return max(stp[l][llen],stp[r-(1<<llen)+1][llen]);
}
int querym (int l,int r) {
    int llen=lg[r-l+1];
    return max(stm[l][llen],stm[r-(1<<llen)+1][llen]);
}
signed main() {
    Cios;
    
    return 0;
}