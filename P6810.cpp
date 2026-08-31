/*---------------------
by DRheEheAM (awa)-----
love hanser forever!---
---------------------*/
#include<bits/stdc++.h>
using namespace std;
#define intc constexpr int
#define int long long
#define Cios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
intc N=2e6+10;
int n,m,p;
int pri[N],tot;
bool isp[N];
int tau[N],num[N],sn[N],sm[N];
void DirSuf (int *a,int n) {
    for (int j=1;j<=tot&&pri[j]<=n;j++) {
        for (int i=n/pri[j];i>=1;i--) a[i]=(a[i]+a[i*pri[j]])%p;
    }
}
signed main() {
    Cios;
    cin>>n>>m>>p;
    int lim=max(n,m);
    fill(isp+2,isp+lim+1,1);
    tau[1]=1;
    for (int i=2;i<=lim;i++) {
        if (isp[i]) {
            pri[++tot]=i;
            tau[i]=2,num[i]=1;
        }
        for (int j=1;j<=tot&&i*pri[j]<=lim;j++) {
            isp[i*pri[j]]=0;
            if (i%pri[j]==0) {
                num[i*pri[j]]=num[i]+1;
                tau[i*pri[j]]=tau[i]/(num[i]+1)*(num[i]+2);
                break;
            }
            else num[i*pri[j]]=1,tau[i*pri[j]]=tau[i]*2;
        }
    }
    for (int i=1;i<=n;i++) sn[i]=tau[i]%p;
    for (int i=1;i<=m;i++) sm[i]=tau[i]%p;
    DirSuf(sn,n);
    DirSuf(sm,m);
    int res=0,minn=min(n,m);
    for (int T=1;T<=minn;T++) (res+=sn[T]*sm[T])%=p;
    cout<<res<<"\n";
    return 0;
}