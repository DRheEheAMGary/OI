/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=1005,mod=998244353;
int n,dpa[2][N][N],dpb[2][N][N];
int qpow (int a,int b) {
    int res=1;
    while (b) {
        if (b&1) (res*=a)%=mod;
        (a*=a)%=mod;
        b>>=1;
    }
    return res;
} 
signed main() {
    Cios;
    cin>>n;
    dpa[0][2][2]=2;
    dpb[0][1][1]=1;
    int nw=0;
    for (int i=1;i<n;i++) {
        int nxt=nw^1;
        memset(dpa[nxt],0,sizeof dpa[nxt]);
        memset(dpb[nxt],0,sizeof dpb[nxt]);
        int mx=2*i;
        for (int s=1;s<=mx;s++) {
            for (int m=s;m<=mx;m++) {
                if (dpa[nw][s][m]) {
                    (dpa[nxt][s+2][max(m,s+2)]+=dpa[nw][s][m])%=mod;
                    (dpb[nxt][s+1][max(m,s+1)]+=dpa[nw][s][m])%=mod;
                }
                if (dpb[nw][s][m]) {
                    (dpa[nxt][s+2][max(m,s+2)]+=dpb[nw][s][m])%=mod;
                    (dpa[nxt][3][max(m,3ll)]+=dpb[nw][s][m])%=mod;
                }
            }
        }
        nw=nxt;
    }
    int tsum=0,mx=2*n;
    for (int s=1;s<=mx;s++) {
        for (int m=s;m<=mx;m++) {
            if (dpa[nw][s][m]) (tsum+=dpa[nw][s][m]*m)%=mod;
            if (dpb[nw][s][m]) (tsum+=dpb[nw][s][m]*m)%=mod;
        }
    }
    cout<<(tsum*qpow(3*(qpow(2,n-1)),mod-2))%mod<<"\n";
    return 0;
}